#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>

#include "epwm_helper.h"
#include "ser_camera.h"

extern int appCliPrintf(__const char *__restrict __format, ...);

/******************************************************************************
 * Sub commands
******************************************************************************/

static char epwm_help_text[] =
    "epwm fps [fps] - show or set current fps\n"
    "epwm duty [duty] - show or set current duty cycle in %%\n"
    ;

static int32_t epwm_tools_help(int argc, char *argv[])
{
    appCliPrintf("epwm command usage:\n%s\n", epwm_help_text);

    return 0;
}

static int32_t epwm_fps(int argc, char *argv[])
{
    int fps;
    int ret;

    /* set */
    if (argc > 0) {
        fps = atoi(argv[0]);

        if (fps > 0 && fps <= 120)
        {
            ret = ser_camera_set_fps(0xff, fps);

            if (ret != 0) {
                appCliPrintf("set camera fps error: %d\n", ret);
                return ret;
            }
        } else {
            appCliPrintf("Invalid fps specified\n");
        }
    } else {
        /* TODO */
        fps = epwm_get_fps();
        appCliPrintf("%d\n", fps);
    }

    return 0;
}

static int32_t epwm_duty(int argc, char *argv[])
{
    int duty;
    int ret;

    /* set */
    if (argc > 0)
    {
        duty = atoi(argv[0]);

        if (duty > 0 && duty <= 100)
        {
            ret = epwm_set_duty((uint8_t)duty);

            if (ret != 0)
            {
                appCliPrintf("epwm error: %d\n", ret);
                return ret;
            }
        }
        else
        {
            appCliPrintf("Invalid duty specified, specify value in %%\n");
        }
    }
    else
    {
        duty = epwm_get_duty();
        appCliPrintf("%d\n", duty);
    }

    return 0;
}

struct epwm_command_desc {
    const char *cmd;
    int32_t (*execute)(int argc, char *argv[]);
};

static const struct epwm_command_desc commands[] = {
    {"fps", &epwm_fps},
    {"duty", &epwm_duty},
    {"help", &epwm_tools_help},
    {NULL, NULL},
};

int32_t epwm_tools(int argc, char *argv[])
{
    /* first arg is "epwm" */
    argc--;
    argv++;

    const struct epwm_command_desc *desc;
    for (desc = &commands[0]; desc->cmd != NULL; desc++)
    {
        if (strcmp(argv[0], desc->cmd) == 0)
        {
            return desc->execute(argc - 1, argv + 1);
        }
    }

    if (desc->cmd == NULL)
    {
        appCliPrintf("Unknown epwm command\n");
    }

    return -1;
}

int epwm_tools_complete(char *line, int cursor, int n)
{
    const struct epwm_command_desc *desc;
    const struct epwm_command_desc *proposed = NULL;
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
