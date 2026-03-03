/*
 *
 *
 */

#include "app_common.h"
#include <unistd.h>
#include <errno.h>
#include <spawn.h>
#include <sys/wait.h>
//#include "../../../tiovx/source/isp_qnx_magna/public/cogent/cogent_api.h"

#include <ti_rpmsg_char.h>

#include "edt.h"
#include "edt_types.h"

#define MAX_ARGV_NUM 20
#define MAX_ARG_LEN 256

static char octo_cam_mask_arg[MAX_ARG_LEN];
static char octo_tpg_mask_arg[MAX_ARG_LEN];
static char gray_tpg_arg[MAX_ARG_LEN];

enum {
    CHLD_OCTO,
    CHLD_GRAY,
    CHLD_MAX,
};

static struct child
{
    pid_t   pid;
    char    *file;
    char    *argv[MAX_ARGV_NUM];
} childs[CHLD_MAX] = {
    [CHLD_OCTO] = {
       .pid = 0,
       .file = "/opt/vision_apps/vx_app_ce_octo_cam.out",
       .argv = { "vx_app_ce_octo_cam.out",
                 "--sensor_index", "0",
                 "--mask_cameras", octo_cam_mask_arg,
                 "--tpg_mask", octo_tpg_mask_arg,
                 NULL
       },
    },
    [CHLD_GRAY] = {
       .pid = 0,
       .file = "/ti_fs/vision_apps/vx_app_ce_single_gray_cam.out",
       .argv = { "vx_app_ce_single_gray_cam.out",
                 "--tpg", gray_tpg_arg,
                 NULL
       },
    },
};

extern char **environ;

void kill_child(pid_t *child_pid)
{
    int wstatus;

    if (!kill(*child_pid, SIGINT))
    {
        while (waitpid(-1, &wstatus, WNOHANG) != *child_pid)
        {
            printf("wait for child to terminate\n");
            usleep(10000);
        }
        *child_pid = 0;
    }
}

#if 0
static int print_command(char **argv)
{
    int i;

    printf("Run command: ");
    for (i = 0; argv[i]; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}
#endif

static void run_cam(edt_rpmsg_cmd_cam_t *cmd)
{
    int status;
    struct child *c_octo = &childs[CHLD_OCTO];
    struct child *c_gray = &childs[CHLD_GRAY];
    struct child *c = NULL;
    int8_t tp = -1;

    if (c_octo->pid)
    {
       kill_child(&c_octo->pid);
    }

    if (c_gray->pid)
    {
       kill_child(&c_gray->pid);
    }

    switch (cmd->cam_id)
    {
        case CAMID_RIGHT:
        case CAMID_LEFT:
        case CAMID_FRONT:
        case CAMID_REAR:
            {
                uint8_t cam_port;

                c = c_octo;
                switch (cmd->cam_tpg)
                {
                    case TPG_NONE:
                        tp = ISP_MANUFACTURING_TEST_NONE;
                        break;
                    case TPG_SOLID_WHITE:
                        tp = ISP_MANUFACTURING_SOLID_WHITE;
                        break;
                    case TPG_SOLID_RED:
                        tp = ISP_MANUFACTURING_SOLID_RED;
                        break;
                    case TPG_SOLID_GREEN:
                        tp = ISP_MANUFACTURING_SOLID_GREEN;
                        break;
                    case TPG_SOLID_BLUE:
                        tp = ISP_MANUFACTURING_SOLID_BLUE;
                        break;
                    case TPG_VERT_COL_BAR:
                        tp = ISP_MANUFACTURING_COLOR_BAR;
                        break;
                    case TPG_VERT_COL_BAR_FADE:
                        tp = ISP_MANUFACTURING_COLOR_BAR_GRADIENT;
                        break;
                    case TPG_SOLID_BLACK:
                        tp = ISP_MANUFACTURING_SOLID_BLACK;
                        break;
                    default:
                        printf("unsuppported test pattern");
                        return;
                }
                cam_port = camera_get_port_by_id(cmd->cam_id);
                snprintf(octo_cam_mask_arg, MAX_ARG_LEN, "0x%02x",
                         1 << cam_port);
                snprintf(octo_tpg_mask_arg, MAX_ARG_LEN, "0x%04x",
                         tp << (cam_port * 4));
            }
            break;
        case CAMID_S1:
            {
                c = c_octo;

                snprintf(octo_cam_mask_arg, MAX_ARG_LEN, "0xf");
                snprintf(octo_tpg_mask_arg, MAX_ARG_LEN, "0x0");
            }
            break;
        case CAMID_DMS:
            {
                c = c_gray;
                switch (cmd->cam_tpg)
                {
                    case TPG_NONE:
                        tp = ISP_MANUFACTURING_TEST_NONE;
                        break;
                    case TPG_SOLID_WHITE:
                        tp = ISP_MANUFACTURING_SOLID_WHITE;
                        break;
                    case TPG_SOLID_BLACK:
                        tp = ISP_MANUFACTURING_SOLID_BLACK;
                        break;
                    case TPG_VERT_COL_BAR:
                        tp = ISP_MANUFACTURING_COLOR_BAR;
                        break;
                    case TPG_VERT_COL_BAR_FADE:
                        tp = ISP_MANUFACTURING_COLOR_BAR_GRADIENT;
                        break;
                    case TPG_SOLID_RED:
                    case TPG_SOLID_GREEN:
                    case TPG_SOLID_BLUE:
                    default:
                        printf("unsuppported test pattern");
                        return;
                }
                snprintf(gray_tpg_arg, MAX_ARG_LEN, "0x%04x", tp);
            }
            break;
        default:
            printf("this cam (%d) could not be handled", cmd->cam_id);
    }

    if (c)
    {
        //status = print_command(c->argv);
        status = posix_spawn(&c->pid, c->file, NULL, NULL, c->argv, environ);
        if (status == 0)
        {
            printf("child pid %d\n", c->pid);
        }
        else
        {
            printf("failed to run cmd %d %s\n", status, strerror(errno));
            c->pid = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    int ret;
    rpmsg_char_dev_t *rcdev = NULL;
    uint8_t init_msg = INIT_MSG_MAGIC;

    ret = rpmsg_char_init(NULL);
    if (ret)
    {
        printf("RPMsg initialization failed: ret = %d\n", ret);
        return ret;
    }

    rcdev = rpmsg_char_open(R5F_MCU0_0, "rpmsg_chrdev", EDT_RPMSG_ENDPOINT, "rpmsg_chrdev", 0);
    if (rcdev == NULL)
    {
		printf("Can't create an endpoint device");
    }

    /* Send Init message */
    ret = write(rcdev->fd, &init_msg, INIT_MSG_LEN);
    if (ret < 0)
    {
        printf("Can't write to rpmsg endpt device: ret = %d\n", ret);
        return ret;
    }

    while(1)
    {
        edt_rpmsg_t msg;

        ret = read(rcdev->fd, &msg, sizeof(msg));
        if (ret == sizeof(msg))
        {
            switch (msg.cmd)
            {
                case CMD_CAM:
                    {
                        printf("octo_cmd:\n \tcam_id %d\n\tcam_tpg %d\n\tcam_retent %d\n",
                                msg.cam_cmd.cam_id, msg.cam_cmd.cam_tpg, msg.cam_cmd.cam_retent);
                        run_cam(&msg.cam_cmd);
                        break;
                    }
                case CMD_NULL:
                default:
                    printf("unknown cmd %d\n", msg.cmd);
            }
        }
        else
        {
            printf("RPMessage recv failed\n");
            ret = -1;
            break;
        }
    }

    rpmsg_char_close(rcdev);
    rpmsg_char_exit();

    return ret;
}
