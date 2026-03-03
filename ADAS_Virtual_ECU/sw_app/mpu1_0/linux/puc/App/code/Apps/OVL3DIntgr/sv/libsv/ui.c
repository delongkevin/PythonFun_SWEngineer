/*******************************************************************************
 * ui.c
 *
 * User-interface for SVS
 *
 * Copyright (c) 2021 Cogent Embedded Inc.
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

#define MODULE_TAG                      UI

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "common.h"
#include "display.h"
#include "list.h"
#include "vbo-dynarray.h"
#include "config.h"
#include "math-neon.h"
#include "ui.h"
#include "../src/util.h"

/*******************************************************************************
 * Tracing configuration
 ******************************************************************************/

TRACE_TAG(INIT, 1);
TRACE_TAG(INFO, 3);
TRACE_TAG(DEBUG, 6);

/*******************************************************************************
 * Local constants definitions
 ******************************************************************************/

/**> Total number of overlay flags (shall match config!) */
enum {
    UI_FLAG_LABEL = 0,
    UI_FLAG_EXIT = 1,
    UI_FLAG_CHECK = 2,
    UI_FLAG_NO_CAMERA_FRONT = 3,
    UI_FLAG_NO_CAMERA_LEFT = 4,
    UI_FLAG_NO_CAMERA_REAR = 5,
    UI_FLAG_NO_CAMERA_RIGHT = 6,
    UI_FLAG_THA_START = 7,
    UI_FLAG_THA_CONFIRM = 8,
    UI_FLAG_THA_MESSAGE = 9,
    UI_FLAG_THA_BTN = 10,
    UI_FLAG_TRG_AUTO = 11,
    UI_AP_BACKBTN = 12,
    UI_AP_DISCLAIMER_CORE = 13,
    UI_AP_EXITBTN_NOT_SELECTED = 14,
    UI_AP_EXITBTN_SELECTED = 15,
    UI_AP_FORWARD_LEFTBTN_NOT_SELECTED = 16,
    UI_AP_FORWARD_LEFTBTN_SELECTED = 17,
    UI_AP_FORWARD_RIGHTBTN_NOT_SELECTED = 18,
    UI_AP_FORWARD_RIGHTBTN_SELECTED = 19,
    UI_AP_FRONTINBTN_NOT_AVAIL = 20,
    UI_AP_FRONTINBTN_NOT_SELECTED = 21,
    UI_AP_FRONTINBTN_SELECTED = 22,
    UI_AP_GREY_BANNER1 = 23,
    UI_AP_GREY_BANNER2 = 24,
    UI_AP_HMI_TOP_RED = 25,
    UI_AP_HMI_BOTTOM_BLACK = 26,
    UI_AP_HMI_FULLSCREEN = 27,
    UI_AP_HMI_TOP_BLACK = 28,
    UI_AP_PARA_EXIT_CORE = 29,
    UI_AP_PARKBTN_NOT_SELECTED = 30,
    UI_AP_PARKBTN_SELECTED = 31,
    UI_AP_PARKIN_DONE = 32,
    UI_AP_PARKOUT_DONE = 33,
    UI_AP_PERP_LEFT_CORE = 34,
    UI_AP_PERP_RIGHT_CORE = 35,
    UI_AP_REARINBTN_NOT_AVAIL = 36,
    UI_AP_REARINBTN_NOT_SELECTED = 37,
    UI_AP_REARINBTN_SELECTED = 38,
    UI_AP_SCAN_KEEP_MOVING_FORWARD_TEXT = 39,
    UI_AP_SCAN_REDUCE_SPEED_TEXT = 40,
    UI_AP_SCAN_STOP_TEXT = 41,
    UI_AP_SCAN_SEARCHING_TEXT = 42,
    UI_AP_SCAN_SELECT_SPACE_TEXT = 43,
    UI_AP_SCAN_SPACE_FOUND_TEXT = 44,
    UI_AP_SCANNING_CORE = 45,
    UI_AP_BG_MAIN = 46,
    UI_AP_DYNAMIC = 47,
    UI_BACKDOOROPEN_ICON_B = 48,
    UI_LEFTDOORFRONTCLOSE_ICON_B = 49,
    UI_LEFTDOORFRONTOPEN_ICON_B = 50,
    UI_LEFTDOORREARCLOSE_ICON_B = 51,
    UI_LEFTDOORREAROPEN_ICON_B = 52,
    UI_RIGHTDOORFRONTCLOSE_ICON_B = 53,
    UI_RIGHTDOORFRONTOPEN_ICON_B = 54,
    UI_RIGHTDOORREARCLOSE_ICON_B = 55,
    UI_RIGHTDOORREAROPEN_ICON_B = 56,
    UI_ZOOM_ICON = 57,
    UI_MORE_ICON = 58,
    UI_MORE_ICON_TEXT = 59,
    BOTTOMBUTTON_TVFV = 60,
    BOTTOMBUTTON_TVRV = 61,
    BOTTOMBUTTON_RCPV = 62,
    BOTTOMBUTTON_FCPV = 63,
    BOTTOMBUTTON_BURV = 64,
    BOTTOMBUTTON_FFCV = 65,
    BOTTOMBUTTON_AUX = 66,
    UI_FLAGS_NUMBER = 67,
};




/*******************************************************************************
 * Local types definitions
 ******************************************************************************/

/**
 * @brief   Soft-button data
 */
typedef struct ui_button
{
    /**> Icon item data */
    icon_item_t     item;

    /**> Destination tile */
    int32_t*         dst;

}   ui_button_t;


typedef struct ui_button_action
{
    ui_button_t*    button;
    int32_t         action;
    uint32_t        target;
    uint32_t        back;
    uint8_t*        enable;
}   ui_button_action_t;

#define MAX_BUTTON_ON_PAGE 200

/**
 * @brief   Menu data
 */
typedef struct ui_data
{
    /**> Array of buttons */
    ui_button_t    *buttons;

    ui_button_action_t button_actions[MAX_BUTTON_ON_PAGE];
    uint32_t           button_actions_count;

    /**> Array of textures for UI files */
    GLuint         *tex;
    float32_t*      tex_scale;

    /**> Current page id */
    int32_t         page;

    /**> Previous page id */
    int32_t         prev_page;

    /**> Array of overlays */
    uint8_t        *ovl_enable[UI_FLAGS_NUMBER];

    ap_dynamic_slot_t* dynamic_slots;

    uint32_t       language_num_of_texture;

    char    language_update_request_name[64];

}   ui_data_t;

/*******************************************************************************
 * Local API
 ******************************************************************************/

/**
 * @brief   Find button given the display coordinates
 */
static inline ui_button_action_t * ui_find_item(ui_data_t *ui, cfg_data_t *cfg, int32_t x, int32_t y)
{
    __list_t       *item;

    uint32_t buttons_on_page = ui->button_actions_count;
    uint32_t i;

    for (i = 0; i < buttons_on_page; i++)
    {
        ui_button_action_t *button_action = &ui->button_actions[i];
        ui_button_t    *button = button_action->button;
        int32_t        *dst = button->dst;
        uint32_t        id = (uint32_t)(button - ui->buttons);

        TRACE(0, _b("test-button-%d[%s]: dst=%d,%d,%d,%d, x=%d,y=%d"), id, cfg->ui.buttons[id].id, dst[0], dst[1], dst[2], dst[3], x, y);

        /* ...skip invisible button */
        if (button_action->enable && *button_action->enable != button_action->target)
        {
            continue;
        }

        if ((!button_action->enable || *button_action->enable) && button_action->action >= 0)
        {
            /* ...check if touchpoint gets into button tile */
            if (x >= dst[0] && x <= dst[2] && y >= dst[1] && y <= dst[3])
            {
                return button_action;
            }
        }
    }

    return NULL;
}

#ifdef BUILD_NATIVE
/**
 * @brief   Process button state change
 *
 * @param   ui[in]          UI data
 * @param   cfg[in]         Global configuration data
 * @param   x[in]           Touch X-coordinate, pixels
 * @param   y[in]           Touch Y-coordinate, pixels
 * @param   id[out]         Pressed button id
 * @param   state[out]      New button state
 *
 * @return                  Non-zero if button was pressed
 */
int ui_touch_process(ui_data_t *ui, cfg_data_t *cfg, int32_t x, int32_t y, int32_t *action)
{
    ui_button_action_t    *button = ui_find_item(ui, cfg, x, y);
    int             update = 0;

    if (button != NULL)
    {
        *action = button->action;
        update = 1;
    }

    return update;
}
#elif USE_GESTURES_FRAMEWORK
#include    <gestures/pinch.h>
#include    <gestures/tap.h>
#include    <gestures/double_tap.h>
#include    <gestures/swipe.h>

/**
 * @brief   Process button state change
 *
 * @param   ui[in]          UI data
 * @param   cfg[in]         Global configuration data
 * @param   x[in]           Touch X-coordinate, pixels
 * @param   y[in]           Touch Y-coordinate, pixels
 * @param   id[out]         Pressed button id
 * @param   state[out]      New button state
 *
 * @return                  Non-zero if button was pressed
 */
int ui_gesture_process(ui_data_t *ui, cfg_data_t *cfg, void *data, int async, int32_t *action)
{
    struct gesture_base    *base = data;
    int                     update = 0;

    if (base->type == GESTURE_TAP)
    {
        gesture_tap_t  *tap = (gesture_tap_t *)base;
        int32_t         x = tap->touch_coords.x;
        int32_t         y = tap->touch_coords.y;

        TRACE(DEBUG, _b("tap state: %u, x,y=%d,%d, async=%d"), base->state, x, y, async);

        ui_button_action_t    *button = ui_find_item(ui, cfg, x, y);
        if (button != NULL)
        {
            *action = button->action;
            update = 1;
        }
    }
    else if (base->type == GESTURE_DOUBLE_TAP)
    {
        gesture_double_tap_t  *tap = (gesture_double_tap_t *)base;
        int32_t                 x0 = tap->first_touch.x;
        int32_t                 y0 = tap->first_touch.y;
        int32_t                 x1 = tap->second_touch.x;
        int32_t                 y1 = tap->second_touch.y;

        TRACE(DEBUG, _b("dtap state: %u, x0,y0=%d,%d, x1,y1=%d,%d, async=%d"), base->state, x0, y0, x1, y1, async);
    }

    return update;
}
#else
/**
 * @brief   Process button state change
 *
 * @param   ui[in]          UI data
 * @param   x0[in]          Current touch reference position, X-coordinate
 * @param   y0[in]          Current touch reference position, Y-coordinate
 * @param   off_x[in]       Current offset from reference position, X-coordinate
 * @param   off_y[in]       Current offset from reference position, Y-coordinate
 * @param   stop[in]        Stop event reception
 * @param   action[out]     Pointer to nes page-id
 *
 * @return                  Non-zero if button was pressed
 */
int ui_input_process(ui_data_t *ui, cfg_data_t *cfg, int32_t x0, int32_t y0, int32_t off_x, int32_t off_y, uint32_t stop, int32_t *action)
{
    int     update = 0;

    if (stop != 0U)
    {
        ui_button_action_t    *button = ui_find_item(ui, cfg, x0 + off_x, y0 + off_y);

        if (button != NULL)
        {
            *action = button->action;
            update = 1;
        }
    }

    return update;
}
#endif

static void draw_dynamic_ap_overlay(ui_data_t *ui, uint32_t* rot_offset, uint8_t active, icon_item_t* item, int32_t *_dst, icon_render_t *render)
{
    ap_dynamic_slot_t* slots = ui->dynamic_slots;
    uint32_t num_slots = AP_DYNAMIC_SLOTS_NUMBER;

    if (slots == NULL)
    {
        return;
    }

    uint32_t i;

    for (i = 0; i < num_slots; i++)
    {
        ap_dynamic_slot_t* slot = &slots[i];

        int32_t dst[4];
        memcpy(dst, _dst, sizeof(dst));

        if (2 != active)
        {
            uint32_t w = dst[2] - dst[0];
            uint32_t h = dst[3] - dst[1];
            *rot_offset = (h - w) / 2;
        }
        dst[0] += slot->x;
        dst[1] += slot->y;
        dst[2] += slot->x;
        dst[3] += slot->y;

        if (slot->type == CE_SLOT_NONE)
            continue;

        if (slot->type == CE_SLOT_PERP)
        {
            dst[0] += *rot_offset;
            dst[1] -= *rot_offset;
            dst[2] += *rot_offset;
            dst[3] -= *rot_offset;
        }

        if (2 == active)
        {
            icon_add_item_rot(item, dst, 0.f, NULL, 0, render);
            continue;
        }

        if (slot->active == active)
        {

            icon_add_item_rot(item, dst, (slot->type == CE_SLOT_PARALLEL) ? 0.0f : M_PI_2, NULL, 0, render);
        }
    }
}


/**
 * @brief   Render-list update function
 *
 * @param   menu[in]            Menu data
 * @param   icon[in]            Icon data
 * @param   render[in]          Icons renderlist
 *
 * @return                      Negative on failure
 */
int ui_update(ui_data_t *ui, icon_render_t *render, icon_render_t *render2 )
{
    if (ui->language_num_of_texture && ui->language_update_request_name[0])
    {
        const char* name = ui->language_update_request_name;

        uint32_t indx = ui->language_num_of_texture - 1;

        int32_t width, height;
        if (tex_upload(name, &ui->tex[indx], &width, &height, NULL) == 0)
        {
            ui->tex_scale[indx*2 + 0] = 1.0f / (float32_t)width;
            ui->tex_scale[indx*2 + 1] = 1.0f / (float32_t)height;
        }

        ui->language_update_request_name[0] = 0;
    }

    uint32_t buttons_num = ui->button_actions_count;
    uint32_t i;

    uint32_t rot_offset = 0;

    for (i = 0; i < buttons_num; i++)
    {
        ui_button_action_t *button = &ui->button_actions[i];

        if (button->enable == ui->ovl_enable[UI_AP_DYNAMIC])
        {
            draw_dynamic_ap_overlay(ui, &rot_offset, button->target - 1, &button->button->item, button->button->dst, render);
        }
        else if (!button->enable || *button->enable == button->target || (button->target == 0xff && *button->enable))
        {
            /* ...add icon to render-list */

            if (button->back == 0)
            {
                CHK_API(icon_add_item(&button->button->item, button->button->dst, render));
            }
            else
            {
                CHK_API(icon_add_item(&button->button->item, button->button->dst, render2));
            }
            TRACE(DEBUG, _b("add item-%d"), (int)(button->button - ui->buttons));
        }
    }

    return 0;
}

ui_button_action_t* push_button_action(ui_data_t *ui)
{
    if (ui->button_actions_count >= MAX_BUTTON_ON_PAGE)
    {
        TRACE(ERROR, _x("Too many buttons on the page"));
        return NULL;
    }

    ui_button_action_t *action = &ui->button_actions[ui->button_actions_count];
    memset(action, 0, sizeof(*action));
    ui->button_actions_count++;
    return action;
}

/**
 * @brief   Set UI page
 *
 * @param   ui[in]              UI data
 * @param   cfg[in]             Global configuration data
 * @param   id[in]              Page identifier
 *
 * @return                      Negative on failure
 */
int ui_set_page(ui_data_t *ui, cfg_data_t *cfg, uint32_t id)
{
    cfg_ui_page_t  *page = &cfg->ui.pages[id];
    int             i;

    /* ...clear buttons list */
    ui->button_actions_count = 0;

    /* ...sanity check */
    CHK_ERR(id < cfg->ui.pages_num, -(errno = EINVAL));

    /* ...fill buttons data */
    for (i = 0; i < page->buttons_num; i++)
    {
        cfg_ui_button_pos_t    *button = &page->buttons[i];
        ui_button_t            *item = &ui->buttons[button->id];

        ui_button_action_t* item_action = push_button_action(ui);

        item_action->button = item;
        item->dst = button->dst;

        /* ...button action */
        item_action->action = button->action;
        item_action->back = button->back;

        /* ...button control flag */
        if (button->visible && button->visible <= UI_FLAGS_NUMBER)
        {
            item_action->enable = ui->ovl_enable[button->visible - 1];
            item_action->target = button->target;
        }

        TRACE(INFO, _b("button-%u added: [%d,%d,%d,%d]"), button->id, item->dst[0], item->dst[1], item->dst[2], item->dst[3]);
    }

    TRACE(INFO, _b("page-%u selected"), id);

    return 0;
}

/**
 * @brief   Create UI menu
 *
 * @param   cfg[in]             Global configuration data
 * @param   vehicle[in]         Vehicle state data
 *
 * @return                      Menu data handle, or NULL on failure
 */
ui_data_t * ui_create(cfg_data_t *cfg, vehicle_state_t *vehicle)
{
    ui_data_t      *ui;

    /* ...allocate menu data structure */
    CHK_ERR(ui = calloc(1, sizeof(*ui)), NULL);

    /* ...allocate buttons array */
    CHK_ERR(ui->buttons = calloc(cfg->ui.buttons_num, sizeof(*ui->buttons)), NULL);

    /* ...generate textures for files */
    uint32_t        number = cfg->ui.files_num;
    uint32_t        i, k;

    /* ...generate textures */
    CHK_ERR(ui->tex = calloc(number, sizeof(*ui->tex)), NULL);
    CHK_ERR(ui->tex_scale = calloc(number, 2*sizeof(*ui->tex_scale)), NULL);

    /* ...create GL-textures */
    glGenTextures(number, ui->tex);       GLCHECK();

    /* ...build resources basing on configuration */
    for (i = 0; i < number; i++)
    {
        cfg_ui_file_t      *file = &cfg->ui.files[i];
        const char         *filename = file->file;
        int                 width = 0, height = 0;

        if (tex_upload(filename, &ui->tex[i], &width, &height, NULL) != 0)
        {
            TRACE(ERROR, _x("failed to upload image '%s': %s"), filename, strerror(errno));
            continue;
        }

        if (strstr(filename,"language-"))
        {
            ui->language_num_of_texture = i + 1;
        }

        ui->tex_scale[i*2 + 0] = 1.0f / (float32_t)width;
        ui->tex_scale[i*2 + 1] = 1.0f / (float32_t)height;

        /* ...process all individual items contained here */
        for (k = 0; k < file->number; k++)
        {
            uint32_t            idx = file->idx + k;
            ui_button_t        *button = &ui->buttons[idx];
            cfg_ui_button_t    *cfg_button = &cfg->ui.buttons[idx];

            /* ...save GL texture id */
            button->item.tex = ui->tex[i];

            /* ...in-place transform source destination to GL-space */
            button->item.src = cfg_button->src;

            button->item.scale_x = &ui->tex_scale[i*2 + 0];
            button->item.scale_y = &ui->tex_scale[i*2 + 1];
        }
    }

    /* ...calculate maximal number of views and overlays */
    for (i = 0; i < cfg->ui.pages_num; i++)
    {
        cfg_ui_page_t      *page = &cfg->ui.pages[i];
        int                 k;

        (cfg->ui.views_num < page->views_num ? cfg->ui.views_num = page->views_num : 0);

        uint32_t            ovl_num[OVL_NUMBER];
        memset(ovl_num, 0, sizeof(ovl_num));

        for (k = 0; k < page->ovl_num; k++)
        {
            cfg_ovl_t     **ovl = page->ovl[k];
            for (ovl = page->ovl[k]; *ovl != NULL; ovl++)
            {
                ovl_num[(*ovl)->type]++;
            }
        }

        for (k = 0; k < OVL_NUMBER; k++)
        {
            (cfg->ui.ovl_num[k] < ovl_num[k] ? cfg->ui.ovl_num[k] = ovl_num[k] : 0);
        }

        TRACE(INFO, _b("page-%s: views: %u, overlays: %u,%u,%u,%u"), page->id, page->views_num, ovl_num[OVL_GUIDE], ovl_num[OVL_ICON], ovl_num[OVL_CAR], ovl_num[OVL_ODO]);
    }

    ui->ovl_enable[UI_FLAG_LABEL] = &vehicle->label_enable;
    ui->ovl_enable[UI_FLAG_EXIT] = &vehicle->exit_enable;
    ui->ovl_enable[UI_FLAG_CHECK] = &vehicle->check_enable;
    ui->ovl_enable[UI_FLAG_NO_CAMERA_FRONT] = &vehicle->no_camera_enable[0];
    ui->ovl_enable[UI_FLAG_NO_CAMERA_LEFT] = &vehicle->no_camera_enable[1];
    ui->ovl_enable[UI_FLAG_NO_CAMERA_REAR] = &vehicle->no_camera_enable[2];
    ui->ovl_enable[UI_FLAG_NO_CAMERA_RIGHT] = &vehicle->no_camera_enable[3];
    ui->ovl_enable[UI_FLAG_THA_START] = &vehicle->tha_start_enable;
    ui->ovl_enable[UI_FLAG_THA_CONFIRM] = &vehicle->tha_confirm_enable;
    ui->ovl_enable[UI_FLAG_THA_MESSAGE] = &vehicle->tha_message_id;
    ui->ovl_enable[UI_FLAG_THA_BTN] = &vehicle->tha_button;
    ui->ovl_enable[UI_FLAG_TRG_AUTO] = &vehicle->trg_auto;

    ui->ovl_enable[UI_AP_BACKBTN] = &vehicle->ap.AP_BackBtn;
    ui->ovl_enable[UI_AP_DISCLAIMER_CORE] = &vehicle->ap.AP_Disclaimer_Core;
    ui->ovl_enable[UI_AP_EXITBTN_NOT_SELECTED] = &vehicle->ap.AP_ExitBtn_Not_Selected;
    ui->ovl_enable[UI_AP_EXITBTN_SELECTED] = &vehicle->ap.AP_ExitBtn_Selected;
    ui->ovl_enable[UI_AP_FORWARD_LEFTBTN_NOT_SELECTED] = &vehicle->ap.AP_Forward_LeftBtn_Not_Selected;
    ui->ovl_enable[UI_AP_FORWARD_LEFTBTN_SELECTED] = &vehicle->ap.AP_Forward_LeftBtn_Selected;
    ui->ovl_enable[UI_AP_FORWARD_RIGHTBTN_NOT_SELECTED] = &vehicle->ap.AP_Forward_RightBtn_Not_Selected;
    ui->ovl_enable[UI_AP_FORWARD_RIGHTBTN_SELECTED] = &vehicle->ap.AP_Forward_RightBtn_Selected;
    ui->ovl_enable[UI_AP_FRONTINBTN_NOT_AVAIL] = &vehicle->ap.AP_FrontInBtn_Not_Avail;
    ui->ovl_enable[UI_AP_FRONTINBTN_NOT_SELECTED] = &vehicle->ap.AP_FrontInBtn_Not_Selected;
    ui->ovl_enable[UI_AP_FRONTINBTN_SELECTED] = &vehicle->ap.AP_FrontInBtn_Selected;
    ui->ovl_enable[UI_AP_GREY_BANNER1] = &vehicle->ap.AP_Grey_Banner1;
    ui->ovl_enable[UI_AP_GREY_BANNER2] = &vehicle->ap.AP_Grey_Banner2;
    ui->ovl_enable[UI_AP_HMI_TOP_RED] = &vehicle->ap.AP_HMI_Top_red;
    ui->ovl_enable[UI_AP_HMI_BOTTOM_BLACK] = &vehicle->ap.AP_HMI_bottom_black;
    ui->ovl_enable[UI_AP_HMI_FULLSCREEN] = &vehicle->ap.AP_HMI_fullscreen;
    ui->ovl_enable[UI_AP_HMI_TOP_BLACK] = &vehicle->ap.AP_HMI_top_black;
    ui->ovl_enable[UI_AP_PARA_EXIT_CORE] = &vehicle->ap.AP_Para_Exit_Core;
    ui->ovl_enable[UI_AP_PARKBTN_NOT_SELECTED] = &vehicle->ap.AP_ParkBtn_Not_Selected;
    ui->ovl_enable[UI_AP_PARKBTN_SELECTED] = &vehicle->ap.AP_ParkBtn_Selected;
    ui->ovl_enable[UI_AP_PARKIN_DONE] = &vehicle->ap.AP_ParkIn_Done;
    ui->ovl_enable[UI_AP_PARKOUT_DONE] = &vehicle->ap.AP_Parkout_Done;
    ui->ovl_enable[UI_AP_PERP_LEFT_CORE] = &vehicle->ap.AP_Perp_Left_Core;
    ui->ovl_enable[UI_AP_PERP_RIGHT_CORE] = &vehicle->ap.AP_Perp_Right_Core;
    ui->ovl_enable[UI_AP_REARINBTN_NOT_AVAIL] = &vehicle->ap.AP_RearInBtn_Not_Avail;
    ui->ovl_enable[UI_AP_REARINBTN_NOT_SELECTED] = &vehicle->ap.AP_RearInBtn_Not_Selected;
    ui->ovl_enable[UI_AP_REARINBTN_SELECTED] = &vehicle->ap.AP_RearInBtn_Selected;
    ui->ovl_enable[UI_AP_SCAN_KEEP_MOVING_FORWARD_TEXT] = &vehicle->ap.AP_Scan_Keep_Moving_Forward_Text;
    ui->ovl_enable[UI_AP_SCAN_REDUCE_SPEED_TEXT] = &vehicle->ap.AP_Scan_Reduce_Speed_Text;
    ui->ovl_enable[UI_AP_SCAN_STOP_TEXT] = &vehicle->ap.AP_Scan_STOP_Text;
    ui->ovl_enable[UI_AP_SCAN_SEARCHING_TEXT] = &vehicle->ap.AP_Scan_Searching_Text;
    ui->ovl_enable[UI_AP_SCAN_SELECT_SPACE_TEXT] = &vehicle->ap.AP_Scan_Select_Space_Text;
    ui->ovl_enable[UI_AP_SCAN_SPACE_FOUND_TEXT] = &vehicle->ap.AP_Scan_Space_Found_Text;
    ui->ovl_enable[UI_AP_SCANNING_CORE] = &vehicle->ap.AP_Scanning_Core;
    ui->ovl_enable[UI_AP_BG_MAIN] = &vehicle->ap.AP_BG_Main;
    ui->ovl_enable[UI_AP_DYNAMIC] = &vehicle->ap.AP_dynamic;
    ui->ovl_enable[UI_BACKDOOROPEN_ICON_B] = &vehicle->ap.BackDoorOpen_Icon_b;
    ui->ovl_enable[UI_LEFTDOORFRONTCLOSE_ICON_B] = &vehicle->ap.LeftDoorFrontClose_Icon_b;
    ui->ovl_enable[UI_LEFTDOORFRONTOPEN_ICON_B] = &vehicle->ap.LeftDoorFrontOpen_Icon_b;
    ui->ovl_enable[UI_LEFTDOORREARCLOSE_ICON_B] = &vehicle->ap.LeftDoorRearClose_Icon_b;
    ui->ovl_enable[UI_LEFTDOORREAROPEN_ICON_B] = &vehicle->ap.LeftDoorRearOpen_Icon_b;
    ui->ovl_enable[UI_RIGHTDOORFRONTCLOSE_ICON_B] = &vehicle->ap.RightDoorFrontClose_Icon_b;
    ui->ovl_enable[UI_RIGHTDOORFRONTOPEN_ICON_B] = &vehicle->ap.RightDoorFrontOpen_Icon_b;
    ui->ovl_enable[UI_RIGHTDOORREARCLOSE_ICON_B] = &vehicle->ap.RightDoorRearClose_Icon_b;
    ui->ovl_enable[UI_RIGHTDOORREAROPEN_ICON_B] = &vehicle->ap.RightDoorRearOpen_Icon_b;
    ui->ovl_enable[UI_ZOOM_ICON] = &vehicle->zoom_icon;
    ui->ovl_enable[UI_MORE_ICON] = &vehicle->more_icon;
    ui->ovl_enable[UI_MORE_ICON_TEXT] = &vehicle->more_icon_text;

    ui->ovl_enable[BOTTOMBUTTON_TVFV] = &vehicle->bottombutton_tvfv;
    ui->ovl_enable[BOTTOMBUTTON_TVRV] = &vehicle->bottombutton_tvrv;
    ui->ovl_enable[BOTTOMBUTTON_RCPV] = &vehicle->bottombutton_rcpv;
    ui->ovl_enable[BOTTOMBUTTON_FCPV] = &vehicle->bottombutton_fcpv;
    ui->ovl_enable[BOTTOMBUTTON_BURV] = &vehicle->bottombutton_burv;
    ui->ovl_enable[BOTTOMBUTTON_FFCV] = &vehicle->bottombutton_ffcv;
    ui->ovl_enable[BOTTOMBUTTON_AUX] = &vehicle->bottombutton_aux;

    ui->dynamic_slots = vehicle->ap.ap_dynamic_slots;

    TRACE(INIT, _b("UI created (views: %u, overlays: %u,%u,%u,%u)"), cfg->ui.views_num, cfg->ui.ovl_num[OVL_GUIDE], cfg->ui.ovl_num[OVL_ICON], cfg->ui.ovl_num[OVL_CAR], cfg->ui.ovl_num[OVL_ODO]);

    return ui;
}



void ui_language_reload(ui_data_t* ui, const char* path_to_ktx)
{
    strncpy(ui->language_update_request_name, path_to_ktx, sizeof(ui->language_update_request_name));
}
