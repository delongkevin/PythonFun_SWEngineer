/*******************************************************************************
 * config_parser.c
 *
 * Config parser from YAML file
 *
 * Copyright (c) 2020-2021 Cogent Embedded Inc.
 * ALL RIGHTS RESERVED.
 *
 * The source code contained or described herein and all documents related to the
 * source code("Software") or their modified versions are owned by
 * Cogent Embedded Inc. or its affiliates.
 *
 * No part of the Software may be used, copied, reproduced, modified, published,
 * uploaded, posted, transmitted, distributed, or disclosed in any way without
 * prior express written permission from Cogent Embedded Inc.
 *
 * Cogent Embedded Inc. grants a nonexclusive, non-transferable, royalty-free
 * license to use the Software to Licensee without the right to sublicense.
 * Licensee agrees not to distribute the Software to any third-party without
 * the prior written permission of Cogent Embedded Inc.
 *
 * Unless otherwise agreed by Cogent Embedded Inc. in writing, you may not remove
 * or alter this notice or any other notice embedded in Software in any way.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#define MODULE_TAG                      CONFIG

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "config.h"
#include <yaml.h>
#include <search.h>

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 1);
TRACE_TAG(DEBUG, 0);

/*******************************************************************************
 * Global variables definition
 ******************************************************************************/

#define RESOURCES_DIR       "./"

/*******************************************************************************
 * Auxiliary macros
 ******************************************************************************/

/* ...floating point parsing */
#define STRTOF(c, v)                            \
({                                              \
    char   *__p;                                \
    (v) = strtof((c), &__p);                    \
    *__p != '\0';                               \
})

/* ...integer value parsing */
#define STRTOU(c, v)                            \
({                                              \
    char   *__p;                                \
    (v) = strtoul((c), &__p, 0);                \
    *__p != '\0';                               \
})

#define STRTOU2(c, v, p)                        \
({                                              \
    (v) = (int)strtoul((c), &(p), 0);           \
    *(p) != '\0';                               \
})

/*******************************************************************************
 * Internal helpers
 ******************************************************************************/

/* ...open parser */
static inline int parser_open(yaml_parser_t *p, const char *fname)
{
    FILE   *f;

    TRACE(INFO, _b("open file: '%s'"), fname);

    /* ...open file descriptor */
    CHK_ERR(f = fopen(fname, "rt"), -errno);

    /* ...open parser */
    if (!yaml_parser_initialize(p))
    {
        TRACE(ERROR, _x("failed to initialize parser"));
        return -(errno = ENOMEM);
    }
    else
    {
        char buf[256];

        /* ...hack to support YAML 1.0 - ugly  */
        if (!fgets(buf, sizeof(buf), f))
        {
            return -1;
        }

        if (strncmp(buf, "%YAML:1.0", 9))
        {
            fseek(f, 0, SEEK_SET);
        }
        else
        {
            /* ...skip second line */
            //fgets(buf, sizeof(buf), f);
        }

        /* ...set input file */
        yaml_parser_set_input_file(p, f);
    }

    TRACE(INIT, _b("use configuration file '%s'"), fname);
    return 0;
}

/* ...parser error report */
static int parser_error(yaml_parser_t *p)
{
    /* ...process parser error */
    switch (p->error)
    {
    case YAML_MEMORY_ERROR:
        TRACE(ERROR, _b("insufficient memory"));
        return -(errno = ENOMEM);

    case YAML_READER_ERROR:
        if (p->problem_value != -1)
        {
            TRACE(ERROR, _b("reader error: %s: %X (offset=%zu)"), p->problem, p->problem_value, p->problem_offset);
        }
        else
        {
            TRACE(ERROR, _b("reader error: %s (offset=%zu)"), p->problem, p->problem_offset);
        }
        return -(errno = EINVAL);

    case YAML_SCANNER_ERROR:
        if (p->context)
        {
            TRACE(ERROR, _b("scanner error: %s (line=%zu:%zu): %s (line=%zu:%zu)"),
                  p->context, p->context_mark.line + 1, p->context_mark.column,
                  p->problem, p->problem_mark.line + 1, p->problem_mark.column);
        }
        else
        {
            TRACE(ERROR, _b("scanner error: %s (line=%zu:%zu)"),
                  p->problem, p->problem_mark.line + 1, p->problem_mark.column);
        }
        return -(errno = EINVAL);

    case YAML_PARSER_ERROR:
        if (p->context)
        {
            TRACE(ERROR, _b("parser error: %s (line=%zu:%zu): %s (line=%zu:%zu)"),
                  p->context, p->context_mark.line + 1, p->context_mark.column,
                  p->problem, p->problem_mark.line + 1, p->problem_mark.column);
        }
        else
        {
            TRACE(ERROR, _b("parser error: %s (line=%zu:%zu)"),
                  p->problem, p->problem_mark.line + 1, p->problem_mark.column);
        }
        return -(errno = EINVAL);

    case YAML_COMPOSER_ERROR:
        if (p->context)
        {
            TRACE(ERROR, _b("composer error: %s (line=%zu:%zu): %s (line=%zu:%zu)"),
                  p->context, p->context_mark.line + 1, p->context_mark.column,
                  p->problem, p->problem_mark.line + 1, p->problem_mark.column);
        }
        else
        {
            TRACE(ERROR, _b("composer error: %s (line=%zu:%zu)"),
                  p->problem, p->problem_mark.line + 1, p->problem_mark.column);
        }
        return -(errno = EINVAL);

    default:
        TRACE(ERROR, _b("internal parser error: %d"), p->error);
        return -(errno = EINVAL);
    }
}

/* ...syntax processing error */
static int syntax_error(yaml_document_t *doc, yaml_node_t *node, const char *fmt, ...)
{
    va_list     args;
    char        buffer[256];

    /* ...dump user-supplied output */
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    if (node)
    {
        TRACE(ERROR, _b("syntax error: node(type: %d) at %zu:%zu:%zu .. %zu:%zu:%zu: %s"),
              node->type,
              node->start_mark.index, node->start_mark.line, node->start_mark.column,
              node->end_mark.index, node->end_mark.line, node->end_mark.column,
              buffer);
    }
    else
    {
        TRACE(ERROR, _b("syntax error: %s"), buffer);
    }

    return -(errno = EINVAL);
}

/* ...auxiliary macros */
#define __MAP_LENGTH(v)     (int)((v)->data.mapping.pairs.top - (v)->data.mapping.pairs.start)
#define __SEQ_LENGTH(v)     (int)((v)->data.sequence.items.top - (v)->data.sequence.items.start)
#define __SEQ_INDEX(v, i)   (int)((i) - (v)->data.sequence.items.start)

/*******************************************************************************
 * Primitives parsing
 ******************************************************************************/

static inline char * parse_token(yaml_document_t *doc, yaml_node_t *v)
{
    CHK_ERR(v && v->type == YAML_SCALAR_NODE, (syntax_error(doc, v, "token expected"), NULL));

    return (char *)v->data.scalar.value;
}

static inline int parse_int(int32_t *i, yaml_document_t *doc, yaml_node_t *v)
{
    char    *t, *__p;

    /* ...make sure we have a scalar node */
    CHK_ERR(t = parse_token(doc, v), -errno);

    /* ...parse signed integer value */
    *i = (int32_t)strtol(t, &__p, 0);

    /* ...make sure parsing is successful */
    CHK_ERR(*__p == '\0', syntax_error(doc, v, "integer expected"));

    return 0;
}

static inline int parse_uint(uint32_t *u, yaml_document_t *doc, yaml_node_t *v)
{
    char    *t, *__p;

    /* ...make sure we have a scalar node */
    CHK_ERR(t = parse_token(doc, v), -errno);

    /* ...parse signed integer value */
    *u = (uint32_t)strtoul(t, &__p, 0);

    /* ...make sure parsing is successful */
    CHK_ERR(*__p == '\0', syntax_error(doc, v, "unsigned expected"));

    return 0;
}

static inline int parse_ui8(uint8_t *u, yaml_document_t *doc, yaml_node_t *v)
{
    char    *t, *__p;

    /* ...make sure we have a scalar node */
    CHK_ERR(t = parse_token(doc, v), -errno);

    /* ...parse signed integer value */
    *u = (uint8_t)strtoul(t, &__p, 0);

    /* ...make sure parsing is successful */
    CHK_ERR(*__p == '\0', syntax_error(doc, v, "unsigned expected"));

    return 0;
}

static inline int parse_float(float32_t *f, yaml_document_t *doc, yaml_node_t *v)
{
    char    *t, *__p;

    /* ...make sure we have a scalar node */
    CHK_ERR(t = parse_token(doc, v), -errno);

    /* ...parse float value */
    *f = strtof(t, &__p);

    /* ...make sure parsing is successful */
    CHK_ERR(*__p == '\0', syntax_error(doc, v, "float expected"));

    return 0;
}

/* ...compounds parsing */
static int parse_vector(float32_t *m, int size, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_item_t   *item;

    /* ...check node is a sequence */
    CHK_ERR(v && v->type == YAML_SEQUENCE_NODE, syntax_error(doc, v, "sequence expected"));

    /* ...check its size is valid */
    CHK_ERR(__SEQ_LENGTH(v) == size, syntax_error(doc, v, "invalid size: %d expected (%d got)", size, __SEQ_LENGTH(v)));

    /* ...parse all nodes */
    for (item = v->data.sequence.items.start; size > 0; size--, item++)
    {
        CHK_API(parse_float(m++, doc, yaml_document_get_node(doc, *item)));
    }

    return 0;
}

/* ...compounds parsing */
static int parse_vector3(float32_t (*m)[3], int size, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_item_t   *item;

    /* ...check node is a sequence */
    CHK_ERR(v && v->type == YAML_SEQUENCE_NODE, syntax_error(doc, v, "sequence expected"));

    /* ...check its size is valid */
    CHK_ERR(__SEQ_LENGTH(v) == size, syntax_error(doc, v, "invalid size: %d expected (%d got)", size, __SEQ_LENGTH(v)));

    /* ...parse all nodes */
    for (item = v->data.sequence.items.start; size > 0; size--, item++)
    {
        CHK_API(parse_vector(*m++, 3, doc, yaml_document_get_node(doc, *item)));
    }

    return 0;
}

/* ...compounds parsing */
static int parse_uivector(uint32_t *m, int size, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_item_t   *item;

    /* ...check node is a sequence */
    CHK_ERR(v && v->type == YAML_SEQUENCE_NODE, syntax_error(doc, v, "sequence expected"));

    /* ...check its size is valid */
    CHK_ERR(__SEQ_LENGTH(v) == size, syntax_error(doc, v, "invalid size: %d expected (%d got)", size, __SEQ_LENGTH(v)));

    /* ...parse all nodes */
    for (item = v->data.sequence.items.start; size > 0; size--, item++)
    {
        CHK_API(parse_uint(m++, doc, yaml_document_get_node(doc, *item)));
    }

    return 0;
}

/* ...compounds parsing */
static int parse_ivector(int32_t *m, int size, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_item_t   *item;

    /* ...check node is a sequence */
    CHK_ERR(v && v->type == YAML_SEQUENCE_NODE, syntax_error(doc, v, "sequence expected"));

    /* ...check its size is valid */
    CHK_ERR(__SEQ_LENGTH(v) == size, syntax_error(doc, v, "invalid size: %d expected (%d got)", size, __SEQ_LENGTH(v)));

    /* ...parse all nodes */
    for (item = v->data.sequence.items.start; size > 0; size--, item++)
    {
        CHK_API(parse_int(m++, doc, yaml_document_get_node(doc, *item)));
    }

    return 0;
}

/* ...compounds parsing */
static int parse_ivector3(int32_t (*m)[3], int size, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_item_t   *item;

    /* ...check node is a sequence */
    CHK_ERR(v && v->type == YAML_SEQUENCE_NODE, syntax_error(doc, v, "sequence expected"));

    /* ...check its size is valid */
    CHK_ERR(__SEQ_LENGTH(v) == size, syntax_error(doc, v, "invalid size: %d expected (%d got)", size, __SEQ_LENGTH(v)));

    /* ...parse all nodes */
    for (item = v->data.sequence.items.start; size > 0; size--, item++)
    {
        CHK_API(parse_ivector(*m++, 3, doc, yaml_document_get_node(doc, *item)));
    }

    return 0;
}

/* ...compounds parsing */
static int parse_ivector4(int32_t (*m)[4], int size, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_item_t   *item;

    /* ...check node is a sequence */
    CHK_ERR(v && v->type == YAML_SEQUENCE_NODE, syntax_error(doc, v, "sequence expected"));

    /* ...check its size is valid */
    CHK_ERR(__SEQ_LENGTH(v) == size, syntax_error(doc, v, "invalid size: %d expected (%d got)", size, __SEQ_LENGTH(v)));

    /* ...parse all nodes */
    for (item = v->data.sequence.items.start; size > 0; size--, item++)
    {
        CHK_API(parse_ivector(*m++, 4, doc, yaml_document_get_node(doc, *item)));
    }

    return 0;
}

/* ...compounds parsing */
static int parse_ui8vector(uint8_t *m, int size, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_item_t   *item;

    /* ...check node is a sequence */
    CHK_ERR(v && v->type == YAML_SEQUENCE_NODE, syntax_error(doc, v, "sequence expected"));

    /* ...check its size is valid */
    CHK_ERR(__SEQ_LENGTH(v) == size, syntax_error(doc, v, "invalid size: %d expected (%d got)", size, __SEQ_LENGTH(v)));

    /* ...parse all nodes */
    for (item = v->data.sequence.items.start; size > 0; size--, item++)
    {
        CHK_API(parse_ui8(m++, doc, yaml_document_get_node(doc, *item)));
    }

    return 0;
}

/* ...matrix parsing */
static int parse_matrix(float32_t *m, int rows, int cols, yaml_document_t *doc, yaml_node_t *v)
{
    yaml_node_pair_t   *pair;
    yaml_node_t        *data = NULL;
    int                 _r = -1, _c = -1;

    /* ...sanity check */
    CHK_ERR(v && v->type == YAML_MAPPING_NODE, syntax_error(doc, v, "map expected"));

    /* ...retrieve matrix parameters */
    for (pair = v->data.mapping.pairs.start; pair != v->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        /* ...check key correctness */
        CHK_ERR(t = parse_token(doc, key), -errno);

        /* ...process individual key */
        if (!strcmp(t, "rows"))
        {
            CHK_API(parse_int(&_r, doc, value));
        }
        else if (!strcmp(t, "cols"))
        {
            CHK_API(parse_int(&_c, doc, value));
        }
        else if (!strcmp(t, "data"))
        {
            data = value;
        }
        else
        {
            TRACE(DEBUG, _b("unrecognized matrix parameter: '%s'"), t);
        }
    }

    /* ...make sure we have read all parameters */
    CHK_ERR(_r == rows && _c == cols && data, syntax_error(doc, v, "incomplete definition"));

    /* ...parse matrix as a vector */
    return CHK_API(parse_vector(m, _r * _c, doc, data));
}

/*******************************************************************************
 * Parsing function
 ******************************************************************************/


/**
 * @brief   Individual camera configuration data parsing
 *
 * @param   cfg[in]         Camera configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_camera_cfg(cfg_camera_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...type check */
    CHK_ERR(root && root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...process camera parameters */
    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check; values must be valid */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        /* ...process high-level parameters */
        CHK_ERR(t = parse_token(doc, key), -errno);

        /* ...process individual parameters */
        if (!strcmp(t, "name"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->name = strdup(v), -errno);
        }
        else if (!strcmp(t, "id"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->id = strdup(v), -errno);
        }
        else if (!strcmp(t, "position"))
        {
            CHK_API(parse_vector(cfg->position, 3, doc, value));
        }
        else if (!strcmp(t, "rotation"))
        {
            CHK_API(parse_vector(cfg->rotation, 3, doc, value));
        }
        else if (!strcmp(t, "rotation-matrix"))
        {
            CHK_API(parse_vector(cfg->rotation_matrix, 3 * 3, doc, value));

            /* ...mark rotation matrix is set */
            cfg->rotation_matrix_valid = 1;
        }
        else if (!strcmp(t, "resolution"))
        {
            CHK_API(parse_vector(cfg->resolution, 2, doc, value));
        }
        else if (!strcmp(t, "distortion"))
        {
            CHK_API(parse_vector(cfg->distortion, 4, doc, value));
        }
        else if (!strcmp(t, "intrinsics"))
        {
            CHK_API(parse_vector(cfg->intrinsics, 3 * 3, doc, value));
        }
        else if (!strcmp(t, "magna-format"))
        {
            CHK_API(parse_int(&cfg->magna_format, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unknown option '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Cameras configuration section parsing
 *
 * @param   cfg[in]         Camera configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_cameras_cfg(cfg_camera_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...make sure sequence size doesn't exceed maximal number of cameras */
    CHK_ERR(__SEQ_LENGTH(root) <= SV_CAMERAS_NUMBER, syntax_error(doc, root, "too much cameras: %u > %u", __SEQ_LENGTH(root), SV_CAMERAS_NUMBER));

    /* ...process individual cameras */
    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        CHK_API(parse_camera_cfg(&cfg[__SEQ_INDEX(root, item)], doc, yaml_document_get_node(doc, *item)));
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Color-correction module configuration
 *
 * @param   cfg[in]         Color-correction configuration
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_cc_config(cfg_cc_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "roi-fl"))
        {
            CHK_API(parse_vector(cfg->roi[0], 4, doc, value));
        }
        else if (!strcmp(t, "roi-rl"))
        {
            CHK_API(parse_vector(cfg->roi[1], 4, doc, value));
        }
        else if (!strcmp(t, "roi-rr"))
        {
            CHK_API(parse_vector(cfg->roi[2], 4, doc, value));
        }
        else if (!strcmp(t, "roi-fr"))
        {
            CHK_API(parse_vector(cfg->roi[3], 4, doc, value));
        }
        else if (!strcmp(t, "filter-coef"))
        {
            CHK_API(parse_float(&cfg->filter_coef, doc, value));
        }
        else if (!strcmp(t, "clamp"))
        {
            CHK_API(parse_int(&cfg->clamp, doc, value));
        }
        else if (!strcmp(t, "color"))
        {
            CHK_API(parse_vector3(cfg->color, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Historcial-view module configuration
 *
 * @param   cfg[in]         Historical-view configuration
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_hv_config(cfg_bv_mesh_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "dim"))
        {
            CHK_API(parse_ivector3(cfg->dim, 4, doc, value));
        }
        else if (!strcmp(t, "front-blind-area"))
        {
            CHK_API(parse_float(&cfg->front_blind_area, doc, value));
        }
        else if (!strcmp(t, "rear-blind-area"))
        {
            CHK_API(parse_float(&cfg->rear_blind_area, doc, value));
        }
        else if (!strcmp(t, "left-blind-area"))
        {
            CHK_API(parse_float(&cfg->left_blind_area, doc, value));
        }
        else if (!strcmp(t, "right-blind-area"))
        {
            CHK_API(parse_float(&cfg->right_blind_area, doc, value));
        }
        else if (!strcmp(t, "slice-width-hor"))
        {
            CHK_API(parse_float(&cfg->slice_width_hor, doc, value));
        }
        else if (!strcmp(t, "slice-height-hor"))
        {
            CHK_API(parse_float(&cfg->slice_height_hor, doc, value));
        }
        else if (!strcmp(t, "slice-width-vert"))
        {
            CHK_API(parse_float(&cfg->slice_width_vert, doc, value));
        }
        else if (!strcmp(t, "slice-height-vert"))
        {
            CHK_API(parse_float(&cfg->slice_height_vert, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/*******************************************************************************
 * Vehicle model configuration parsing
 ******************************************************************************/

/**
 * @brief   Parse vehicle configuration
 *
 * @param   cfg[in]         Vehicle configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_vehicle_config(cfg_vehicle_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "length"))
        {
            CHK_API(parse_float(&cfg->length, doc, value));
        }
        else if (!strcmp(t, "width"))
        {
            CHK_API(parse_float(&cfg->width, doc, value));
        }
        else if (!strcmp(t, "width-mirrors"))
        {
            CHK_API(parse_float(&cfg->width_mirrors, doc, value));
        }
        else if (!strcmp(t, "wheelbase"))
        {
            CHK_API(parse_float(&cfg->wheel_base, doc, value));
        }
        else if (!strcmp(t, "front-overhang"))
        {
            CHK_API(parse_float(&cfg->front_overhang, doc, value));
        }
        else if (!strcmp(t, "rear-overhang"))
        {
            CHK_API(parse_float(&cfg->rear_overhang, doc, value));
        }
        else if (!strcmp(t, "front-blind-area"))
        {
            CHK_API(parse_float(&cfg->front_blind_area, doc, value));
        }
        else if (!strcmp(t, "rear-blind-area"))
        {
            CHK_API(parse_float(&cfg->rear_blind_area, doc, value));
        }
        else if (!strcmp(t, "left-blind-area"))
        {
            CHK_API(parse_float(&cfg->left_blind_area, doc, value));
        }
        else if (!strcmp(t, "right-blind-area"))
        {
            CHK_API(parse_float(&cfg->right_blind_area, doc, value));
        }
        else if (!strcmp(t, "front-track-width"))
        {
            CHK_API(parse_float(&cfg->front_track_width, doc, value));
        }
        else if (!strcmp(t, "rear-track-width"))
        {
            CHK_API(parse_float(&cfg->rear_track_width, doc, value));
        }
        else if (!strcmp(t, "front-wheel-width"))
        {
            CHK_API(parse_float(&cfg->front_wheel_width, doc, value));
        }
        else if (!strcmp(t, "front-wheel-diameter"))
        {
            CHK_API(parse_float(&cfg->front_wheel_diameter, doc, value));
        }
        else if (!strcmp(t, "rear-wheel-width"))
        {
            CHK_API(parse_float(&cfg->rear_wheel_width, doc, value));
        }
        else if (!strcmp(t, "rear-wheel-diameter"))
        {
            CHK_API(parse_float(&cfg->rear_wheel_diameter, doc, value));
        }
        else if (!strcmp(t, "wheel-pulse-width"))
        {
            CHK_API(parse_float(&cfg->wheel_pulse_width, doc, value));
        }
        else if (!strcmp(t, "steering-coef"))
        {
            CHK_API(parse_float(&cfg->steering_coef, doc, value));
        }
        else if (!strcmp(t, "steering-lhd"))
        {
            CHK_API(parse_uint(&cfg->steering_lhd, doc, value));
        }
        else if (!strcmp(t, "parking-sensor"))
        {
            CHK_API(parse_uint(&cfg->parking_sensor, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse sonar-view configuration
 *
 * @param   cfg[in]         Sonar-view configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_sonar_config(cfg_sonar_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "sonar-car-model-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_car_model_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fl-wheel-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fl_wheel_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fr-wheel-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fr_wheel_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rl-wheel-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rl_wheel_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rr-wheel-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rr_wheel_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-left-scan-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_left_scan_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-right-scan-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_right_scan_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fc-pas-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fc_pas_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fr-pas-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fr_pas_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fl-pas-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fl_pas_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rc-pas-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rc_pas_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rr-pas-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rr_pas_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rl-pas-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rl_pas_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fc-failure-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fc_failure_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fr-failure-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fr_failure_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-fl-failure-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_fl_failure_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rc-failure-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rc_failure_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rr-failure-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rr_failure_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-rl-failure-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_rl_failure_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-pas-off-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_pas_off_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sonar-pas-failure-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_pas_failure_dst, 4, doc, value));
        }
        else if (!strcmp(t, "door-open-dst"))
        {
            CHK_API(parse_ivector4(cfg->sonar_door_open_dst, 4, doc, value));
        }
        else if (!strcmp(t, "door-closed-dst"))
        {
            CHK_API(parse_ivector4(cfg->sonar_door_closed_dst, 4, doc, value));
        }
        else if (!strcmp(t, "trunk-open-dst"))
        {
            CHK_API(parse_ivector(cfg->sonar_trunk_open_dst, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse CTA configuration
 *
 * @param   cfg[in]         CTA configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_cta_config(cfg_cta_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "cta-left-outer-dst"))
        {
            CHK_API(parse_ivector(cfg->cta_left_outer_dst, 4, doc, value));
        }
        else if (!strcmp(t, "cta-left-inner-dst"))
        {
            CHK_API(parse_ivector(cfg->cta_left_inner_dst, 4, doc, value));
        }
        else if (!strcmp(t, "cta-right-outer-dst"))
        {
            CHK_API(parse_ivector(cfg->cta_right_outer_dst, 4, doc, value));
        }
        else if (!strcmp(t, "cta-right-inner-dst"))
        {
            CHK_API(parse_ivector(cfg->cta_right_inner_dst, 4, doc, value));
        }
        else if (!strcmp(t, "dst-left"))
        {
            CHK_API(parse_ivector(cfg->dst_left, 4, doc, value));
        }
        else if (!strcmp(t, "dst-right"))
        {
            CHK_API(parse_ivector(cfg->dst_right, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse aiming error icons configuration
 *
 * @param   cfg[in]         CTA configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_aiming_error_config(cfg_aiming_error_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "tv-dst"))
        {
            CHK_API(parse_ivector4(cfg->tv_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sv-dst"))
        {
            CHK_API(parse_ivector4(cfg->sv_dst, 4, doc, value));
        }
        else if (!strcmp(t, "nc-dst"))
        {
            CHK_API(parse_ivector4(cfg->nc_dst, 4, doc, value));
        }
        else if (!strcmp(t, "sc-dst"))
        {
            CHK_API(parse_ivector4(cfg->sc_dst, 1, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse guidelines configuration
 *
 * @param   cfg[in]         Guidelines configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_guide_dynamic_fr_config(cfg_guide_dynamic_fr_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "total-length"))
        {
            CHK_API(parse_float(&cfg->total_length, doc, value));
        }
        else if (!strcmp(t, "vehicle-width"))
        {
            CHK_API(parse_float(&cfg->vehicle_width, doc, value));
        }
        else if (!strcmp(t, "hidden-width"))
        {
            CHK_API(parse_float(&cfg->hidden_width, doc, value));
        }
        else if (!strcmp(t, "vehicle-trajectory-width"))
        {
            CHK_API(parse_float(&cfg->vehicle_trajectory_width, doc, value));
        }
        else if (!strcmp(t, "wheel-lateral-distance"))
        {
            CHK_API(parse_float(&cfg->wheel_lateral_distance, doc, value));
        }
        else if (!strcmp(t, "wheel-width"))
        {
            CHK_API(parse_float(&cfg->wheel_width, doc, value));
        }
        else if (!strcmp(t, "wheel-border-width"))
        {
            CHK_API(parse_float(&cfg->wheel_border_width, doc, value));
        }
        else if (!strcmp(t, "distance-marker-1"))
        {
            CHK_API(parse_float(&cfg->distance_marker_1, doc, value));
        }
        else if (!strcmp(t, "distance-marker-2"))
        {
            CHK_API(parse_float(&cfg->distance_marker_2, doc, value));
        }
        else if (!strcmp(t, "distance-marker-3"))
        {
            CHK_API(parse_float(&cfg->distance_marker_3, doc, value));
        }
        else if (!strcmp(t, "distance-marker-width"))
        {
            CHK_API(parse_float(&cfg->distance_marker_width, doc, value));
        }
        else if (!strcmp(t, "distance-marker-length"))
        {
            CHK_API(parse_float(&cfg->distance_marker_length, doc, value));
        }
        else if (!strcmp(t, "horizontal-line-width"))
        {
            CHK_API(parse_float(&cfg->horizontal_line_width, doc, value));
        }
        else if (!strcmp(t, "fade-section-start-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_start_length, doc, value));
        }
        else if (!strcmp(t, "fade-section-end-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_end_length, doc, value));
        }
        else if (!strcmp(t, "side-angle-threshold"))
        {
            CHK_API(parse_float(&cfg->side_angle_threshold, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}


/**
 * @brief   Parse guidelines configuration
 *
 * @param   cfg[in]         Guidelines configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_guide_dynamic_sv_config(cfg_guide_dynamic_sv_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "total-length"))
        {
            CHK_API(parse_float(&cfg->total_length, doc, value));
        }
        else if (!strcmp(t, "total-width"))
        {
            CHK_API(parse_float(&cfg->total_width, doc, value));
        }
        else if (!strcmp(t, "line-width"))
        {
            CHK_API(parse_float(&cfg->line_width, doc, value));
        }
        else if (!strcmp(t, "fade-section-start-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_start_length, doc, value));
        }
        else if (!strcmp(t, "fade-section-end-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_end_length, doc, value));
        }
        else if (!strcmp(t, "delta-width"))
        {
            CHK_API(parse_float(&cfg->delta_width, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse fixed guidelines configuration
 *
 * @param   cfg[in]         Guidelines configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_guide_fixed_fr_config(cfg_guide_fixed_fr_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "total-length"))
        {
            CHK_API(parse_float(&cfg->total_length, doc, value));
        }
        else if (!strcmp(t, "total-width"))
        {
            CHK_API(parse_float(&cfg->total_width, doc, value));
        }
        else if (!strcmp(t, "line-width"))
        {
            CHK_API(parse_float(&cfg->line_width, doc, value));
        }
        else if (!strcmp(t, "front-gap"))
        {
            CHK_API(parse_float(&cfg->front_gap, doc, value));
        }
        else if (!strcmp(t, "rear-gap"))
        {
            CHK_API(parse_float(&cfg->rear_gap, doc, value));
        }
        else if (!strcmp(t, "close-section-length"))
        {
            CHK_API(parse_float(&cfg->close_section_length, doc, value));
        }
        else if (!strcmp(t, "close-interlock-width"))
        {
            CHK_API(parse_float(&cfg->close_interlock_width, doc, value));
        }
        else if (!strcmp(t, "close-interlock-gap"))
        {
            CHK_API(parse_float(&cfg->close_interlock_gap, doc, value));
        }
        else if (!strcmp(t, "surface-close-width"))
        {
            CHK_API(parse_float(&cfg->surface_close_width, doc, value));
        }
        else if (!strcmp(t, "surface-close-gap"))
        {
            CHK_API(parse_float(&cfg->surface_close_gap, doc, value));
        }
        else if (!strcmp(t, "fade-section-start-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_start_length, doc, value));
        }
        else if (!strcmp(t, "fade-section-end-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_end_length, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse fixed guidelines configuration for side-view
 *
 * @param   cfg[in]         Guidelines configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_guide_fixed_sv_config(cfg_guide_fixed_sv_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "total-length"))
        {
            CHK_API(parse_float(&cfg->total_length, doc, value));
        }
        else if (!strcmp(t, "total-width"))
        {
            CHK_API(parse_float(&cfg->total_width, doc, value));
        }
        else if (!strcmp(t, "vert-line-width"))
        {
            CHK_API(parse_float(&cfg->vert_line_width, doc, value));
        }
        else if (!strcmp(t, "hor-line-width"))
        {
            CHK_API(parse_float(&cfg->hor_line_width, doc, value));
        }
        else if (!strcmp(t, "hor-line-gap"))
        {
            CHK_API(parse_float(&cfg->hor_line_gap, doc, value));
        }
        else if (!strcmp(t, "hor-line-start"))
        {
            CHK_API(parse_float(&cfg->hor_line_start, doc, value));
        }
        else if (!strcmp(t, "vert-line-start"))
        {
            CHK_API(parse_float(&cfg->vert_line_start, doc, value));
        }
        else if (!strcmp(t, "bar-width"))
        {
            CHK_API(parse_float(&cfg->bar_width, doc, value));
        }
        else if (!strcmp(t, "bar-fade-width"))
        {
            CHK_API(parse_float(&cfg->bar_fade_width, doc, value));
        }
        else if (!strcmp(t, "hor-fade-length"))
        {
            CHK_API(parse_float(&cfg->hor_fade_length, doc, value));
        }
        else if (!strcmp(t, "vert-fade-length"))
        {
            CHK_API(parse_float(&cfg->vert_fade_length, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse top-view guidelines configuration
 *
 * @param   cfg[in]         Guidelines configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_guide_tv_config(cfg_guide_tv_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "total-length"))
        {
            CHK_API(parse_float(&cfg->total_length, doc, value));
        }
        else if (!strcmp(t, "total-width"))
        {
            CHK_API(parse_float(&cfg->total_width, doc, value));
        }
        else if (!strcmp(t, "front-gap"))
        {
            CHK_API(parse_float(&cfg->front_gap, doc, value));
        }
        else if (!strcmp(t, "rear-gap"))
        {
            CHK_API(parse_float(&cfg->rear_gap, doc, value));
        }
        else if (!strcmp(t, "line-width"))
        {
            CHK_API(parse_float(&cfg->line_width, doc, value));
        }
        else if (!strcmp(t, "close-section-length"))
        {
            CHK_API(parse_float(&cfg->close_section_length, doc, value));
        }
        else if (!strcmp(t, "fade-section-start-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_start_length, doc, value));
        }
        else if (!strcmp(t, "fade-section-end-length"))
        {
            CHK_API(parse_float(&cfg->fade_section_end_length, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse guidelines configuration
 *
 * @param   cfg[in]         Guidelines configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_guide_config(cfg_guide_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "dynamic-front"))
        {
            CHK_API(parse_guide_dynamic_fr_config(&cfg->dynamic_front, doc, value));
        }
        else if (!strcmp(t, "dynamic-rear"))
        {
            CHK_API(parse_guide_dynamic_fr_config(&cfg->dynamic_rear, doc, value));
        }
        else if (!strcmp(t, "dynamic-front-stv"))
        {
            CHK_API(parse_guide_dynamic_fr_config(&cfg->dynamic_front_stv, doc, value));
        }
        else if (!strcmp(t, "dynamic-rear-stv"))
        {
            CHK_API(parse_guide_dynamic_fr_config(&cfg->dynamic_rear_stv, doc, value));
        }
        else if (!strcmp(t, "dynamic-sv"))
        {
            CHK_API(parse_guide_dynamic_sv_config(&cfg->dynamic_sv, doc, value));
        }
        else if (!strcmp(t, "dynamic-sv-stv"))
        {
            CHK_API(parse_guide_dynamic_sv_config(&cfg->dynamic_sv_stv, doc, value));
        }
        else if (!strcmp(t, "fixed-front"))
        {
            CHK_API(parse_guide_fixed_fr_config(&cfg->fixed_front, doc, value));
        }
        else if (!strcmp(t, "fixed-front-wide"))
        {
            CHK_API(parse_guide_fixed_fr_config(&cfg->fixed_front_wide, doc, value));
        }
        else if (!strcmp(t, "fixed-rear"))
        {
            CHK_API(parse_guide_fixed_fr_config(&cfg->fixed_rear, doc, value));
        }
        else if (!strcmp(t, "fixed-rear-wide"))
        {
            CHK_API(parse_guide_fixed_fr_config(&cfg->fixed_rear_wide, doc, value));
        }
        else if (!strcmp(t, "fixed-sv"))
        {
            CHK_API(parse_guide_fixed_sv_config(&cfg->fixed_sv, doc, value));
        }
        else if (!strcmp(t, "tv"))
        {
            CHK_API(parse_guide_tv_config(&cfg->tv, doc, value));
        }
        else if (!strcmp(t, "static-surface-color"))
        {
            CHK_API(parse_ui8vector(cfg->static_surface_color, 3, doc, value));
        }
        else if (!strcmp(t, "static-line-color"))
        {
            CHK_API(parse_ui8vector(cfg->static_line_color, 3, doc, value));
        }
        else if (!strcmp(t, "static-surface-close-color"))
        {
            CHK_API(parse_ui8vector(cfg->static_surface_close_color, 3, doc, value));
        }
        else if (!strcmp(t, "static-surface-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->static_surface_transmittance, doc, value));
        }
        else if (!strcmp(t, "static-surface-close-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->static_surface_close_transmittance, doc, value));
        }
        else if (!strcmp(t, "static-line-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->static_line_transmittance, doc, value));
        }
        else if (!strcmp(t, "dynamic-close-section-color"))
        {
            CHK_API(parse_ui8vector(cfg->dynamic_close_section_color, 3, doc, value));
        }
        else if (!strcmp(t, "dynamic-line-color"))
        {
            CHK_API(parse_ui8vector(cfg->dynamic_line_color, 3, doc, value));
        }
        else if (!strcmp(t, "line-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->line_transmittance, doc, value));
        }
        else if (!strcmp(t, "dynamic-close-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->dynamic_close_transmittance, doc, value));
        }
        else if (!strcmp(t, "dynamic-middle-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->dynamic_middle_transmittance, doc, value));
        }
        else if (!strcmp(t, "dynamic-far-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->dynamic_far_transmittance, doc, value));
        }
        else if (!strcmp(t, "tv-close-section-color"))
        {
            CHK_API(parse_ui8vector(cfg->tv_close_section_color, 3, doc, value));
        }
        else if (!strcmp(t, "tv-close-section-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->tv_close_section_transmittance, doc, value));
        }
        else if (!strcmp(t, "tv-line-color"))
        {
            CHK_API(parse_ui8vector(cfg->tv_line_color, 3, doc, value));
        }
        else if (!strcmp(t, "tv-line-transmittance"))
        {
            CHK_API(parse_ui8(&cfg->tv_line_transmittance, doc, value));
        }
        else if (!strcmp(t, "stv-pas-transparency"))
        {
            CHK_API(parse_ui8(&cfg->stv_pas_transparency, doc, value));
        }
        else if (!strcmp(t, "stv-pas-inactive-color"))
        {
            CHK_API(parse_ui8vector(cfg->stv_pas_inactive_color, 3, doc, value));
        }
        else if (!strcmp(t, "stv-pas-close-color"))
        {
            CHK_API(parse_ui8vector(cfg->stv_pas_close_color, 3, doc, value));
        }
        else if (!strcmp(t, "stv-pas-middle-color"))
        {
            CHK_API(parse_ui8vector(cfg->stv_pas_middle_color, 3, doc, value));
        }
        else if (!strcmp(t, "stv-pas-far-color"))
        {
            CHK_API(parse_ui8vector(cfg->stv_pas_far_color, 3, doc, value));
        }
        else if (!strcmp(t, "stv-pas-max-color"))
        {
            CHK_API(parse_ui8vector(cfg->stv_pas_max_color, 3, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-color"))
        {
            CHK_API(parse_ui8vector(cfg->stv_obstacle_color, 3, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-transparency"))
        {
            CHK_API(parse_ui8(&cfg->stv_obstacle_transparency, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-line-color"))
        {
            CHK_API(parse_ui8vector(cfg->stv_obstacle_line_color, 3, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-line-transparency"))
        {
            CHK_API(parse_ui8(&cfg->stv_obstacle_line_transparency, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-line-width"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_line_width, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-min-distance"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_min_distance, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-close-distance"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_close_distance, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-middle-distance"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_middle_distance, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-far-distance"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_far_distance, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-max-distance"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_max_distance, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-width"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_width, doc, value));
        }
        else if (!strcmp(t, "stv-obstacle-height"))
        {
            CHK_API(parse_float(&cfg->stv_obstacle_height, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse single-camera-view configuration
 *
 * @param   cfg[in]         SCV configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_scv_mesh_config(cfg_scv_mesh_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "camera-id"))
        {
            CHK_ERR(v = parse_token(doc, value), -1);

            if (!strcmp(v, "front"))    cfg->id = SV_CAMERA_FRONT;
            else if (!strcmp(v, "left"))    cfg->id = SV_CAMERA_LEFT;
            else if (!strcmp(v, "rear"))    cfg->id = SV_CAMERA_REAR;
            else if (!strcmp(v, "right"))    cfg->id = SV_CAMERA_RIGHT;
            else
            {
                TRACE(ERROR, _x("invalid camera id: '%s'"), v);
                return -(errno = EINVAL);
            }
        }
        else if (!strcmp(t, "position"))
        {
            CHK_API(parse_vector(cfg->position, 3, doc, value));
        }
        else if (!strcmp(t, "rotation"))
        {
            CHK_API(parse_vector(cfg->rotation, 3, doc, value));
        }
        else if (!strcmp(t, "fov"))
        {
            CHK_API(parse_vector(cfg->fov, 4, doc, value));
        }
        else if (!strcmp(t, "distortion"))
        {
            if (value->type == YAML_SEQUENCE_NODE)
            {
                CHK_API(parse_vector(cfg->distortion, 2, doc, value));
            }
            else
            {
                CHK_API(parse_float(&cfg->distortion[0], doc, value));
            }
        }
        else if (!strcmp(t, "compression"))
        {
            if (value->type == YAML_SEQUENCE_NODE)
            {
                CHK_API(parse_vector(cfg->compression, 2, doc, value));
            }
            else
            {
                CHK_API(parse_float(&cfg->compression[0], doc, value));
                cfg->compression[1] = 1.0f;
            }
        }
        else if (!strcmp(t, "mask"))
        {
            CHK_API(parse_vector(cfg->mask, 4, doc, value));
        }
        else if (!strcmp(t, "window"))
        {
            CHK_API(parse_ivector(cfg->base.dst, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse multiples-camera-view configuration
 *
 * @param   cfg[in]         MCV configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_mcv_mesh_config(cfg_mcv_mesh_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...create number of configurations */
    cfg->number = __SEQ_LENGTH(root);

    CHK_ERR(cfg->scv = calloc(cfg->number, sizeof(*cfg->scv)), -1);

    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        CHK_API(parse_scv_mesh_config(&cfg->scv[__SEQ_INDEX(root, item)], doc, yaml_document_get_node(doc, *item)));
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parse top-view configuration
 *
 * @param   cfg[in]         TV configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_tv_mesh_config(cfg_tv_mesh_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "shadow"))
        {
            CHK_API(parse_vector(cfg->shadow, 4, doc, value));
        }
        else if (!strcmp(t, "area"))
        {
            CHK_API(parse_vector(cfg->area, 4, doc, value));
        }
        else if (!strcmp(t, "separator-width"))
        {
            CHK_API(parse_float(&cfg->separator_width, doc, value));
        }
        else if (!strcmp(t, "separator-exp"))
        {
            CHK_API(parse_float(&cfg->separator_exp, doc, value));
        }
        else if (!strcmp(t, "angles"))
        {
            CHK_API(parse_vector(cfg->angles, 8, doc, value));
        }
        else if (!strcmp(t, "offsets"))
        {
            CHK_API(parse_vector(cfg->offsets, 8, doc, value));
        }
        else if (!strcmp(t, "window"))
        {
            CHK_API(parse_ivector(cfg->base.dst, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse see-through-view configuration
 *
 * @param   cfg[in]         STV configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_stv_mesh_config(cfg_stv_mesh_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "position"))
        {
            CHK_API(parse_vector(cfg->position, 3, doc, value));
        }
        else if (!strcmp(t, "look-at"))
        {
            CHK_API(parse_vector(cfg->look_at, 3, doc, value));
        }
        else if (!strcmp(t, "fov"))
        {
            CHK_API(parse_vector(cfg->fov, 2, doc, value));
        }
        else if (!strcmp(t, "shadow"))
        {
            CHK_API(parse_vector(cfg->shadow, 4, doc, value));
        }
        else if (!strcmp(t, "angles"))
        {
            CHK_API(parse_vector(cfg->angles, 8, doc, value));
        }
        else if (!strcmp(t, "offsets"))
        {
            CHK_API(parse_vector(cfg->offsets, 8, doc, value));
        }
        else if (!strcmp(t, "parabolic"))
        {
            CHK_API(parse_vector(cfg->parabolic, 4, doc, value));
        }
        else if (!strcmp(t, "separator-width"))
        {
            CHK_API(parse_float(&cfg->separator_width, doc, value));
        }
        else if (!strcmp(t, "separator-exp"))
        {
            CHK_API(parse_float(&cfg->separator_exp, doc, value));
        }
        else if (!strcmp(t, "window"))
        {
            CHK_API(parse_ivector(cfg->base.dst, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse raw-mesh configuration
 *
 * @param   cfg[in]         Raw mesh configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_raw_mesh_config(cfg_raw_mesh_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "camera-id"))
        {
            CHK_ERR(v = parse_token(doc, value), -1);

            if (!strcmp(v, "front"))    cfg->id = SV_CAMERA_FRONT;
            else if (!strcmp(v, "left"))    cfg->id = SV_CAMERA_LEFT;
            else if (!strcmp(v, "rear"))    cfg->id = SV_CAMERA_REAR;
            else if (!strcmp(v, "right"))    cfg->id = SV_CAMERA_RIGHT;
            else
            {
                TRACE(ERROR, _x("invalid camera id: '%s'"), v);
                return -(errno = EINVAL);
            }
        }
        else if (!strcmp(t, "crop"))
        {
            CHK_API(parse_ivector(cfg->crop, 4, doc, value));
        }
        else if (!strcmp(t, "window"))
        {
            CHK_API(parse_ivector(cfg->base.dst, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse generic mesh configuration
 *
 * @param   mesh[out]       Mesh configuration data pointer
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_mesh_config(cfg_mesh_t **mesh, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...search for mesh type */
    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "type"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            if (!strcmp(v, "scv"))
            {
                CHK_ERR(*mesh = calloc(1, sizeof((*mesh)->scv)), -1);
                (*mesh)->base.type = MESH_SCV;
                CHK_API(parse_scv_mesh_config(&(*mesh)->scv, doc, root));
            }
            else if (!strcmp(v, "stv"))
            {
                CHK_ERR(*mesh = calloc(1, sizeof((*mesh)->stv)), -1);
                (*mesh)->base.type = MESH_STV;
                CHK_API(parse_stv_mesh_config(&(*mesh)->stv, doc, root));
            }
            else if (!strcmp(v, "tv"))
            {
                CHK_ERR(*mesh = calloc(1, sizeof((*mesh)->tv)), -1);
                (*mesh)->base.type = MESH_TV;
                CHK_API(parse_tv_mesh_config(&(*mesh)->tv, doc, root));
            }
            else if (!strcmp(v, "raw"))
            {
                CHK_ERR(*mesh = calloc(1, sizeof((*mesh)->raw)), -1);
                (*mesh)->base.type = MESH_RAW;
                CHK_API(parse_raw_mesh_config(&(*mesh)->raw, doc, root));
            }
            else
            {
                TRACE(ERROR, _b("unrecognized mesh type: '%s'"), v);
            }

            TRACE(DEBUG, _b("parsed mesh type '%s'"), v);

            break;
        }
    }

    return 0;
}

/**
 * @brief   Parse IBL configuration
 *
 * @param   cfg[in]         IBL configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ibl_config(cfg_ibl_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);
        CHK_ERR(v = parse_token(doc, value), -errno);

        if (!strcmp(t, "sh"))
        {
            CHK_ERR(cfg->sh = strdup(v), -errno);
        }
        else if (!strcmp(t, "specular"))
        {
            CHK_ERR(cfg->specular = strdup(v), -errno);
        }
        else if (!strcmp(t, "diffuse"))
        {
            CHK_ERR(cfg->diffuse = strdup(v), -errno);
        }
        else if (!strcmp(t, "lut"))
        {
            CHK_ERR(cfg->lut = strdup(v), -errno);
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse car model configuration
 *
 * @param   cfg[in]         Car-model configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_car_model_config(cfg_model_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "file"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_model = strdup(v), -errno);
        }
        else if (!strcmp(t, "ibl"))
        {
            CHK_ERR(cfg->ibl = calloc(1, sizeof(*cfg->ibl)), -errno);
            CHK_API(parse_ibl_config(cfg->ibl, doc, value));
        }
        else if (!strcmp(t, "body"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_body_groups = strdup(v), -errno);
        }
        else if (!strcmp(t, "interior"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_interior_groups = strdup(v), -errno);
        }
        else if (!strcmp(t, "shadow"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_shadow_groups = strdup(v), -errno);
        }
        else if (!strcmp(t, "wheel-fl"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_wheels_groups[0] = strdup(v), -errno);
        }
        else if (!strcmp(t, "wheel-fr"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_wheels_groups[1] = strdup(v), -errno);
        }
        else if (!strcmp(t, "wheel-rl"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_wheels_groups[2] = strdup(v), -errno);
        }
        else if (!strcmp(t, "wheel-rr"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->car_wheels_groups[3] = strdup(v), -errno);
        }
        else if (!strcmp(t, "anim-door-fl"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->anim_door[0] = strdup(v), -errno);
        }
        else if (!strcmp(t, "anim-door-fr"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->anim_door[1] = strdup(v), -errno);
        }
        else if (!strcmp(t, "anim-door-rl"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->anim_door[2] = strdup(v), -errno);
        }
        else if (!strcmp(t, "anim-door-rr"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->anim_door[3] = strdup(v), -errno);
        }
        else if (!strcmp(t, "anim-door-b"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->anim_door[4] = strdup(v), -errno);
        }
        else if (!strcmp(t, "anim-mirror-l"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->anim_mirror[0] = strdup(v), -errno);
        }
        else if (!strcmp(t, "anim-mirror-r"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->anim_mirror[1] = strdup(v), -errno);
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse car model rendering configuration
 *
 * @param   cfg[in]         Car-model rendering configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_car_render_config(cfg_car_render_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "window-front-opaqueness"))
        {
            CHK_API(parse_float(&cfg->window_front_opaqueness, doc, value));
        }
        if (!strcmp(t, "window-rear-opaqueness"))
        {
            CHK_API(parse_float(&cfg->window_rear_opaqueness, doc, value));
        }
        else if (!strcmp(t, "body-opaqueness"))
        {
            CHK_API(parse_float(&cfg->body_opaqueness, doc, value));
        }
        else if (!strcmp(t, "head-opaqueness"))
        {
            CHK_API(parse_float(&cfg->head_opaqueness, doc, value));
        }
        else if (!strcmp(t, "mask-opaqueness"))
        {
            CHK_API(parse_float(&cfg->mask_opaqueness, doc, value));
        }
        else if (!strcmp(t, "wheel-height-min"))
        {
            CHK_API(parse_float(&cfg->wheel_height_min, doc, value));
        }
        else if (!strcmp(t, "wheel-height-max"))
        {
            CHK_API(parse_float(&cfg->wheel_height_max, doc, value));
        }
        else if (!strcmp(t, "wheel-gradient-exp"))
        {
            CHK_API(parse_float(&cfg->wheel_gradient_exp, doc, value));
        }
        else if (!strcmp(t, "rear-gradient-x"))
        {
            CHK_API(parse_float(&cfg->rear_gradient_x, doc, value));
        }
        else if (!strcmp(t, "rear-gradient-scale"))
        {
            CHK_API(parse_float(&cfg->rear_gradient_scale, doc, value));
        }
        else if (!strcmp(t, "front-gradient-x"))
        {
            CHK_API(parse_float(&cfg->front_gradient_x, doc, value));
        }
        else if (!strcmp(t, "front-gradient-scale"))
        {
            CHK_API(parse_float(&cfg->front_gradient_scale, doc, value));
        }
        else if (!strcmp(t, "height-gradient-z"))
        {
            CHK_API(parse_float(&cfg->height_gradient_z, doc, value));
        }
        else if (!strcmp(t, "height-gradient-scale"))
        {
            CHK_API(parse_float(&cfg->height_gradient_scale, doc, value));
        }
        else if (!strcmp(t, "front-mask-gradient-start"))
        {
            CHK_API(parse_float(&cfg->front_mask_gradient_start, doc, value));
        }
        else if (!strcmp(t, "front-mask-gradient-stop"))
        {
            CHK_API(parse_float(&cfg->front_mask_gradient_stop, doc, value));
        }
        else if (!strcmp(t, "front-mask-gradient-exp"))
        {
            CHK_API(parse_float(&cfg->front_mask_gradient_exp, doc, value));
        }
        else if (!strcmp(t, "rear-mask-gradient-start"))
        {
            CHK_API(parse_float(&cfg->rear_mask_gradient_start, doc, value));
        }
        else if (!strcmp(t, "rear-mask-gradient-stop"))
        {
            CHK_API(parse_float(&cfg->rear_mask_gradient_stop, doc, value));
        }
        else if (!strcmp(t, "rear-mask-gradient-exp"))
        {
            CHK_API(parse_float(&cfg->rear_mask_gradient_exp, doc, value));
        }
        else if (!strcmp(t, "front-wheel-width-scale"))
        {
            CHK_API(parse_float(&cfg->front_wheel_width_scale, doc, value));
        }
        else if (!strcmp(t, "rear-wheel-width-scale"))
        {
            CHK_API(parse_float(&cfg->rear_wheel_width_scale, doc, value));
        }
        else if (!strcmp(t, "mask-ambient-color"))
        {
            CHK_API(parse_ui8vector(cfg->mask_ambient_color, 3, doc, value));
        }
        else if (!strcmp(t, "wheel-ambient-color"))
        {
            CHK_API(parse_ui8vector(cfg->wheel_ambient_color, 3, doc, value));
        }
        else if (!strcmp(t, "lights-tail-base-color"))
        {
            CHK_API(parse_ui8vector(cfg->lights_tail_base_color, 4, doc, value));
        }
        else if (!strcmp(t, "lights-tail-lens-color"))
        {
            CHK_API(parse_ui8vector(cfg->lights_tail_lens_color, 4, doc, value));
        }
        else if (!strcmp(t, "lights-tail-shine-color"))
        {
            CHK_API(parse_ui8vector(cfg->lights_tail_shine_color, 4, doc, value));
        }
        else if (!strcmp(t, "lights-tail-corner-color"))
        {
            CHK_API(parse_ui8vector(cfg->lights_tail_corner_color, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/*******************************************************************************
 * Icons parsing
 ******************************************************************************/

/**
 * @brief   Icon name lookup
 *
 * @param   v[in]           Icon name
 *
 * @return                  Icon identifier
 */
static uint32_t cfg_icon_name_lookup(char *v)
{
    uint32_t    id;

    /* ...associate resource with icon item - tbd - somehow */
    if (!strcmp(v, "border"))
    {
        id = ICON_BORDER;
    }
    else if (!strcmp(v, "cta-left"))
    {
        id = ICON_CTA_LEFT;
    }
    else if (!strcmp(v, "cta-right"))
    {
        id = ICON_CTA_RIGHT;
    }
    else if (!strcmp(v, "car-model"))
    {
        id = ICON_CAR_MODEL;
    }
    else if (!strcmp(v, "car-fl-open"))
    {
        id = ICON_DOOR_FL_OPEN;
    }
    else if (!strcmp(v, "car-fr-open"))
    {
        id = ICON_DOOR_FR_OPEN;
    }
    else if (!strcmp(v, "car-rl-open"))
    {
        id = ICON_DOOR_RL_OPEN;
    }
    else if (!strcmp(v, "car-rr-open"))
    {
        id = ICON_DOOR_RR_OPEN;
    }
    else if (!strcmp(v, "car-fl-closed"))
    {
        id = ICON_DOOR_FL_CLOSED;
    }
    else if (!strcmp(v, "car-fr-closed"))
    {
        id = ICON_DOOR_FR_CLOSED;
    }
    else if (!strcmp(v, "car-rl-closed"))
    {
        id = ICON_DOOR_RL_CLOSED;
    }
    else if (!strcmp(v, "car-rr-closed"))
    {
        id = ICON_DOOR_RR_CLOSED;
    }
    else if (!strcmp(v, "car-tg-open"))
    {
        id = ICON_TRUNK_OPEN;
    }

    else if (!strcmp(v, "pas-fl-caution"))
    {
        id = ICON_PAS_FL_CAUTION;
    }
    else if (!strcmp(v, "pas-fc-caution"))
    {
        id = ICON_PAS_FC_CAUTION;
    }
    else if (!strcmp(v, "pas-fr-caution"))
    {
        id = ICON_PAS_FR_CAUTION;
    }
    else if (!strcmp(v, "pas-rl-caution"))
    {
        id = ICON_PAS_RL_CAUTION;
    }
    else if (!strcmp(v, "pas-rc-caution"))
    {
        id = ICON_PAS_RC_CAUTION;
    }
    else if (!strcmp(v, "pas-rr-caution"))
    {
        id = ICON_PAS_RR_CAUTION;
    }

    else if (!strcmp(v, "pas-fl-crit"))
    {
        id = ICON_PAS_FL_CRITICAL;
    }
    else if (!strcmp(v, "pas-fc-crit"))
    {
        id = ICON_PAS_FC_CRITICAL;
    }
    else if (!strcmp(v, "pas-fr-crit"))
    {
        id = ICON_PAS_FR_CRITICAL;
    }
    else if (!strcmp(v, "pas-rl-crit"))
    {
        id = ICON_PAS_RL_CRITICAL;
    }
    else if (!strcmp(v, "pas-rc-crit"))
    {
        id = ICON_PAS_RC_CRITICAL;
    }
    else if (!strcmp(v, "pas-rr-crit"))
    {
        id = ICON_PAS_RR_CRITICAL;
    }

    else if (!strcmp(v, "car-model-sv"))
    {
        id = ICON_CAR_MODEL_SV;
    }
    else if (!strcmp(v, "tyre-front"))
    {
        id = ICON_TYRE_FRONT;
    }
    else if (!strcmp(v, "tyre-rear"))
    {
        id = ICON_TYRE_REAR;
    }
    else if (!strcmp(v, "tyre"))
    {
        id = ICON_CAR_TYRE;
    }
    else if (!strcmp(v, "scan-mask"))
    {
        id = ICON_SCAN_MASK;
    }
    else if (!strcmp(v, "pas-tv-fl-inactive"))
    {
        id = ICON_PAS_TV_FL_INACTIVE;
    }
    else if (!strcmp(v, "pas-tv-fl-close"))
    {
        id = ICON_PAS_TV_FL_CLOSE;
    }
    else if (!strcmp(v, "pas-tv-fl-middle"))
    {
        id = ICON_PAS_TV_FL_MIDDLE;
    }
    else if (!strcmp(v, "pas-tv-fl-far"))
    {
        id = ICON_PAS_TV_FL_FAR;
    }
    else if (!strcmp(v, "pas-tv-fl-max"))
    {
        id = ICON_PAS_TV_FL_MAX;
    }
    else if (!strcmp(v, "pas-tv-fc-inactive"))
    {
        id = ICON_PAS_TV_FC_INACTIVE;
    }
    else if (!strcmp(v, "pas-tv-fc-close"))
    {
        id = ICON_PAS_TV_FC_CLOSE;
    }
    else if (!strcmp(v, "pas-tv-fc-middle"))
    {
        id = ICON_PAS_TV_FC_MIDDLE;
    }
    else if (!strcmp(v, "pas-tv-fc-far"))
    {
        id = ICON_PAS_TV_FC_FAR;
    }
    else if (!strcmp(v, "pas-tv-fc-max"))
    {
        id = ICON_PAS_TV_FC_MAX;
    }
    else if (!strcmp(v, "pas-tv-fr-inactive"))
    {
        id = ICON_PAS_TV_FR_INACTIVE;
    }
    else if (!strcmp(v, "pas-tv-fr-close"))
    {
        id = ICON_PAS_TV_FR_CLOSE;
    }
    else if (!strcmp(v, "pas-tv-fr-middle"))
    {
        id = ICON_PAS_TV_FR_MIDDLE;
    }
    else if (!strcmp(v, "pas-tv-fr-far"))
    {
        id = ICON_PAS_TV_FR_FAR;
    }
    else if (!strcmp(v, "pas-tv-fr-max"))
    {
        id = ICON_PAS_TV_FR_MAX;
    }
    else if (!strcmp(v, "pas-tv-rl-inactive"))
    {
        id = ICON_PAS_TV_RL_INACTIVE;
    }
    else if (!strcmp(v, "pas-tv-rl-close"))
    {
        id = ICON_PAS_TV_RL_CLOSE;
    }
    else if (!strcmp(v, "pas-tv-rl-middle"))
    {
        id = ICON_PAS_TV_RL_MIDDLE;
    }
    else if (!strcmp(v, "pas-tv-rl-far"))
    {
        id = ICON_PAS_TV_RL_FAR;
    }
    else if (!strcmp(v, "pas-tv-rl-max"))
    {
        id = ICON_PAS_TV_RL_MAX;
    }
    else if (!strcmp(v, "pas-tv-rc-inactive"))
    {
        id = ICON_PAS_TV_RC_INACTIVE;
    }
    else if (!strcmp(v, "pas-tv-rc-close"))
    {
        id = ICON_PAS_TV_RC_CLOSE;
    }
    else if (!strcmp(v, "pas-tv-rc-middle"))
    {
        id = ICON_PAS_TV_RC_MIDDLE;
    }
    else if (!strcmp(v, "pas-tv-rc-far"))
    {
        id = ICON_PAS_TV_RC_FAR;
    }
    else if (!strcmp(v, "pas-tv-rc-max"))
    {
        id = ICON_PAS_TV_RC_MAX;
    }
    else if (!strcmp(v, "pas-tv-rr-inactive"))
    {
        id = ICON_PAS_TV_RR_INACTIVE;
    }
    else if (!strcmp(v, "pas-tv-rr-close"))
    {
        id = ICON_PAS_TV_RR_CLOSE;
    }
    else if (!strcmp(v, "pas-tv-rr-middle"))
    {
        id = ICON_PAS_TV_RR_MIDDLE;
    }
    else if (!strcmp(v, "pas-tv-rr-far"))
    {
        id = ICON_PAS_TV_RR_FAR;
    }
    else if (!strcmp(v, "pas-tv-rr-max"))
    {
        id = ICON_PAS_TV_RR_MAX;
    }
    else if (!strcmp(v, "pas-sv-fl-inactive"))
    {
        id = ICON_PAS_SV_FL_INACTIVE;
    }
    else if (!strcmp(v, "pas-sv-fl-close"))
    {
        id = ICON_PAS_SV_FL_CLOSE;
    }
    else if (!strcmp(v, "pas-sv-fl-middle"))
    {
        id = ICON_PAS_SV_FL_MIDDLE;
    }
    else if (!strcmp(v, "pas-sv-fl-far"))
    {
        id = ICON_PAS_SV_FL_FAR;
    }
    else if (!strcmp(v, "pas-sv-fl-max"))
    {
        id = ICON_PAS_SV_FL_MAX;
    }
    else if (!strcmp(v, "pas-sv-fc-inactive"))
    {
        id = ICON_PAS_SV_FC_INACTIVE;
    }
    else if (!strcmp(v, "pas-sv-fc-close"))
    {
        id = ICON_PAS_SV_FC_CLOSE;
    }
    else if (!strcmp(v, "pas-sv-fc-middle"))
    {
        id = ICON_PAS_SV_FC_MIDDLE;
    }
    else if (!strcmp(v, "pas-sv-fc-far"))
    {
        id = ICON_PAS_SV_FC_FAR;
    }
    else if (!strcmp(v, "pas-sv-fc-max"))
    {
        id = ICON_PAS_SV_FC_MAX;
    }
    else if (!strcmp(v, "pas-sv-fr-inactive"))
    {
        id = ICON_PAS_SV_FR_INACTIVE;
    }
    else if (!strcmp(v, "pas-sv-fr-close"))
    {
        id = ICON_PAS_SV_FR_CLOSE;
    }
    else if (!strcmp(v, "pas-sv-fr-middle"))
    {
        id = ICON_PAS_SV_FR_MIDDLE;
    }
    else if (!strcmp(v, "pas-sv-fr-far"))
    {
        id = ICON_PAS_SV_FR_FAR;
    }
    else if (!strcmp(v, "pas-sv-fr-max"))
    {
        id = ICON_PAS_SV_FR_MAX;
    }
    else if (!strcmp(v, "pas-sv-rl-inactive"))
    {
        id = ICON_PAS_SV_RL_INACTIVE;
    }
    else if (!strcmp(v, "pas-sv-rl-close"))
    {
        id = ICON_PAS_SV_RL_CLOSE;
    }
    else if (!strcmp(v, "pas-sv-rl-middle"))
    {
        id = ICON_PAS_SV_RL_MIDDLE;
    }
    else if (!strcmp(v, "pas-sv-rl-far"))
    {
        id = ICON_PAS_SV_RL_FAR;
    }
    else if (!strcmp(v, "pas-sv-rl-max"))
    {
        id = ICON_PAS_SV_RL_MAX;
    }
    else if (!strcmp(v, "pas-sv-rc-inactive"))
    {
        id = ICON_PAS_SV_RC_INACTIVE;
    }
    else if (!strcmp(v, "pas-sv-rc-close"))
    {
        id = ICON_PAS_SV_RC_CLOSE;
    }
    else if (!strcmp(v, "pas-sv-rc-middle"))
    {
        id = ICON_PAS_SV_RC_MIDDLE;
    }
    else if (!strcmp(v, "pas-sv-rc-far"))
    {
        id = ICON_PAS_SV_RC_FAR;
    }
    else if (!strcmp(v, "pas-sv-rc-max"))
    {
        id = ICON_PAS_SV_RC_MAX;
    }
    else if (!strcmp(v, "pas-sv-rr-inactive"))
    {
        id = ICON_PAS_SV_RR_INACTIVE;
    }
    else if (!strcmp(v, "pas-sv-rr-close"))
    {
        id = ICON_PAS_SV_RR_CLOSE;
    }
    else if (!strcmp(v, "pas-sv-rr-middle"))
    {
        id = ICON_PAS_SV_RR_MIDDLE;
    }
    else if (!strcmp(v, "pas-sv-rr-far"))
    {
        id = ICON_PAS_SV_RR_FAR;
    }
    else if (!strcmp(v, "pas-sv-rr-max"))
    {
        id = ICON_PAS_SV_RR_MAX;
    }
    else if (!strcmp(v, "pas-off"))
    {
        id = ICON_PAS_OFF;
    }
    else if (!strcmp(v, "pas-tv-failure"))
    {
        id = ICON_PAS_FAILURE;
    }
    else if (!strcmp(v, "pas-tv-sonar-failure"))
    {
        id = ICON_PAS_SONAR_FAILURE;
    }
    else if (!strcmp(v, "cta-alert-l1-100"))
    {
        id = ICON_CTA_WARNING_BRIGHT_LEFT;
    }
    else if (!strcmp(v, "cta-alert-l1-50"))
    {
        id = ICON_CTA_WARNING_DARK_LEFT;
    }
    else if (!strcmp(v, "cta-alert-r1-100"))
    {
        id = ICON_CTA_WARNING_BRIGHT_RIGHT;
    }
    else if (!strcmp(v, "cta-alert-r1-50"))
    {
        id = ICON_CTA_WARNING_DARK_RIGHT;
    }
    else if (!strcmp(v, "cta-detect-l1-100"))
    {
        id = ICON_CTA_DETECTION_BRIGHT_LEFT;
    }
    else if (!strcmp(v, "cta-detect-l1-50"))
    {
        id = ICON_CTA_DETECTION_DARK_LEFT;
    }
    else if (!strcmp(v, "cta-detect-r1-100"))
    {
        id = ICON_CTA_DETECTION_BRIGHT_RIGHT;
    }
    else if (!strcmp(v, "cta-detect-r1-50"))
    {
        id = ICON_CTA_DETECTION_DARK_RIGHT;
    }
    else if (!strcmp(v, "aiming-error"))
    {
        id = ICON_AIMING_ERROR;
    }
    else if (!strcmp(v, "aiming-execution"))
    {
        id = ICON_AIMING_EXECUTION;
    }
    else if (!strcmp(v, "aiming-inspection"))
    {
        id = ICON_AIMING_INSPECTION;
    }
    else if (!strcmp(v, "aiming-front-camera"))
    {
        id = ICON_AIMING_FRONT;
    }
    else if (!strcmp(v, "aiming-rear-camera"))
    {
        id = ICON_AIMING_REAR;
    }
    else if (!strcmp(v, "aiming-left-camera"))
    {
        id = ICON_AIMING_LEFT;
    }
    else if (!strcmp(v, "aiming-right-camera"))
    {
        id = ICON_AIMING_RIGHT;
    }
    else if (!strcmp(v, "aiming-steering"))
    {
        id = ICON_AIMING_STEERING;
    }
    else if (!strcmp(v, "aiming-speed"))
    {
        id = ICON_AIMING_SPEED;
    }
    else if (!strcmp(v, "aiming-status-processing"))
    {
        id = ICON_AIMING_STATUS_PROCESSING;
    }
    else if (!strcmp(v, "aiming-status-pause"))
    {
        id = ICON_AIMING_STATUS_PAUSE;
    }
    else if (!strcmp(v, "aiming-status-failure"))
    {
        id = ICON_AIMING_STATUS_FAILURE;
    }
    else if (!strcmp(v, "aiming-status-success"))
    {
        id = ICON_AIMING_STATUS_SUCCESS;
    }
    else if (!strcmp(v, "aiming-marker-tv"))
    {
        id = ICON_AIMING_MARKER_TV;
    }

    else if (!strcmp(v, "aim-arrow-green"))
    {
        id = ICON_AIM_ARROW_GREEN;
    }
    else if (!strcmp(v, "aim-arrow-red"))
    {
        id = ICON_AIM_ARROW_RED;
    }
    else if (!strcmp(v, "aim-arrow-yellow"))
    {
        id = ICON_AIM_ARROW_YELLOW;
    }
    else if (!strcmp(v, "aim-arrow-gray"))
    {
        id = ICON_AIM_ARROW_GRAY;
    }
    else if (!strcmp(v, "aim-play"))
    {
        id = ICON_AIM_PLAY;
    }
    else if (!strcmp(v, "aim-pause"))
    {
        id = ICON_AIM_PAUSE;
    }
    else if (!strcmp(v, "aim-failure"))
    {
        id = ICON_AIM_FAILURE;
    }
    else if (!strcmp(v, "aim-success"))
    {
        id = ICON_AIM_SUCCESS;
    }
    else if (!strcmp(v, "aim-frame"))
    {
        id = ICON_AIM_FRAME;
    }
    else if (!strcmp(v, "aim-progress-0"))
    {
        id = ICON_AIM_PROGRESS_0;
    }
    else if (!strcmp(v, "aim-progress-25"))
    {
        id = ICON_AIM_PROGRESS_25;
    }
    else if (!strcmp(v, "aim-progress-50"))
    {
        id = ICON_AIM_PROGRESS_50;
    }
    else if (!strcmp(v, "aim-progress-75"))
    {
        id = ICON_AIM_PROGRESS_75;
    }
    else if (!strcmp(v, "aim-progress-100"))
    {
        id = ICON_AIM_PROGRESS_100;
    }

    else if (!strcmp(v, "ui-sv3d-active"))
    {
        id = ICON_UI_SV3D_ACTIVE;
    }
    else if (!strcmp(v, "ui-sv3d"))
    {
        id = ICON_UI_SV3D;
    }
    else if (!strcmp(v, "ui-tv-active"))
    {
        id = ICON_UI_TV_ACTIVE;
    }
    else if (!strcmp(v, "ui-tv"))
    {
        id = ICON_UI_TV;
    }
    else if (!strcmp(v, "ui-front-active"))
    {
        id = ICON_UI_FRONT_ACTIVE;
    }
    else if (!strcmp(v, "ui-front"))
    {
        id = ICON_UI_FRONT;
    }
    else if (!strcmp(v, "ui-rear-active"))
    {
        id = ICON_UI_REAR_ACTIVE;
    }
    else if (!strcmp(v, "ui-rear"))
    {
        id = ICON_UI_REAR;
    }
    else if (!strcmp(v, "ui-ct-active"))
    {
        id = ICON_UI_CT_ACTIVE;
    }
    else if (!strcmp(v, "ui-ct"))
    {
        id = ICON_UI_CT;
    }
    else
    {
        id = ICON_UNKNOWN;
    }

    return id;
}

/**
 * @brief   Parse icon items
 *
 * @param   cfg[in]         Icon configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_icon_item_config(cfg_icon_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    cfg->number = __SEQ_LENGTH(root);

    /* ...allocate items array */
    CHK_ERR(cfg->item = calloc(cfg->number, sizeof(*cfg->item)), -errno);

    /* ...process items array */
    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        yaml_node_t        *key = yaml_document_get_node(doc, *item);
        yaml_node_pair_t   *pair;
        int                 i = __SEQ_INDEX(root, item);

        /* ...type check */
        CHK_ERR(key && key->type == YAML_MAPPING_NODE, syntax_error(doc, key, "mapping expected"));

        /* ...process individual item */
        for (pair = key->data.mapping.pairs.start; pair != key->data.mapping.pairs.top; pair++)
        {
            yaml_node_t    *subkey = yaml_document_get_node(doc, pair->key);
            yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
            char           *t, *v;

            /* ...sanity check; values must be valid */
            BUG(!subkey || !value, _x("internal error: subkey=%p, value=%p"), subkey, value);

            CHK_ERR(t = parse_token(doc, subkey), -errno);

            if (!strcmp(t, "id"))
            {
                CHK_ERR(v = parse_token(doc, value), -errno);

                cfg->item[i].id = cfg_icon_name_lookup(v);
            }
            else if (!strcmp(t, "src"))
            {
                CHK_API(parse_vector(cfg->item[i].src, 4, doc, value));
            }
            else
            {
                TRACE(DEBUG, _b("ignore unknown key '%s'"), t);
            }
        }
    }

    return 0;
}

/**
 * @brief   Parse icons configuration section
 *
 * @param   cfg[in]         Icon configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_icon_config(cfg_icon_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...retrieve matrix parameters */
    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        /* ...read parameters */
        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "file"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->file = strdup(v), -errno);
        }
        else if (!strcmp(t, "items"))
        {
            CHK_API(parse_icon_item_config(cfg, doc, value));
        }
        else
        {
            TRACE(DEBUG, _x("ignore unknonw key '%s'"), t);
        }
    }

    return 0;
}


/**
 * @brief   Parse icons configuration section
 *
 * @param   cfg[in]         Icons configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_icons_config(cfg_icons_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...create number of configurations */
    cfg->number = __SEQ_LENGTH(root);

    /* ...allocate items array */
    CHK_ERR(cfg->icon = calloc(cfg->number, sizeof(*cfg->icon)), -1);

    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        CHK_API(parse_icon_config(&cfg->icon[__SEQ_INDEX(root, item)], doc, yaml_document_get_node(doc, *item)));
    }

    return __SEQ_LENGTH(root);
}


/*******************************************************************************
 * View-manager configuration parsing
 ******************************************************************************/

/**
 * @brief   Parse view-manager configuration
 *
 * @param   cfg[in]         View-manager configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_vm_config(cfg_vm_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "front-view"))
        {
            CHK_API(parse_scv_mesh_config(&cfg->front_view, doc, value));
        }
        else if (!strcmp(t, "front-wide-view"))
        {
            CHK_API(parse_scv_mesh_config(&cfg->front_wide_view, doc, value));
        }
        else if (!strcmp(t, "rear-view"))
        {
            CHK_API(parse_scv_mesh_config(&cfg->rear_view, doc, value));
        }
        else if (!strcmp(t, "rear-sonar-view"))
        {
            CHK_API(parse_scv_mesh_config(&cfg->rear_sonar_view, doc, value));
        }
        else if (!strcmp(t, "rear-wide-view"))
        {
            CHK_API(parse_scv_mesh_config(&cfg->rear_wide_view, doc, value));
        }
        else if (!strcmp(t, "side-view"))
        {
            CHK_API(parse_mcv_mesh_config(&cfg->side_view, doc, value));
        }
        else if (!strcmp(t, "debug-view"))
        {
            CHK_API(parse_mcv_mesh_config(&cfg->debug_view, doc, value));
        }
        else if (!strcmp(t, "rear-centric-view"))
        {
            CHK_API(parse_scv_mesh_config(&cfg->rear_centric_view, doc, value));
        }
        else if (!strcmp(t, "front-stv"))
        {
            CHK_API(parse_stv_mesh_config(&cfg->front_stv, doc, value));
        }
        else if (!strcmp(t, "rear-stv"))
        {
            CHK_API(parse_stv_mesh_config(&cfg->rear_stv, doc, value));
        }
        else if (!strcmp(t, "front-tv"))
        {
            CHK_API(parse_tv_mesh_config(&cfg->front_tv, doc, value));
        }
        else if (!strcmp(t, "rear-tv"))
        {
            CHK_API(parse_tv_mesh_config(&cfg->rear_tv, doc, value));
        }
        else if (!strcmp(t, "fadeout-duration"))
        {
            CHK_API(parse_uint(&cfg->fadeout_duration, doc, value));
        }
        else if (!strcmp(t, "default-layout"))
        {
            CHK_API(parse_uint(&cfg->default_layout, doc, value));
        }
        else if (!strcmp(t, "width"))
        {
            CHK_API(parse_uint(&cfg->width, doc, value));
        }
        else if (!strcmp(t, "height"))
        {
            CHK_API(parse_uint(&cfg->height, doc, value));
        }
        else if (!strcmp(t, "scale-factor"))
        {
            CHK_API(parse_float(&cfg->scale, doc, value));
        }
        else if (!strcmp(t, "sonar-sv"))
        {
            CHK_API(parse_sonar_config(&cfg->sonar_sv, doc, value));
        }
        else if (!strcmp(t, "sonar-tv"))
        {
            CHK_API(parse_sonar_config(&cfg->sonar_tv, doc, value));
        }
        else if (!strcmp(t, "sonar-sc"))
        {
            CHK_API(parse_sonar_config(&cfg->sonar_sc, doc, value));
        }
        else if (!strcmp(t, "sonar-lc"))
        {
            CHK_API(parse_sonar_config(&cfg->sonar_lc, doc, value));
        }
        else if (!strcmp(t, "sonar-nc"))
        {
            CHK_API(parse_sonar_config(&cfg->sonar_nc, doc, value));
        }
        else if (!strcmp(t, "cta-main"))
        {
            CHK_API(parse_cta_config(&cfg->cta_main, doc, value));
        }
        else if (!strcmp(t, "cta-side"))
        {
            CHK_API(parse_cta_config(&cfg->cta_side, doc, value));
        }
        else if (!strcmp(t, "cta-sonar"))
        {
            CHK_API(parse_cta_config(&cfg->cta_sonar, doc, value));
        }
        else if (!strcmp(t, "cta-centric"))
        {
            CHK_API(parse_cta_config(&cfg->cta_centric, doc, value));
        }
        else if (!strcmp(t, "aiming-error"))
        {
            CHK_API(parse_aiming_error_config(&cfg->aiming_error, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized parameter '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse object position world generator patterns configuration section
 *
 * @param   cfg[in]         World generator configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_world_position_config(cfg_world_object_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...create number of objects */
    cfg->number = __SEQ_LENGTH(root);

    /* ...allocate patterns array */
    CHK_ERR(cfg->position = calloc(cfg->number, sizeof(*cfg->position)), -1);

    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        cfg_world_position_t   *pos = &cfg->position[__SEQ_INDEX(root, item)];
        yaml_node_t            *key = yaml_document_get_node(doc, *item);
        yaml_node_pair_t       *pair;

        /* ...type check */
        CHK_ERR(key && key->type == YAML_MAPPING_NODE, syntax_error(doc, key, "mapping expected"));

        /* ...process individual item */
        for (pair = key->data.mapping.pairs.start; pair != key->data.mapping.pairs.top; pair++)
        {
            yaml_node_t    *subkey = yaml_document_get_node(doc, pair->key);
            yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
            char           *t, *v;

            /* ...sanity check; values must be valid */
            BUG(!subkey || !value, _x("internal error: subkey=%p, value=%p"), subkey, value);

            CHK_ERR(t = parse_token(doc, subkey), -errno);

            if (!strcmp(t, "origin"))
            {
                CHK_ERR(v = parse_token(doc, value), -errno);

                /* ...associate resource with icon item - tbd - somehow */
                if (!strcmp(v, "front-center"))
                {
                    pos->origin = 1;
                }
                else if (!strcmp(v, "front-left"))
                {
                    pos->origin = 2;
                }
                else if (!strcmp(v, "front-right"))
                {
                    pos->origin = 3;
                }
                else if (!strcmp(v, "center"))
                {
                    pos->origin = 4;
                }
                else if (!strcmp(v, "center-left"))
                {
                    pos->origin = 5;
                }
                else if (!strcmp(v, "center-right"))
                {
                    pos->origin = 6;
                }
                else if (!strcmp(v, "rear-center"))
                {
                    pos->origin = 7;
                }
                else if (!strcmp(v, "rear-left"))
                {
                    pos->origin = 8;
                }
                else if (!strcmp(v, "rear-right"))
                {
                    pos->origin = 9;
                }
            }
            else if (!strcmp(t, "xyz"))
            {
                if (__SEQ_LENGTH(value) == 4)
                {
                    CHK_API(parse_vector(pos->loc, 4, doc, value));
                    pos->loc[5] = pos->loc[3];
                    pos->loc[3] = pos->loc[4] = 0.0f;
                }
                else
                {
                    CHK_API(parse_vector(pos->loc, 6, doc, value));
                }
            }
        }

        TRACE(DEBUG, _b("position: origin=%d, loc=%f,%f,%f,%f"), pos->origin, pos->loc[0], pos->loc[1], pos->loc[2], pos->loc[3]);
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parse world generator patterns configuration section
 *
 * @param   cfg[in]         World generator configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_world_object_config(cfg_world_object_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "model"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->model = strdup(v), -errno);
        }
        else if (!strcmp(t, "places"))
        {
            CHK_API(parse_world_position_config(cfg, doc, value));
        }
    }

    return 0;
}


/**
 * @brief   Parse world generator patterns configuration section
 *
 * @param   cfg[in]         World generator configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_world_pattern_config(cfg_world_pattern_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "id"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            CHK_ERR(cfg->id = strdup(v), -errno);
        }
        else if (!strcmp(t, "objects"))
        {
            yaml_node_item_t   *item;

            /* ...sequence is expected */
            CHK_ERR(value->type == YAML_SEQUENCE_NODE, syntax_error(doc, value, "sequence expected"));

            /* ...create number of objects */
            cfg->number = __SEQ_LENGTH(value);

            /* ...allocate patterns array */
            CHK_ERR(cfg->object = calloc(cfg->number, sizeof(*cfg->object)), -1);

            for (item = value->data.sequence.items.start; item != value->data.sequence.items.top; item++)
            {
                CHK_API(parse_world_object_config(&cfg->object[__SEQ_INDEX(value, item)], doc, yaml_document_get_node(doc, *item)));
            }
        }
    }

    return 0;
}

/**
 * @brief   Parse world generator patterns configuration section
 *
 * @param   cfg[in]         World generator configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_world_patterns_config(cfg_world_gen_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...create number of patterns */
    cfg->number = __SEQ_LENGTH(root);

    /* ...allocate patterns array */
    CHK_ERR(cfg->pattern = calloc(cfg->number, sizeof(*cfg->pattern)), -1);

    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        CHK_API(parse_world_pattern_config(&cfg->pattern[__SEQ_INDEX(root, item)], doc, yaml_document_get_node(doc, *item)));
        TRACE(DEBUG, _b("pattern '%s' processed"), cfg->pattern[__SEQ_INDEX(root, item)].id);
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parse world generator configuration section
 *
 * @param   cfg[in]         World generator configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_world_gen_config(cfg_world_gen_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "patterns"))
        {
            CHK_API(parse_world_patterns_config(cfg, doc, value));
        }
        else if (!strcmp(t, "car-model"))
        {
            /* ...allocate car model object */
            CHK_ERR(cfg->car = calloc(1, sizeof(*cfg->car)), -1);
            CHK_API(parse_world_object_config(cfg->car, doc, value));
        }
        else if (!strcmp(t, "lens-shading-angle"))
        {
            CHK_API(parse_float(&cfg->lens_shading_angle_deg, doc, value));
            CHK_ERR(cfg->lens_shading_angle_deg > 0.0f && cfg->lens_shading_angle_deg < 360.0f, -(errno = ERANGE));
        }
        else if (!strcmp(t, "lens-shading-size"))
        {
            CHK_API(parse_float(&cfg->lens_shading_size, doc, value));
            CHK_ERR(cfg->lens_shading_size > 0.0f && cfg->lens_shading_size < 1.0f, -(errno = ERANGE));
        }
        else if (!strcmp(t, "clipping"))
        {
            CHK_API(parse_float(&cfg->clipping_mm, doc, value));
            CHK_ERR(cfg->clipping_mm >= 0.0f, -(errno = ERANGE));
        }
    }

    return 0;
}

/**
 * @brief   UI page comparison functor
 *
 * @param   a[in]       First parameter
 * @param   b[in]       Second parameter
 *
 * @return              Comparison result
 */
static int ui_str_cmp(const void *a, const void *b)
{
    const char  * const * A = a, * const *B = b;

    return strcmp(*A, *B);
}

/**
 * @brief   UI parser data
 */
typedef struct ui_parse_data
{
    /**> Page identifiers map */
    void                   *page_map;

    /**> Buttons identifiers map */
    void                   *button_map;

    /**> Total number of button identifiers */
    uint32_t                number;

    /**> Global array of button identifiers */
    cfg_ui_button_t        *buttons;

    /**> Current index of buttons resource */
    uint32_t                idx;

    /**> Array of pages */
    cfg_ui_page_t          *pages;

}   ui_parse_data_t;

/**
 * @brief  Button index / identifier
 */
typedef struct ui_parse_index
{
    /**> Item identifer */
    char                   *id;

    /**> Item index in generic map */
    uint32_t                index;

}   ui_parse_index_t;

/**
 * @brief   Parse UI buttons resource items
 *
 * @param   cfg[in]         Button configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ui_buttons_config(cfg_ui_file_t *cfg, ui_parse_data_t *ui, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t       *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    cfg->number = __SEQ_LENGTH(root);
    cfg->idx = ui->number;

    /* ...reallocate global buttons array */
    CHK_ERR(ui->buttons = realloc(ui->buttons, (ui->number += cfg->number) * sizeof(*ui->buttons)), -errno);

    /* ...set writing position in items array */
    cfg_ui_button_t    *button = &ui->buttons[cfg->idx];

    memset(button, 0, cfg->number * sizeof(*button));

    /* ...process items array */
    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        yaml_node_t        *key = yaml_document_get_node(doc, *item);
        yaml_node_pair_t   *pair;
        //int                 i = __SEQ_INDEX(root, item);

        /* ...type check */
        CHK_ERR(key && key->type == YAML_MAPPING_NODE, syntax_error(doc, key, "mapping expected"));

        /* ...process individual item */
        for (pair = key->data.mapping.pairs.start; pair != key->data.mapping.pairs.top; pair++)
        {
            yaml_node_t    *subkey = yaml_document_get_node(doc, pair->key);
            yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
            char           *t, *v;

            /* ...sanity check; values must be valid */
            BUG(!subkey || !value, _x("internal error: subkey=%p, value=%p"), subkey, value);

            CHK_ERR(t = parse_token(doc, subkey), -errno);

            if (!strcmp(t, "id"))
            {
                ui_parse_index_t   *index;

                CHK_ERR(v = parse_token(doc, value), -errno);

                CHK_ERR(index = malloc(sizeof(*index)), -errno);

                /* ...set text identifier */
                button->id = index->id = strdup(v);
                index->index = (uint32_t)(button - &ui->buttons[0]);

                /* ...add item in the map */
                ui_parse_index_t  **val;
                CHK_ERR(val = tsearch(index, &ui->button_map, ui_str_cmp), -1);
                if (*val != index)
                {
                    TRACE(ERROR, _b("ui-button '%s' clash: %d and %d"), v, index->index, (*val)->index);
                    return -(errno = EINVAL);
                }
            }
            else if (!strcmp(t, "src"))
            {
                CHK_API(parse_vector(button->src, 4, doc, value));
            }
            else
            {
                TRACE(DEBUG, _b("ignore unknown key '%s'"), t);
            }
        }

        /* ...make sure button id is assigned */
        CHK_ERR(button->id, -(errno = EINVAL));

        /* ...save buttons resource index */
        button->idx = ui->idx;

        /* ...advance to next item */
        button++;
    }

    return 0;
}

/**
 * @brief   Parse UI buttons configuration section
 *
 * @param   cfg[in]         UI configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ui_files_config(cfg_ui_t *cfg, ui_parse_data_t *ui, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...create number of button-resources files */
    cfg->files_num = __SEQ_LENGTH(root);

    /* ...allocate buttons array */
    CHK_ERR(cfg->files = calloc(cfg->files_num, sizeof(*cfg->files)), -1);

    /* ...process all button resources */
    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        cfg_ui_file_t      *file = &cfg->files[__SEQ_INDEX(root, item)];
        yaml_node_t        *node = yaml_document_get_node(doc, *item);
        yaml_node_pair_t   *pair;

        /* ...mapping is expected */
        CHK_ERR(node->type == YAML_MAPPING_NODE, syntax_error(doc, node, "mapping expected"));

        /* ...process all buttons resource files */
        for (pair = node->data.mapping.pairs.start; pair != node->data.mapping.pairs.top; pair++)
        {
            yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
            yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
            char           *t, *v;

            /* ...sanity check */
            BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

            CHK_ERR(t = parse_token(doc, key), -errno);

            if (!strcmp(t, "file"))
            {
                CHK_ERR(v = parse_token(doc, value), -errno);
                CHK_ERR(file->file = strdup(v), -errno);
            }
            else if (!strcmp(t, "items"))
            {
                CHK_API(parse_ui_buttons_config(file, ui, doc, value));
            }
            else
            {
                TRACE(DEBUG, _x("ignore unknown key '%s'"), t);
            }
        }

        /* ...advance buttons-resource index */
        ui->idx++;
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parser UI views array for given page
 */
static inline int parse_ui_views_array(cfg_ui_page_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...set number of views */
    cfg->views_num = __SEQ_LENGTH(root);

    /* ...allocate views array */
    CHK_ERR(cfg->views = calloc(cfg->views_num, sizeof(*cfg->views)), -1);

    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        cfg_mesh_t        **view = &cfg->views[__SEQ_INDEX(root, item)];
        yaml_node_t        *node = yaml_document_get_node(doc, *item);

        CHK_API(parse_mesh_config(view, doc, node));
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parse generic overlay configuration
 *
 * @param   ovl[out]        Guideline overlay configuration data pointer
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ovl_guide_config(cfg_ovl_guide_t *ovl, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...search for overlay type */
    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "subtype"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            if (!strcmp(v, "front"))
            {
                ovl->subtype = GUIDE_FRONT;
            }
            else if (!strcmp(v, "rear"))
            {
                ovl->subtype = GUIDE_REAR;
            }
            else if (!strcmp(v, "front-wide"))
            {
                ovl->subtype = GUIDE_FRONT_WIDE;
            }
            else if (!strcmp(v, "rear-wide"))
            {
                ovl->subtype = GUIDE_REAR_WIDE;
            }
            else if (!strcmp(v, "top-front"))
            {
                ovl->subtype = GUIDE_TOP_FRONT;
            }
            else if (!strcmp(v, "top-rear"))
            {
                ovl->subtype = GUIDE_TOP_REAR;
            }
            else if (!strcmp(v, "sv-left"))
            {
                ovl->subtype = GUIDE_SV_LEFT;
            }
            else if (!strcmp(v, "sv-right"))
            {
                ovl->subtype = GUIDE_SV_RIGHT;
            }
            else if (!strcmp(v, "stv-front"))
            {
                ovl->subtype = GUIDE_STV_FRONT;
            }
            else if (!strcmp(v, "stv-rear"))
            {
                ovl->subtype = GUIDE_STV_REAR;
            }
            else
            {
                return syntax_error(doc, value, "unknown type '%s'", v);
            }
        }
        else
        {
            TRACE(DEBUG, _b("ignore unknown key '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse icon overlay configuration
 *
 * @param   ovl[out]        Icon overlay configuration data pointer
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ovl_icon_config(cfg_ovl_icon_t *ovl, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...search for overlay type */
    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "icon"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            if (!strcmp(v, "sonar-tv"))
            {
                ovl->subtype = ICON_OVL_CAR_TV;
            }
            else if (!strcmp(v, "sonar-sv"))
            {
                ovl->subtype = ICON_OVL_CAR_SV;
            }
            else if (!strcmp(v, "cta-front"))
            {
                ovl->subtype = ICON_OVL_CTA_FRONT;
            }
            else if (!strcmp(v, "cta-rear"))
            {
                ovl->subtype = ICON_OVL_CTA_REAR;
            }
            else if (!strcmp(v, "border"))
            {
                ovl->subtype = ICON_OVL_BORDER;
            }
            else if (!strcmp(v, "aiming"))
            {
                ovl->subtype = ICON_OVL_AIMING;
            }
            else
            {
                return syntax_error(doc, value, "unknown type '%s'", v);
            }
        }
        else if (!strcmp(t, "dst"))
        {
            CHK_API(parse_ivector(ovl->dst, 4, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unknown key '%s'"), t);
        }
    }

    return 0;
}

/**
 * @brief   Parse generic overlay configuration
 *
 * @param   mesh[out]       Overlay configuration data pointer
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ovl_config(cfg_ovl_t **ovl, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...search for overlay type */
    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t, *v;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "type"))
        {
            CHK_ERR(v = parse_token(doc, value), -errno);
            if (!strcmp(v, "guide"))
            {
                CHK_ERR(*ovl = calloc(1, sizeof((*ovl)->guide)), -1);
                (*ovl)->type = OVL_GUIDE;
                CHK_API(parse_ovl_guide_config(&(*ovl)->guide, doc, root));
            }
            else if (!strcmp(v, "icon"))
            {
                CHK_ERR(*ovl = calloc(1, sizeof((*ovl)->icon)), -1);
                (*ovl)->type = OVL_ICON;
                CHK_API(parse_ovl_icon_config(&(*ovl)->icon, doc, root));
            }
            else if (!strcmp(v, "car"))
            {
                CHK_ERR(*ovl = calloc(1, sizeof((*ovl)->car)), -1);
                (*ovl)->type = OVL_CAR;
                //CHK_API(parse_tv_mesh_config(&(*mesh)->tv, doc, root));
            }
            else
            {
                TRACE(ERROR, _b("unrecognized overlay type: '%s'"), v);
            }

            TRACE(DEBUG, _b("parsed overlay type '%s'"), v);

            break;
        }
    }

    return 0;
}

/**
 * @brief   Parser UI overlays array for given page
 */
static inline int parse_ui_overlays_array(cfg_ui_page_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...set number of overlays */
    cfg->ovl_num = __SEQ_LENGTH(root);

    /* ...allocate overlays array */
    CHK_ERR(cfg->ovl = calloc(cfg->ovl_num, sizeof(*cfg->ovl)), -1);

    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        cfg_ovl_t        ***ovl = &cfg->ovl[__SEQ_INDEX(root, item)];
        yaml_node_t        *node = yaml_document_get_node(doc, *item);
        yaml_node_item_t   *subitem;

        /* ...mapping is expected */
        CHK_ERR(node->type == YAML_SEQUENCE_NODE, syntax_error(doc, node, "mapping expected"));

        /* ...allocate nested array */
        CHK_ERR(*ovl = calloc(__SEQ_LENGTH(node) + 1, sizeof(**ovl)), -1);

        /* ...process nested overlays array */
        for (subitem = node->data.sequence.items.start; subitem != node->data.sequence.items.top; subitem++)
        {
            yaml_node_t        *subnode = yaml_document_get_node(doc, *subitem);

            /* ...parse individual overlay */
            CHK_API(parse_ovl_config(&(*ovl)[__SEQ_INDEX(node, subitem)], doc, subnode));
        }
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parse UI buttons array configuration section
 *
 * @param   cfg[in]         UI page configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ui_buttons_array(cfg_ui_page_t *cfg, ui_parse_data_t *ui, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...set number of buttons */
    cfg->buttons_num = __SEQ_LENGTH(root);

    /* ...allocate buttons array */
    CHK_ERR(cfg->buttons = calloc(cfg->buttons_num, sizeof(*cfg->buttons)), -1);

    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        cfg_ui_button_pos_t    *button = &cfg->buttons[__SEQ_INDEX(root, item)];
        yaml_node_t            *node = yaml_document_get_node(doc, *item);
        yaml_node_pair_t       *pair;

        /* ...mapping is expected */
        CHK_ERR(node->type == YAML_MAPPING_NODE, syntax_error(doc, node, "mapping expected"));

        button->action = -1;

        for (pair = node->data.mapping.pairs.start; pair != node->data.mapping.pairs.top; pair++)
        {
            yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
            yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
            char           *t, *v;

            /* ...sanity check */
            BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

            CHK_ERR(t = parse_token(doc, key), -errno);

            if (!strcmp(t, "id"))
            {
                CHK_ERR(v = parse_token(doc, value), -errno);

                /* ...find button id in the map */
                ui_parse_index_t   **val = tfind(&v, &ui->button_map, ui_str_cmp);
                if (val == NULL)
                {
                    TRACE(ERROR, _b("button '%s' not found"), v);
                    return syntax_error(doc, key, "button '%s' not found", v);
                }

                /* ...save button index as identifier */
                button->id = (*val)->index;
            }
            else if (!strcmp(t, "dst"))
            {
                CHK_API(parse_ivector(button->dst, 4, doc, value));
            }
            else if (!strcmp(t, "action"))
            {
                CHK_ERR(v = parse_token(doc, value), -errno);

                /* ...find page-id */
                if (strcmp(v, "prev") != 0)
                {
                    cfg_ui_page_t  **val = tfind(&v, &ui->page_map, ui_str_cmp);

                    if (val == NULL)
                    {
                        //return syntax_error(doc, key, "page '%s' not found", v);
                    }
                    else
                    {
                        button->action = 1 + (int)(*val - ui->pages);
                    }
                }
                else
                {
                    button->action = 0;
                }
            }
            else if (!strcmp(t, "visible"))
            {
                CHK_API(parse_ui8(&button->visible, doc, value));
            }
        }
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parse UI pages configuration section
 *
 * @param   cfg[in]         UI configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ui_pages_config(cfg_ui_t *cfg, ui_parse_data_t *ui, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_item_t   *item;

    /* ...sequence is expected */
    CHK_ERR(root->type == YAML_SEQUENCE_NODE, syntax_error(doc, root, "sequence expected"));

    /* ...create number of pages */
    cfg->pages_num = __SEQ_LENGTH(root);

    /* ...allocate pages array */
    CHK_ERR(ui->pages = calloc(cfg->pages_num, sizeof(*ui->pages)), -1);

    /* ...first pass - create page text identifiers */
    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        cfg_ui_page_t      *page = &ui->pages[__SEQ_INDEX(root, item)];
        yaml_node_t        *node = yaml_document_get_node(doc, *item);
        yaml_node_pair_t   *pair;

        /* ...mapping is expected */
        CHK_ERR(node->type == YAML_MAPPING_NODE, syntax_error(doc, node, "mapping expected"));

        /* ...search for page id */
        for (pair = node->data.mapping.pairs.start; pair != node->data.mapping.pairs.top; pair++)
        {
            yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
            yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
            char           *t, *v;

            /* ...sanity check */
            BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

            CHK_ERR(t = parse_token(doc, key), -errno);

            if (!strcmp(t, "id"))
            {
                CHK_ERR(v = parse_token(doc, value), -1);

                /* ...save page text identifier */
                CHK_ERR(page->id = strdup(v), -1);

                /* ...insert page id into map */
                cfg_ui_page_t  **val;
                CHK_ERR(val = tsearch(page, &ui->page_map, ui_str_cmp), -(errno = ENOMEM));
                if (*val != page)
                {
                    TRACE(ERROR, _b("page-id '%s' clash: %d and %d"), page->id, (int)(*val - ui->pages), (int)(page - ui->pages));
                    return -(errno = EINVAL);
                }

                break;
            }
        }
    }

    /* ...second pass - process pages layouts */
    for (item = root->data.sequence.items.start; item != root->data.sequence.items.top; item++)
    {
        cfg_ui_page_t      *page = &ui->pages[__SEQ_INDEX(root, item)];
        yaml_node_t        *node = yaml_document_get_node(doc, *item);
        yaml_node_pair_t   *pair;

        /* ...mapping is expected */
        CHK_ERR(node->type == YAML_MAPPING_NODE, syntax_error(doc, node, "mapping expected"));

        for (pair = node->data.mapping.pairs.start; pair != node->data.mapping.pairs.top; pair++)
        {
            yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
            yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
            char           *t, *v;

            /* ...sanity check */
            BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

            CHK_ERR(t = parse_token(doc, key), -errno);

            if (!strcmp(t, "views"))
            {
                CHK_API(parse_ui_views_array(page, doc, value));
            }
            else if (!strcmp(t, "overlays"))
            {
                CHK_API(parse_ui_overlays_array(page, doc, value));
            }
            else if (!strcmp(t, "buttons"))
            {
                CHK_API(parse_ui_buttons_array(page, ui, doc, value));
            }
        }

        TRACE(INFO, _b("page-%u['%s']: %u views, %u overlays, %u buttons"), __SEQ_INDEX(root, item), page->id, page->views_num, page->ovl_num, page->buttons_num);
    }

    return __SEQ_LENGTH(root);
}

/**
 * @brief   Parse UI configuration
 *
 * @param   cfg[in]         UI configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_ui_config(cfg_ui_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;
    ui_parse_data_t     ui;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...clear UI parser data */
    memset(&ui, 0, sizeof(ui));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "buttons"))
        {
            CHK_API(parse_ui_files_config(cfg, &ui, doc, value));
        }
        else if (!strcmp(t, "pages"))
        {
            CHK_API(parse_ui_pages_config(cfg, &ui, doc, value));
        }
    }

    /* ...save parsed UI data */
    cfg->pages = ui.pages;
    cfg->buttons_num = ui.number;
    cfg->buttons = ui.buttons;

    return 0;
}

/**
 * @brief   Parse scene parameters configuration
 *
 * @param   cfg[in]         Scene parameters configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_scene_params_config(cfg_scene_params_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);
        char           *t;

        /* ...sanity check */
        BUG(!key || !value, _x("internal error: key=%p, value=%p"), key, value);

        CHK_ERR(t = parse_token(doc, key), -errno);

        if (!strcmp(t, "zoom-factor"))
        {
            CHK_API(parse_float(&cfg->zoom_factor, doc, value));
        }
        else if (!strcmp(t, "zoom-threshold"))
        {
            CHK_API(parse_float(&cfg->zoom_threshold, doc, value));
        }
        else if (!strcmp(t, "zoom-min-length"))
        {
            CHK_API(parse_float(&cfg->zoom_min_length, doc, value));
        }
        else if (!strcmp(t, "zoom-max-length"))
        {
            CHK_API(parse_float(&cfg->zoom_max_length, doc, value));
        }
        else if (!strcmp(t, "pan-velocity-x"))
        {
            CHK_API(parse_float(&cfg->pan_velocity_x, doc, value));
        }
        else if (!strcmp(t, "pan-velocity-y"))
        {
            CHK_API(parse_float(&cfg->pan_velocity_y, doc, value));
        }
        else if (!strcmp(t, "pan-max-length"))
        {
            CHK_API(parse_float(&cfg->pan_max_length, doc, value));
        }
        else if (!strcmp(t, "rotate-velocity-yaw"))
        {
            CHK_API(parse_float(&cfg->rotate_velocity_yaw, doc, value));
        }
        else if (!strcmp(t, "rotate-velocity-pitch"))
        {
            CHK_API(parse_float(&cfg->rotate_velocity_pitch, doc, value));
        }
        else if (!strcmp(t, "rotate-pitch-max"))
        {
            CHK_API(parse_float(&cfg->rotate_pitch_max, doc, value));
        }
        else if (!strcmp(t, "rotate-pitch-min"))
        {
            CHK_API(parse_float(&cfg->rotate_pitch_min, doc, value));
        }
        else if (!strcmp(t, "rotate-pitch-threshold"))
        {
            CHK_API(parse_float(&cfg->rotate_pitch_threshold, doc, value));
        }
        else if (!strcmp(t, "rotate-yaw-threshold"))
        {
            CHK_API(parse_float(&cfg->rotate_yaw_threshold, doc, value));
        }
    }

    return 0;
}

/**
 * @brief   Top-level configuration parser
 *
 * @param   cfg[in]         Configuration data
 * @param   doc[in]         YAML document
 * @param   root[in]        YAML node of section
 *
 * @return                  Negative on failure
 */
static inline int parse_toplevel_config(cfg_data_t *cfg, yaml_document_t *doc, yaml_node_t *root)
{
    yaml_node_pair_t   *pair;

    /* ...mapping is expected */
    CHK_ERR(root->type == YAML_MAPPING_NODE, syntax_error(doc, root, "mapping expected"));

    /* ...process high-level options */
    for (pair = root->data.mapping.pairs.start; pair != root->data.mapping.pairs.top; pair++)
    {
        yaml_node_t    *key = yaml_document_get_node(doc, pair->key);
        yaml_node_t    *value = yaml_document_get_node(doc, pair->value);

        /* ...sanity check; values must be valid */
        if (!key || !value)
            break;

        char           *t, *v;

        CHK_ERR(t = parse_token(doc, key), -errno);

        /* ...process individual parameters */
        if (!strcmp(t, "cameras"))
        {
            CHK_API(cfg->cameras_number = parse_cameras_cfg(cfg->camera, doc, value));
        }
        else if (!strcmp(t, "cc"))
        {
            CHK_API(parse_cc_config(&cfg->cc, doc, value));
        }
        else if (!strcmp(t, "hv"))
        {
            CHK_API(parse_hv_config(&cfg->hv, doc, value));
        }
        else if (!strcmp(t, "vehicle"))
        {
            CHK_API(parse_vehicle_config(&cfg->vehicle, doc, value));
        }
        else if (!strcmp(t, "car-model"))
        {
            CHK_API(parse_car_model_config(&cfg->car_model_stv, doc, value));
        }
        else if (!strcmp(t, "car-renderer"))
        {
            CHK_API(parse_car_render_config(&cfg->car_render, doc, value));
        }
        else if (!strcmp(t, "icons"))
        {
            CHK_API(parse_icons_config(&cfg->icons, doc, value));
        }
        else if (!strcmp(t, "guidelines"))
        {
            CHK_API(parse_guide_config(&cfg->guide, doc, value));
        }
        else if (!strcmp(t, "view-manager"))
        {
            CHK_API(parse_vm_config(&cfg->vm, doc, value));
        }
        else if (!strcmp(t, "ui"))
        {
            CHK_API(parse_ui_config(&cfg->ui, doc, value));
        }
        else if (!strcmp(t, "scene-params-mouse"))
        {
            CHK_API(parse_scene_params_config(&cfg->scene_params_mouse, doc, value));
        }
        else if (!strcmp(t, "scene-params-touch"))
        {
            CHK_API(parse_scene_params_config(&cfg->scene_params_touch, doc, value));
        }
        else if (!strcmp(t, "world-gen"))
        {
            CHK_API(parse_world_gen_config(&cfg->world_gen, doc, value));
        }
        else
        {
            TRACE(DEBUG, _b("ignore unrecognized section '%s'"), t);
        }
    }

    return 0;
}

/* ...main parsing function*/
int config_parse(cfg_data_t *cfg, char *fname)
{
    yaml_parser_t   p;
    yaml_node_t    *root;
    int             r;

    /* ...create parser */
    CHK_API(parser_open(&p, fname));

    /* ...go process the file; find all sections */
    do
    {
        yaml_document_t     document;

        /* ...get next document */
        if (!yaml_parser_load(&p, &document))
        {
            syntax_error(&document, document.nodes.end, "internal");
            parser_error(&p);
            goto error;
        }

        /* ...get root document node */
        if ((root = yaml_document_get_root_node(&document)) != NULL)
        {
            if (parse_toplevel_config(cfg, &document, root) < 0)
            {
                goto error;
            }
        }

        /* ...destroy document */
        yaml_document_delete(&document);
    }
    while (root != NULL);

    TRACE(INIT, _b("Main config parsing successful"));

    /* ...return success */
    r = 0;

out:
    /* ...close parser afterwards */
    yaml_parser_delete(&p);
    return r;

error:
    TRACE(ERROR, _b("configuration parsing failed: %m"));
    r = -errno;
    goto out;
}

/*******************************************************************************
 * Configuration storing interface
 ******************************************************************************/

static int store_int(yaml_document_t *doc, int32_t value)
{
    char    buffer[64];

    snprintf(buffer, sizeof(buffer), "%d", value);

    return yaml_document_add_scalar(doc, NULL, (yaml_char_t *)buffer, -1, YAML_PLAIN_SCALAR_STYLE);
}

static int store_uint(yaml_document_t *doc, uint32_t value)
{
    char    buffer[64];

    snprintf(buffer, sizeof(buffer), "%u", value);

    return yaml_document_add_scalar(doc, NULL, (yaml_char_t *)buffer, -1, YAML_PLAIN_SCALAR_STYLE);
}

static int store_float(yaml_document_t *doc, float32_t value)
{
    char    buffer[64];

    snprintf(buffer, sizeof(buffer), "%e", value);

    return yaml_document_add_scalar(doc, NULL, (yaml_char_t *)buffer, -1, YAML_PLAIN_SCALAR_STYLE);
}

static int store_vector(yaml_document_t *doc, float32_t *value, int n)
{
    int     seq;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_FLOW_SEQUENCE_STYLE)) > 0, -1);

    while (n-- > 0)
    {
        int     item;

        CHK_ERR((item = store_float(doc, *value++)) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

static int store_ivector(yaml_document_t *doc, int32_t *value, int n)
{
    int     seq;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_FLOW_SEQUENCE_STYLE)) > 0, -1);

    while (n-- > 0)
    {
        int     item;

        CHK_ERR((item = store_int(doc, *value++)) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

static int store_ivector3(yaml_document_t *doc, int32_t (*value)[3], int n)
{
    int     seq;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_FLOW_SEQUENCE_STYLE)) > 0, -1);

    while (n-- > 0)
    {
        int     item;

        CHK_ERR((item = store_ivector(doc, *value++, 3)) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

static int store_ivector4(yaml_document_t *doc, int32_t (*value)[4], int n)
{
    int     seq;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_FLOW_SEQUENCE_STYLE)) > 0, -1);

    while (n-- > 0)
    {
        int     item;

        CHK_ERR((item = store_ivector(doc, *value++, 4)) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

static int store_uivector(yaml_document_t *doc, uint32_t *value, int n)
{
    int     seq;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_FLOW_SEQUENCE_STYLE)) > 0, -1);

    while (n-- > 0)
    {
        int     item;

        CHK_ERR((item = store_uint(doc, *value++)) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

static int store_ui8vector(yaml_document_t *doc, uint8_t *value, int n)
{
    int     seq;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_FLOW_SEQUENCE_STYLE)) > 0, -1);

    while (n-- > 0)
    {
        int     item;

        CHK_ERR((item = store_uint(doc, *value++)) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

static int store_matrix(yaml_document_t *doc, float32_t *data, int rows, int cols)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    /* ...add rows key */
    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rows", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_int(doc, rows)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    /* ...add columns key */
    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cols", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_int(doc, cols)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    /* ...add data vector */
    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"data", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, data, rows * cols)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store camera configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Camera configuration data
 *
 * @return              Positive node ID on success
 */
static int store_camera_cfg(yaml_document_t *doc, cfg_camera_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"name", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->name, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"id", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->id, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"position", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->position, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rotation", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->rotation, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    if (cfg->rotation_matrix_valid)
    {
        CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rotation-matrix", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
        CHK_ERR((value = store_vector(doc, cfg->rotation_matrix, 3 * 3)) > 0, -1);
        CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);
    }

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"resolution", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->resolution, 2)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"distortion", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->distortion, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"intrinsics", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->intrinsics, 3 * 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store cameras configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Camera configuration data array
 * @param   n[in]       Number of cameras
 *
 * @return              Positive node ID on success
 */
static int store_cameras_cfg(yaml_document_t *doc, cfg_camera_t *cfg, int n)
{
    int     seq;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_BLOCK_SEQUENCE_STYLE)) > 0, -1);

    while (n-- > 0)
    {
        int     item;

        CHK_ERR((item = store_camera_cfg(doc, cfg++)) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

/**
 * @brief   Store color-correction configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Color-correction configuration data
 *
 * @return              Positive node ID on success
 */
static int store_cc_cfg(yaml_document_t *doc, cfg_cc_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"roi-fl", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->roi[0], 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"roi-rl", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->roi[1], 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"roi-rr", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->roi[2], 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"roi-fr", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->roi[3], 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"clamp", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_int(doc, cfg->clamp)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"filter-coef", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->filter_coef)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store historical view configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Historical view configuration data
 *
 * @return              Positive node ID on success
 */
static int store_hv_cfg(yaml_document_t *doc, cfg_bv_mesh_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dim", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector3(doc, cfg->dim, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"left-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->left_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"right-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->right_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"slice-width-hor", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->slice_width_hor)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"slice-height-hor", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->slice_height_hor)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"slice-width-vert", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->slice_width_vert)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"slice-height-vert", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->slice_height_vert)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store vehicle configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Vehicle configuration
 *
 * @return              Positive node ID on success
 */
static int store_vehicle_cfg(yaml_document_t *doc, cfg_vehicle_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"width-mirrors", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->width_mirrors)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheelbase", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_base)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-overhang", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_overhang)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-overhang", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_overhang)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"left-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->left_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"right-blind-area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->right_blind_area)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-track-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_track_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-track-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_track_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-wheel-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_wheel_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-wheel-diameter", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_wheel_diameter)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-wheel-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_wheel_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-wheel-diameter", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_wheel_diameter)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-pulse-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_pulse_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"steering-coef", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->steering_coef)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"steering-lhd", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->steering_lhd)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"parking-sensor", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->parking_sensor)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store sonar-view configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Sonar-view configuration
 *
 * @return              Positive node ID on success
 */
static int store_sonar_cfg(yaml_document_t *doc, cfg_sonar_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-car-model-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_car_model_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fl-wheel-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fl_wheel_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fr-wheel-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fr_wheel_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rl-wheel-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rl_wheel_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rr-wheel-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rr_wheel_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-left-scan-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_left_scan_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-right-scan-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_right_scan_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fc-pas-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fc_pas_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fr-pas-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fr_pas_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fl-pas-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fl_pas_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rc-pas-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rc_pas_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rr-pas-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rr_pas_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rl-pas-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rl_pas_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fc-failure-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fc_failure_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fr-failure-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fr_failure_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-fl-failure-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_fl_failure_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rc-failure-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rc_failure_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rr-failure-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rr_failure_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-rl-failure-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_rl_failure_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-pas-off-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_pas_off_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-pas-failure-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->sonar_pas_failure_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store CTA configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     CTA configuration
 *
 * @return              Positive node ID on success
 */
static int store_cta_cfg(yaml_document_t *doc, cfg_cta_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-left-outer-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->cta_left_outer_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-left-inner-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->cta_left_inner_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-right-outer-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->cta_right_outer_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-right-inner-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->cta_right_inner_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store CTA configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     CTA configuration
 *
 * @return              Positive node ID on success
 */
static int store_aiming_error_cfg(yaml_document_t *doc, cfg_aiming_error_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"tv-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector4(doc, cfg->tv_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sv-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector4(doc, cfg->sv_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"nc-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector4(doc, cfg->nc_dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sc-dst", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector4(doc, cfg->sc_dst, 1)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store dynamic front/rear guidelines configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Guidelines configuration
 *
 * @return              Positive node ID on success
 */
static int store_guide_dynamic_fr_cfg(yaml_document_t *doc, cfg_guide_dynamic_fr_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"vehicle-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->vehicle_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"hidden-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->hidden_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"vehicle-trajectory-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->vehicle_trajectory_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-lateral-distance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_lateral_distance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-border-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_border_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"distance-marker-1", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->distance_marker_1)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"distance-marker-2", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->distance_marker_2)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"distance-marker-3", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->distance_marker_3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"distance-marker-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->distance_marker_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"distance-marker-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->distance_marker_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"horizontal-line-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->horizontal_line_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store dynamic side guidelines configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Guidelines configuration
 *
 * @return              Positive node ID on success
 */
static int store_guide_dynamic_sv_cfg(yaml_document_t *doc, cfg_guide_dynamic_sv_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"line-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->line_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fade-section-start-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->fade_section_start_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fade-section-end-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->fade_section_end_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"delta-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->delta_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store fixed guidelines configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Guidelines configuration
 *
 * @return              Positive node ID on success
 */
static int store_guide_fixed_fr_cfg(yaml_document_t *doc, cfg_guide_fixed_fr_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"line-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->line_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-gap", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_gap)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-gap", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_gap)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"close-section-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->close_section_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"close-interlock-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->close_interlock_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"close-interlock-gap", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->close_interlock_gap)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"surface-close-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->surface_close_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"surface-close-gap", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->surface_close_gap)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fade-section-start-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->fade_section_start_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fade-section-end-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->fade_section_end_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store fixed guidelines configuration for side-view
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Guidelines configuration
 *
 * @return              Positive node ID on success
 */
static int store_guide_fixed_sv_cfg(yaml_document_t *doc, cfg_guide_fixed_sv_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"vert-line-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->vert_line_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"hor-line-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->hor_line_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"hor-line-gap", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->hor_line_gap)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"hor-line-start", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->hor_line_start)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"vert-line-start", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->vert_line_start)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"bar-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->bar_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"bar-fade-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->bar_fade_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"hor-fade-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->hor_fade_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"vert-fade-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->vert_fade_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store top-view guidelines configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Guidelines configuration
 *
 * @return              Positive node ID on success
 */
static int store_guide_tv_cfg(yaml_document_t *doc, cfg_guide_tv_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"total-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->total_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-gap", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_gap)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-gap", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_gap)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"line-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->line_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"close-section-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->close_section_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fade-section-start-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->fade_section_start_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fade-section-end-length", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->fade_section_end_length)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store guidelines configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Guidelines configuration
 *
 * @return              Positive node ID on success
 */
static int store_guide_cfg(yaml_document_t *doc, cfg_guide_t *cfg)
{
    int     map, key, value;

    /* ...create mapping element */
    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-front", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_dynamic_fr_cfg(doc, &cfg->dynamic_front)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-rear", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_dynamic_fr_cfg(doc, &cfg->dynamic_rear)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-front-stv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_dynamic_fr_cfg(doc, &cfg->dynamic_front_stv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-rear-stv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_dynamic_fr_cfg(doc, &cfg->dynamic_rear_stv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-sv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_dynamic_sv_cfg(doc, &cfg->dynamic_sv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-sv-stv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_dynamic_sv_cfg(doc, &cfg->dynamic_sv_stv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fixed-front", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_fixed_fr_cfg(doc, &cfg->fixed_front)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fixed-front-wide", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_fixed_fr_cfg(doc, &cfg->fixed_front_wide)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fixed-rear", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_fixed_fr_cfg(doc, &cfg->fixed_rear)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fixed-rear-wide", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_fixed_fr_cfg(doc, &cfg->fixed_rear_wide)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fixed-sv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_fixed_sv_cfg(doc, &cfg->fixed_sv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"tv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_guide_tv_cfg(doc, &cfg->tv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"static-surface-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->static_surface_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"static-surface-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->static_surface_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"static-line-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->static_line_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"static-line-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->static_line_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"static-surface-close-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->static_surface_close_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"static-surface-close-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->static_surface_close_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-close-section-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->dynamic_close_section_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-line-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->dynamic_line_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"line-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->line_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-close-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->dynamic_close_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-middle-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->dynamic_middle_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"dynamic-far-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->dynamic_far_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"tv-close-section-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->tv_close_section_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"tv-close-section-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->tv_close_section_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"tv-line-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->tv_line_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"tv-line-transmittance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->tv_line_transmittance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-pas-transparency", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->stv_pas_transparency)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-pas-inactive-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->stv_pas_inactive_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-pas-close-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->stv_pas_close_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-pas-middle-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->stv_pas_middle_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-pas-far-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->stv_pas_far_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-pas-max-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->stv_pas_max_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->stv_obstacle_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-line-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->stv_obstacle_line_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-transparency", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->stv_obstacle_transparency)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-line-transparency", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->stv_obstacle_line_transparency)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-line-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_line_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-min-distance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_min_distance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-close-distance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_close_distance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-middle-distance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_middle_distance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-far-distance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_far_distance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-max-distance", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_max_distance)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"stv-obstacle-height", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->stv_obstacle_height)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

static const char * get_camera_id(uint32_t id)
{
    static const char * name[SV_CAMERAS_NUMBER] = {
        [SV_CAMERA_FRONT] = "front",
        [SV_CAMERA_LEFT] = "left",
        [SV_CAMERA_REAR] = "rear",
        [SV_CAMERA_RIGHT] = "right",
    };

    return (id < SV_CAMERAS_NUMBER ? name[id] : "unknown");
}

static const char * get_icon_id(uint32_t id)
{
    static const char * name[ICON_RESOURCE_MAX] = {
        [ICON_CAR_MODEL] = "car-model",
        [ICON_TYRE_FRONT] = "tyre-front",
        [ICON_TYRE_REAR] = "tyre-rear",
    };

    return (id < ICON_RESOURCE_MAX && name[id] != NULL ? name[id] : "unknown");
}

/**
 * @brief   Store SCV-mesh configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     SCV-configuration
 *
 * @return              Positive node ID on success
 */
static int store_scv_mesh_cfg(yaml_document_t *doc, cfg_scv_mesh_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"camera-id", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)get_camera_id(cfg->id), -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"position", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->position, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rotation", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->rotation, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fov", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->fov, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"distortion", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->distortion, 2)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"compression", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->compression, 2)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"mask", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->mask, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"window", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->base.dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store MCV-mesh configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     MCV-configuration
 *
 * @return              Positive node ID on success
 */
static int store_mcv_mesh_cfg(yaml_document_t *doc, cfg_mcv_mesh_t *cfg)
{
    int         seq, item;
    uint32_t    i;

    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_BLOCK_SEQUENCE_STYLE)) > 0, -1);

    for (i = 0; i < cfg->number; i++)
    {
        CHK_ERR((item = store_scv_mesh_cfg(doc, &cfg->scv[i])) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

/**
 * @brief   Store TV-mesh configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     TV-configuration
 *
 * @return              Positive node ID on success
 */
static int store_tv_mesh_cfg(yaml_document_t *doc, cfg_tv_mesh_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"shadow", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->shadow, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"area", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->area, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"separator-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->separator_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"separator-exp", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->separator_exp)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"angles", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->angles, 8)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"offsets", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->offsets, 8)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"window", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->base.dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store STV-mesh configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     STV-configuration
 *
 * @return              Positive node ID on success
 */
static int store_stv_mesh_cfg(yaml_document_t *doc, cfg_stv_mesh_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"position", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->position, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"look-at", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->look_at, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"shadow", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->shadow, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fov", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->fov, 2)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"angles", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->angles, 8)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"offsets", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->offsets, 8)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"parabolic", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vector(doc, cfg->parabolic, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"separator-width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->separator_width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"separator-exp", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->separator_exp)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"window", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ivector(doc, cfg->base.dst, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store car model configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     IBL configuration
 *
 * @return              Positive node ID on success
 */
static int store_ibl_cfg(yaml_document_t *doc, cfg_ibl_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sh", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->sh, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"specular", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->specular, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"diffuse", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->diffuse, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"lut", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->lut, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store car model configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Car model configuration
 *
 * @return              Positive node ID on success
 */
static int store_car_model_cfg(yaml_document_t *doc, cfg_model_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"file", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_model, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    if (cfg->ibl != NULL)
    {
        CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"ibl", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
        CHK_ERR((value = store_ibl_cfg(doc, cfg->ibl)) > 0, -1);
        CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);
    }

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"body", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_body_groups, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"shadow", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_shadow_groups, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"interior", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_interior_groups, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-fl", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_wheels_groups[0], -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-fr", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_wheels_groups[1], -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-rl", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_wheels_groups[2], -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-rr", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->car_wheels_groups[3], -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store car rendering configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Car model configuration
 *
 * @return              Positive node ID on success
 */
static int store_car_render_cfg(yaml_document_t *doc, cfg_car_render_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"window-front-opaqueness", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->window_front_opaqueness)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"window-rear-opaqueness", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->window_rear_opaqueness)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"body-opaqueness", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->body_opaqueness)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"head-opaqueness", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->head_opaqueness)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"mask-opaqueness", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->mask_opaqueness)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-height-min", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_height_min)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-height-max", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_height_max)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-gradient-exp", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->wheel_height_max)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-gradient-x", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_gradient_x)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-gradient-scale", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_gradient_scale)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-gradient-x", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_gradient_x)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-gradient-scale", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_gradient_scale)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"height-gradient-z", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->height_gradient_z)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"height-gradient-scale", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->height_gradient_scale)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-mask-gradient-start", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_mask_gradient_start)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-mask-gradient-stop", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_mask_gradient_stop)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-mask-gradient-exp", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_mask_gradient_exp)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-mask-gradient-start", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_mask_gradient_start)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-mask-gradient-stop", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_mask_gradient_stop)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-mask-gradient-exp", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_mask_gradient_exp)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-wheel-width-scale", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->front_wheel_width_scale)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-wheel-width-scale", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->rear_wheel_width_scale)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"mask-ambient-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->mask_ambient_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"wheel-ambient-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->wheel_ambient_color, 3)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"lights-tail-base-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->lights_tail_base_color, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"lights-tail-lens-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->lights_tail_lens_color, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"lights-tail-shine-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->lights_tail_shine_color, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"lights-tail-corner-color", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_ui8vector(doc, cfg->lights_tail_corner_color, 4)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store icon items configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Icon container configuration
 *
 * @return              Positive node ID on success
 */
static int store_icon_items_cfg(yaml_document_t *doc, cfg_icon_t *cfg)
{
    int         seq, item;
    uint32_t    i;

    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_BLOCK_SEQUENCE_STYLE)) > 0, -1);

    for (i = 0; i < cfg->number; i++)
    {
        int     key, value;

        CHK_ERR((item = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

        CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"id", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
        CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)get_icon_id(cfg->item[i].id), -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
        CHK_ERR(yaml_document_append_mapping_pair(doc, item, key, value) > 0, -1);

        CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"src", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
        CHK_ERR((value = store_vector(doc, cfg->item[i].src, 4)) > 0, -1);
        CHK_ERR(yaml_document_append_mapping_pair(doc, item, key, value) > 0, -1);

        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

/**
 * @brief   Store icon container configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Icon container configuration
 *
 * @return              Positive node ID on success
 */
static int store_icon_cfg(yaml_document_t *doc, cfg_icon_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"file", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)cfg->file, -1, YAML_DOUBLE_QUOTED_SCALAR_STYLE)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"items", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_icon_items_cfg(doc, cfg)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store icons configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Icons configuration
 * @param   n[in]       Number of cameras
 *
 * @return              Positive node ID on success
 */
static int store_icons_cfg(yaml_document_t *doc, cfg_icons_t *cfg)
{
    uint32_t    i;
    int         seq, item;

    /* ...create sequence element */
    CHK_ERR((seq = yaml_document_add_sequence(doc, NULL, YAML_BLOCK_SEQUENCE_STYLE)) > 0, -1);

    for (i = 0; i < cfg->number; i++)
    {
        CHK_ERR((item = store_icon_cfg(doc, &cfg->icon[i])) > 0, -1);
        CHK_ERR(yaml_document_append_sequence_item(doc, seq, item) > 0, -1);
    }

    return seq;
}

/**
 * @brief   Store view-manager configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     View-manager configuration
 *
 * @return              Positive node ID on success
 */
static int store_vm_cfg(yaml_document_t *doc, cfg_vm_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-view", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_scv_mesh_cfg(doc, &cfg->front_view)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-wide-view", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_scv_mesh_cfg(doc, &cfg->front_wide_view)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-view", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_scv_mesh_cfg(doc, &cfg->rear_view)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-sonar-view", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_scv_mesh_cfg(doc, &cfg->rear_sonar_view)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-wide-view", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_scv_mesh_cfg(doc, &cfg->rear_wide_view)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"side-view", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_mcv_mesh_cfg(doc, &cfg->side_view)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"debug-view", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_mcv_mesh_cfg(doc, &cfg->debug_view)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-stv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_stv_mesh_cfg(doc, &cfg->front_stv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-stv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_stv_mesh_cfg(doc, &cfg->rear_stv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"front-tv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_tv_mesh_cfg(doc, &cfg->front_tv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"rear-tv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_tv_mesh_cfg(doc, &cfg->rear_tv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-tv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_sonar_cfg(doc, &cfg->sonar_tv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-sv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_sonar_cfg(doc, &cfg->sonar_sv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-sc", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_sonar_cfg(doc, &cfg->sonar_sc)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-lc", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_sonar_cfg(doc, &cfg->sonar_lc)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"sonar-nc", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_sonar_cfg(doc, &cfg->sonar_nc)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-main", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_cta_cfg(doc, &cfg->cta_main)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-side", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_cta_cfg(doc, &cfg->cta_side)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-sonar", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_cta_cfg(doc, &cfg->cta_sonar)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cta-centric", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_cta_cfg(doc, &cfg->cta_centric)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"aiming-error", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_aiming_error_cfg(doc, &cfg->aiming_error)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"fadeout-duration", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->fadeout_duration)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"default-layout", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->default_layout)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"width", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->width)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"height", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_uint(doc, cfg->height)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"scale-factor", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_float(doc, cfg->scale)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}

/**
 * @brief   Store top-level configuration
 *
 * @param   doc[in]     YAML output document
 * @param   cfg[in]     Global configuration data
 *
 * @return              Positive node ID on success
 */
static int store_toplevel_cfg(yaml_document_t *doc, cfg_data_t *cfg)
{
    int     map, key, value;

    CHK_ERR((map = yaml_document_add_mapping(doc, NULL, YAML_BLOCK_MAPPING_STYLE)) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cameras", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_cameras_cfg(doc, cfg->camera, cfg->cameras_number)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"cc", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_cc_cfg(doc, &cfg->cc)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"hv", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_hv_cfg(doc, &cfg->hv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"vehicle", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vehicle_cfg(doc, &cfg->vehicle)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"car-model", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_car_model_cfg(doc, &cfg->car_model_stv)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"icons", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_icons_cfg(doc, &cfg->icons)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    CHK_ERR((key = yaml_document_add_scalar(doc, NULL, (yaml_char_t *)"view-manager", -1, YAML_PLAIN_SCALAR_STYLE)) > 0, -1);
    CHK_ERR((value = store_vm_cfg(doc, &cfg->vm)) > 0, -1);
    CHK_ERR(yaml_document_append_mapping_pair(doc, map, key, value) > 0, -1);

    return map;
}


/**
 * @brief   Configuration storing
 *
 * @param   cfg[in]     Configuration data pointer
 * @param   fname[in]   Configuration file name
 *
 * @return              Negative on failure
 */
int config_store(cfg_data_t *cfg, char *fname)
{
    yaml_emitter_t      emitter;
    yaml_document_t     doc;
    yaml_event_t        event;
    FILE               *f;
    int                 root, key, value;

    /* ...open file for writing */
    CHK_ERR(f = fopen(fname, "w"), -1);

    /* ...initialize an emitter */
    CHK_ERR(yaml_emitter_initialize(&emitter), -(errno = EBADFD));

    /* ...set output file */
    yaml_emitter_set_output_file(&emitter, f);

    /* ...initialize document */
    CHK_ERR(yaml_document_initialize(&doc, NULL, NULL, NULL, 0, 0), -(errno = EBADFD));

    /* ...create root mapping */
    if ((root = store_toplevel_cfg(&doc, cfg)) <= 0)
    {
        TRACE(ERROR, _x("failed to store configuration"));
        errno = ENOMEM;
    }
    else if (yaml_document_add_mapping(&doc, NULL, YAML_BLOCK_MAPPING_STYLE) <= 0)
    {
        TRACE(ERROR, _x("failed to store configuration"));
        errno = ENOMEM;
    }
    else
    {
        yaml_emitter_dump(&emitter, &doc);
    }

    yaml_emitter_close(&emitter);
    yaml_emitter_delete(&emitter);

    fclose(f);

    TRACE(INIT, _b("config saved into '%s'"), fname);

    return 0;
}

