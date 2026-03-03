#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>

#include "ser_camera.h"
#include "md_tools.h"

#ifdef j721s2_hyd
#include <ti/board/src/j721s2_hyd/include/board_internal.h>
#endif

extern int appCliPrintf(__const char *__restrict __format, ...);

/******************************************************************************
 * Sub commands
******************************************************************************/

static char md_help_text[] =
    "md get reg            - get register values\n"
    "md set reg val        - set register values\n"
    "md dump [start] [end] [holes_mask] - dump soc registers\n"
    ;

static int32_t md_tools_help(int argc, char *argv[])
{
    appCliPrintf("md command usage:\n%s\n", md_help_text);

    return 0;
}

static int32_t md_set(int argc, char *argv[])
{
    int32_t ret;
    uint32_t  reg;
    uint32_t val;
    int32_t reg_len, val_len;

    if (argc != 2) {
        appCliPrintf("No enough arguments!\n");
        return -1;
    }

    reg_len = hex2int_ext(argv[0], &reg);
    if (reg_len < 0) {
        appCliPrintf("Failed to parse register!\n");
        return reg_len;
    }

    val_len = hex2int_ext(argv[1], &val);
    if (val_len < 0) {
        appCliPrintf("Failed to parse value!\n");
        return val_len;
    }

    appCliPrintf("Writing soc register 0x%x value 0x%x\n", reg, val);

    Board_unlockMMR();

    ret = 0;
    CSL_REG32_WR((uintptr_t)reg, val);

    if (ret) {
        appCliPrintf("Failed %d\n", ret);
    }

    return ret;
}

static int32_t md_get(int argc, char *argv[])
{
    int32_t ret;
    uint32_t reg, val = 0;
    int32_t reg_len;

    if (argc < 1) {
        appCliPrintf("No enough arguments!\n");
        return -1;
    }

    reg_len = hex2int_ext(argv[0], &reg);
    if (reg_len < 0) {
        appCliPrintf("Failed to parse register!\n");
        return reg_len;
    }

    appCliPrintf("Reading  soc register 0x%x\n", reg);

    Board_unlockMMR();

    ret = 0;
    val = CSL_REG32_RD((uintptr_t)reg);

    if (ret) {
        appCliPrintf("Read failed %d\n", ret);
    } else {
        appCliPrintf("value 0x%08x\n", val);
    }

    return ret;
}

static int32_t md_dump(int argc, char *argv[])
{
    int i, j;
    uint32_t first = 0x100000, last = 0x100008;
    uint64_t holes_mask = 0;

    if (argc > 0) {
        (void)hex2int_ext(argv[0], &first);
        last = first;
    }
    if (argc > 1) {
        (void)hex2int_ext(argv[1], &last);
    }

    if (argc > 2) {
        (void)hex2long_ext(argv[2], &holes_mask);
    }

    if (first > last) {
        appCliPrintf("Invalid register address range 0x%x..0x%x\n", first, last);
        return -1;
    }

    appCliPrintf("Dumping soc regs range 0x%08x..0x%08x holes_mask=0x%x\n", first, last, holes_mask);

    Board_unlockMMR();

    /* TODO: fix for addresign and register sizes != byte */
    appCliPrintf("          0        4        8        c\n");
    for (i = (first & (~0x0f)); i < ((last + 15) & (~0x0f)); i += 16) {
        appCliPrintf("%08x: ", i);
        for(j = 0; j < 16 ; j+=4) {
            int32_t res;
            uint32_t val = 0;
            uint32_t reg = i + j;

            /* Skip unwanted regs */
            if (reg < first || reg > last) {
                appCliPrintf("   ");
                continue;
            }

            if (holes_mask & 1) {
                res = -1;
            } else {
                res = 0;
                val = CSL_REG32_RD((uintptr_t)reg);
            }

            holes_mask >>= 1;

            if (res < 0)
                appCliPrintf("xxxxxxxx ");
            else
                appCliPrintf("%08x ", val);
        }
        appCliPrintf("\n");
    }

    return 0;
}

struct md_command_desc {
    const char *cmd;
    int32_t (*execute)(int argc, char *argv[]);
};

static const struct md_command_desc commands[] = {
    {"get", &md_get},
    {"set", &md_set},
    {"dump", &md_dump},
    {"help", &md_tools_help},
    {NULL, NULL},
};

int32_t md_tools(int argc, char *argv[])
{
    /* first arg is "md" */
    argc--;
    argv++;

    const struct md_command_desc *desc;
    for (desc = &commands[0]; desc->cmd != NULL; desc++)
    {
        if (strcmp(argv[0], desc->cmd) == 0)
        {
            return desc->execute(argc - 1, argv + 1);
        }
    }

    if (desc->cmd == NULL)
    {
        appCliPrintf("Unknown md command\n");
    }

    return -1;
}

int md_tools_complete(char *line, int cursor, int n)
{
    const struct md_command_desc *desc;
    const struct md_command_desc *proposed = NULL;
    char *space = strchr(line, ' ');
    int space_pos = -1;
    int shift;
    int len = strlen(line);

    if (space != NULL)
    {
        space_pos = space - line;
    }

    if (cursor < space_pos || space_pos < 0)
    {
        for (desc = &commands[0]; desc->cmd != NULL; desc++)
        {
            if (strncmp(line, desc->cmd, cursor) == 0)
            {
                if (proposed == NULL)
                {
                    proposed = desc;
                }
                else
                {
                    /*.. several commands found, cannot decide which one to choose */
                    proposed = NULL;
                    break;
                }
            }
        }

        if (proposed != NULL)
        {
            int insert_len = strlen(proposed->cmd) - cursor;
            shift = insert_len + 1 + 1; /*.. also a space and a terminator */
            if (len + shift >= n)
            {
                shift = n - len - 1 - 2;
            }

            char *insert_at = line + cursor;

            memmove(insert_at + shift, insert_at, shift);
            strncpy(insert_at, proposed->cmd + cursor, shift - 1);
            strncpy(insert_at + insert_len, " ", 2);

            /*.. terminate anyway */
            line[n - 1] = '\0';

            cursor += shift - 1;
        }
    }

    return cursor;
}
