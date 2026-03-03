/*
 *
 * Copyright (c) 2017 Texas Instruments Incorporated
 *
 * All rights reserved not granted herein.
 *
 * Limited License.
 *
 * Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
 * license under copyrights and patents it now or hereafter owns or controls to make,
 * have made, use, import, offer to sell and sell ("Utilize") this software subject to the
 * terms herein.  With respect to the foregoing patent license, such license is granted
 * solely to the extent that any such patent is necessary to Utilize the software alone.
 * The patent license shall not apply to any combinations which include this software,
 * other than combinations with devices manufactured by or for TI ("TI Devices").
 * No hardware patent is licensed hereunder.
 *
 * Redistributions must preserve existing copyright notices and reproduce this license
 * (including the above copyright notice and the disclaimer and (if applicable) source
 * code license limitations below) in the documentation and/or other materials provided
 * with the distribution
 *
 * Redistribution and use in binary form, without modification, are permitted provided
 * that the following conditions are met:
 *
 * *       No reverse engineering, decompilation, or disassembly of this software is
 * permitted with respect to any software provided in binary form.
 *
 * *       any redistribution and use are licensed by TI for use only with TI Devices.
 *
 * *       Nothing shall obligate TI to provide you with source code for the software
 * licensed and provided to you in object code.
 *
 * If software source code is provided to you, modification and redistribution of the
 * source code are permitted provided that the following conditions are met:
 *
 * *       any redistribution and use of the source code, including any resulting derivative
 * works, are licensed by TI for use only with TI Devices.
 *
 * *       any redistribution and use of any object code compiled from the source code
 * and any resulting derivative works, are licensed by TI for use only with TI Devices.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of its suppliers
 *
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * DISCLAIMER.
 *
 * THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#if defined(j721s2_evm)
#include <ti/board/src/j721s2_evm/include/board_cfg.h>
#include <ti/board/src/j721s2_evm/include/board_pinmux.h>
#include <ti/board/src/j721s2_evm/include/board_utils.h>
#include <ti/board/src/j721s2_evm/include/board_control.h>
#elif defined(j721s2_hyd)
#include <ti/board/src/j721s2_hyd/include/board_cfg.h>
#include <ti/board/src/j721s2_hyd/include/board_pinmux.h>
#include <ti/board/src/j721s2_hyd/include/board_utils.h>
#include <ti/board/src/j721s2_hyd/include/board_control.h>
#else
#error "j721s2_evm or j721s2_hyd not defined"
#endif

#include <utils/console_io/include/app_cli.h>
#include <utils/console_io/include/app_log.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <readline.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>


#define APP_CLI_MAX_SYSTEM_CMDS     (32u)
#define APP_CLI_MAX_APP_CMDS        (64u)
#define APP_CLI_MAX_APP_SUB_CMDS    (32u)
#define APP_CLI_MAX_ARGS            (32u)

typedef struct {
    
    char *cmd;
    char *desc;
    app_cli_cmd_handler_f cmd_handler;
    
    app_cli_cmd_complete_f complete_handler;
} app_cli_cmd_entry_t;

typedef struct {
    
    app_cli_init_prm_t prm;
    
    app_cli_cmd_entry_t sys_cmds[APP_CLI_MAX_SYSTEM_CMDS];
    app_cli_cmd_entry_t app_cmds[APP_CLI_MAX_APP_CMDS];
    app_cli_cmd_entry_t app_sub_cmds[APP_CLI_MAX_APP_SUB_CMDS];
    
    app_cli_cmd_entry_t *cur_app_cmd;

    uint32_t is_inside_app_cmd;
    
    struct rl_history readline_history;
} app_cli_obj_t;

static int32_t appCliSystemCmdHelp(int argc, char *argv[]);

app_cli_obj_t g_app_cli_obj;

int appCliDeviceWriteDefault(char *string, uint32_t max_size)
{
    UART_puts(string, max_size);
    
    return 0;
}

int appCliDeviceReadDefault(char *string, uint32_t max_size, uint32_t *string_size)
{
    UART_gets(string, max_size);
    string[max_size-1] = 0;
    *string_size = strlen(string);
    
    return 0;
}

int appCliPrintf(__const char *__restrict __format, ...)
{
    app_cli_obj_t *obj = &g_app_cli_obj;    
    int status = 0;
    char buf[1024u];
    
    va_list args;
    va_start(args,__format);
    vsnprintf(buf, sizeof(buf), __format, args);
    va_end(args);
    
    if(obj->prm.device_write!=NULL)
    {
        status = obj->prm.device_write(buf, sizeof(buf));
    }
    
    return status;
}

void appCliInitPrmSetDefault(app_cli_init_prm_t *prm)
{
    prm->device_write = appCliDeviceWriteDefault;
    prm->device_read = appCliDeviceReadDefault;
    snprintf(prm->cli_prompt_name, APP_CLI_MAX_PROMPT_NAME, "cli>");
}


int32_t appCliInit(app_cli_init_prm_t *prm)
{
    app_cli_obj_t *obj = &g_app_cli_obj;
    int32_t status = 0;
    uint32_t i;
    
    appLogPrintf("CLI: Init ... !!!\n");
        
    Board_initParams_t initParams;

    Board_getInitParams(&initParams);

    initParams.uartInst      = BOARD_UART2_INSTANCE;
    initParams.uartSocDomain = BOARD_SOC_DOMAIN_MAIN;

    Board_initCfg boardCfg = BOARD_INIT_UART_STDIO;// | BOARD_INIT_UNLOCK_MMR;
    Board_setInitParams(&initParams);

    status = Board_init(boardCfg);

    obj->is_inside_app_cmd = 0;
    obj->prm = *prm;
    obj->cur_app_cmd = NULL;
    
    for(i=0 ; i<APP_CLI_MAX_SYSTEM_CMDS; i++)
    {
        obj->sys_cmds[i].cmd = NULL;    
        obj->sys_cmds[i].cmd_handler = NULL;
    }
    for(i=0 ; i<APP_CLI_MAX_APP_CMDS; i++)
    {
        obj->app_cmds[i].cmd = NULL;    
        obj->app_cmds[i].cmd_handler = NULL;
    }
    for(i=0 ; i<APP_CLI_MAX_APP_SUB_CMDS; i++)
    {
        obj->app_sub_cmds[i].cmd = NULL;    
        obj->app_sub_cmds[i].cmd_handler = NULL;
    }

    appCliRegisterSystemCmd("help", "Show this help", appCliSystemCmdHelp);
    
    appLogPrintf("CLI: Init ... Done !!!\n");
    
    return status;
}

int32_t appCliDeInit()
{
    int32_t status = 0;
    
    appLogPrintf("CLI: Deinit ... !!!\n");
    
    appLogPrintf("CLI: Deinit ... Done !!!\n");
    
    return status;
}

int32_t appCliRegisterSystemCmd(char *cmd, char *desc, app_cli_cmd_handler_f cmd_handler)
{
    app_cli_obj_t *obj = &g_app_cli_obj;
    int32_t status = -1;
    uint32_t i;
    
    for(i=0 ; i<APP_CLI_MAX_SYSTEM_CMDS; i++)
    {
        if(obj->sys_cmds[i].cmd_handler==NULL)
        {
            obj->sys_cmds[i].cmd = cmd;
            obj->sys_cmds[i].desc = desc;
            obj->sys_cmds[i].cmd_handler = cmd_handler;
            status = 0;
            break;
        }
    }

    return status;
}

int32_t appCliRegisterAppCmd(char *cmd, char *desc, app_cli_cmd_handler_f cmd_handler,
                             app_cli_cmd_complete_f complete_handler)
{
    app_cli_obj_t *obj = &g_app_cli_obj;    
    int32_t status = -1;
    uint32_t i;
    
    for(i=0 ; i<APP_CLI_MAX_APP_CMDS; i++)
    {
        if(obj->app_cmds[i].cmd_handler==NULL)
        {
            obj->app_cmds[i].cmd = cmd;
            obj->app_cmds[i].desc = desc;
            obj->app_cmds[i].cmd_handler = cmd_handler;
            obj->app_cmds[i].complete_handler = complete_handler;
            status = 0;
            break;
        }
    }

    return status;
}

int32_t appCliRegisterAppSubCmd(char *cmd, char *desc, app_cli_cmd_handler_f cmd_handler)
{
    app_cli_obj_t *obj = &g_app_cli_obj;
    int32_t status = -1;
    uint32_t i;
    
    /* app sub cmd can be registered only after executing a app cmd */
    if(obj->is_inside_app_cmd)
    {
        for(i=0 ; i<APP_CLI_MAX_APP_SUB_CMDS; i++)
        {
            if(obj->app_sub_cmds[i].cmd_handler==NULL)
            {
                obj->app_sub_cmds[i].cmd = cmd;
                obj->app_sub_cmds[i].desc = desc;
                obj->app_sub_cmds[i].cmd_handler = cmd_handler;
                break;
            }
        }
    }
    return status;
}

static int32_t appCliUnRegisterAllAppSubCmds()
{
    app_cli_obj_t *obj = &g_app_cli_obj;
    int32_t status = -1;
    uint32_t i;
    
    /* app sub cmd can be registered only after executing a app cmd */
    if(obj->is_inside_app_cmd)
    {
        for(i=0 ; i<APP_CLI_MAX_APP_SUB_CMDS; i++)
        {
            obj->app_sub_cmds[i].cmd = NULL;
            obj->app_sub_cmds[i].cmd_handler = NULL;
            obj->app_sub_cmds[i].desc = NULL;
        }
        status = 0;
    }
    return status;
}

static void appCliShowCommands(app_cli_cmd_entry_t *cmds, uint32_t num)
{
    uint32_t i;
    
    for(i=0 ; i<num; i++)
    {
        if(cmds[i].cmd_handler!=NULL && cmds[i].cmd != NULL
            )
        {
            if(cmds[i].desc != NULL)
            {
                appCliPrintf("  %-32s : %s\n", cmds[i].cmd, cmds[i].desc);
            }
            else
            {
                appCliPrintf("  %-32s : No description provided !!!\n", cmds[i].cmd);
            }
        }
    }
}

static int32_t appCliSystemCmdHelp(int argc, char *argv[])
{
    app_cli_obj_t *obj = &g_app_cli_obj;

    appCliPrintf("\n");
    appCliPrintf(" Supported system commands,\n");
    appCliShowCommands(obj->sys_cmds, APP_CLI_MAX_SYSTEM_CMDS);
    appCliPrintf("  %-32s : %s\n", "exit", "Exit current application");
    appCliPrintf("\n");

    if(obj->is_inside_app_cmd && obj->cur_app_cmd != NULL && obj->cur_app_cmd->cmd != NULL)
    {
        appCliPrintf(" Supported sub-commands for [%s],\n", 
            obj->cur_app_cmd->cmd 
            );
        appCliShowCommands(obj->app_sub_cmds, APP_CLI_MAX_APP_SUB_CMDS);
    }
    else
    {
        appCliPrintf(" Supported application commands,\n");
        appCliShowCommands(obj->app_cmds, APP_CLI_MAX_APP_CMDS);
    }
    appCliPrintf("\n");
    return 0;    
}

static app_cli_cmd_entry_t *appCliSearchCmd(app_cli_cmd_entry_t *cmds, uint32_t num, char *cmd)
{
    uint32_t i;
    app_cli_cmd_entry_t *cmd_entry = NULL;
    
    for(i=0 ; i<num; i++)
    {
        if(cmds[i].cmd_handler!=NULL && cmds[i].cmd != NULL)
        {
            if(strcmp(cmds[i].cmd, cmd)==0)
            {
                cmd_entry = &cmds[i];
                break;
            }
        }
    }

    return cmd_entry;
}


static app_cli_cmd_entry_t *appCliProposeCmd(char *incomplete, int chars)
{
    app_cli_obj_t *obj = &g_app_cli_obj;
    uint32_t i;
    app_cli_cmd_entry_t *cmd_entry = NULL;
    static app_cli_cmd_entry_t duplicate = { 0 };

    app_cli_cmd_entry_t *cmds = obj->app_cmds;
    uint32_t num = APP_CLI_MAX_APP_CMDS;
    for (i = 0; i < num; i++)
    {
        if (cmds[i].cmd_handler != NULL && cmds[i].cmd != NULL)
        {
            if (strncmp(cmds[i].cmd, incomplete, chars) == 0)
            {
                if (cmd_entry == NULL)
                {
                    cmd_entry = &cmds[i];
                }
                else
                {
                    cmd_entry = &duplicate;
                    break;
                }
            }
        }
    }

    cmds = obj->sys_cmds;
    num = APP_CLI_MAX_SYSTEM_CMDS;
    for (i = 0; i < num; i++)
    {
        if (cmds[i].cmd_handler != NULL && cmds[i].cmd != NULL)
        {
            if (strncmp(cmds[i].cmd, incomplete, chars) == 0)
            {
                if (cmd_entry == NULL)
                {
                    cmd_entry = &cmds[i];
                }
                else
                {
                    cmd_entry = &duplicate;
                    break;
                }
            }
        }
    }

    if (cmd_entry == &duplicate)
    {
        /*.. TODO: offer selection for the user */
        cmd_entry = NULL;
    }

    return cmd_entry;
}

int32_t appCliCompleteCmd(char *line, int cursor, int n)
{
    app_cli_obj_t *obj = &g_app_cli_obj;
    app_cli_cmd_entry_t *cmd_entry = NULL;
    int shift;
    int len = strlen(line);

    if (cursor < len - 1)
    {
        /*.. for simplicity, we do not support [TAB] completion
            in the middle of the line.
            The rest of the code assumes that we are at the end.
            Fully-functional autocompletion is nice, but not mandatory. */
        return cursor;
    }

    int second_token_pos = -1;
    char *space = strchr(line, ' ');

    if (obj->is_inside_app_cmd != 0)
    {
        /*.. we skip first token inside the app */
        second_token_pos = 0;
    }
    else if (space != NULL)
    {
        second_token_pos = (space - line) + 1;
    }

    if (cursor + 1 < second_token_pos || second_token_pos < 0)
    {
        /*.. we are at the first token, propose a command */
        cmd_entry = appCliProposeCmd(line, cursor);

        if (cmd_entry != NULL)
        {
            int insert_len = strlen(cmd_entry->cmd) - cursor;
            shift =  insert_len + 1 + 1; /*.. also a space and a terminator */
            if (len + shift >= n)
            {
                shift = n - len - 1 - 2;
            }

            char *insert_at = line + cursor;

            memmove(insert_at + shift, insert_at, shift);
            strncpy(insert_at, cmd_entry->cmd + cursor, shift - 1);
            strncpy(insert_at + insert_len, " ", 2);

            /*.. terminate anyway */
            line[n - 1] = '\0';

            cursor += shift - 1;
        }
    }
    else
    {
        if (obj->is_inside_app_cmd != 0)
        {
            cmd_entry = obj->cur_app_cmd;
        }
        else
        {
            /*.. locate current application */
            cmd_entry = appCliProposeCmd(line, second_token_pos - 1);
        }

        if (cmd_entry != NULL)
        {
            /*.. call application's autocompletion */
            if (cmd_entry->complete_handler)
            {
                int current_cursor = cursor - second_token_pos;
                int new_cursor = cmd_entry->complete_handler(line + second_token_pos,
                                                             current_cursor,
                                                             n - second_token_pos);
                cursor += (new_cursor - current_cursor);
            }
        }
    }

    return cursor;
}

int32_t appCliExecuteCmd(int argc, char *argv[], uint32_t *is_exit)
{
    app_cli_cmd_entry_t *cmd;
    app_cli_obj_t *obj = &g_app_cli_obj;
    int32_t status = 0;
    uint32_t is_cmd_executed = 0;
    
    /* check if its a system command */
    cmd = appCliSearchCmd(obj->sys_cmds, APP_CLI_MAX_SYSTEM_CMDS, argv[0]);
    if(cmd!=NULL)
    {
        status = cmd->cmd_handler(argc, argv);
        is_cmd_executed = 1;
    }
    else
    {
        if(obj->is_inside_app_cmd==0)
        {
            /* if not inside a application, check if its a application command */
            cmd = appCliSearchCmd(obj->app_cmds, APP_CLI_MAX_APP_CMDS, argv[0]);
            if(cmd!=NULL)
            {
                obj->is_inside_app_cmd = 1;
                obj->cur_app_cmd = cmd;
                
                status = cmd->cmd_handler(argc, argv);
                
                appCliUnRegisterAllAppSubCmds();
                
                obj->is_inside_app_cmd = 0;
                obj->cur_app_cmd = NULL;
                
                is_cmd_executed = 1;
            }
        }
        else
        {
            /* inside application, search app sub commands */
            /* if not inside a application, check if its a application command */
            cmd = appCliSearchCmd(obj->app_sub_cmds, APP_CLI_MAX_APP_SUB_CMDS, argv[0]);
            if(cmd!=NULL)
            {
                status = cmd->cmd_handler(argc, argv);
                
                is_cmd_executed = 1;
            }
        }    
    }
    if(is_cmd_executed==0)
    {
        /* check if it is exit command */
        if(strcmp(argv[0],"exit")==0)
        {
            *is_exit = 1;
        }
        else
        {
            appCliPrintf(" Unknown command: %s\n", argv[0]);
        }
    }
    return status;
}

int32_t appCliShowPrompt(uint32_t *is_exit)
{
    app_cli_obj_t *obj = &g_app_cli_obj;
    int32_t status = 0;
    char*    tokenized_args[APP_CLI_MAX_ARGS];
    char*    ptr_cli_cmd;
    char     delimitter[] = " \r\n";
    uint32_t arg_index;
    uint32_t string_size;
    char buf[128u];
    char cmd_string[1024u];
        
    *is_exit = 0;    
    
    /* Demo Prompt: */
    if(obj->cur_app_cmd!=NULL && obj->cur_app_cmd->cmd != NULL)
    {
        snprintf(buf, sizeof(buf), " %s/%s $ ", obj->prm.cli_prompt_name, obj->cur_app_cmd->cmd);
    }
    else
    {
        snprintf(buf, sizeof(buf), " %s/ $ ", obj->prm.cli_prompt_name);
    }

    /* Reset the command string: */
    memset ((void *)&cmd_string[0], 0, sizeof(cmd_string));

    if(obj->prm.device_read!=NULL)
    {
        /* Read the command message */
        string_size = readline(buf, cmd_string, sizeof(cmd_string), &obj->readline_history);
    }

    /* comment lines found - ignore the whole line*/
    if (cmd_string[0]=='#') 
    {
        
    }
    else if (string_size > 0)
    {
        /* Reset all the tokenized arguments: */
        memset ((void *)&tokenized_args, 0, sizeof(tokenized_args));
        arg_index      = 0;
        ptr_cli_cmd = (char*)&cmd_string[0];
        
        /* The command has been entered we now tokenize the command message */
        while (1)
        {
            /* Tokenize the arguments: */
            tokenized_args[arg_index] = strtok(ptr_cli_cmd, delimitter);
            /* Reset the command string */
            ptr_cli_cmd = NULL;

            if (tokenized_args[arg_index] != NULL &&
                strcmp(tokenized_args[arg_index], ";") != 0)
            {
                /* Increment the argument index: */
                arg_index++;
                if (arg_index < APP_CLI_MAX_ARGS)
                {
                    continue;
                }
                else
                {
                    break;
                }
            }

            /* Were we able to tokenize the CLI command? */
            if (arg_index > 0)
            {
                status = appCliExecuteCmd(arg_index, tokenized_args, is_exit);
            }

            if (tokenized_args[arg_index] == NULL)
            {
                break;
            }
            else if (strcmp(tokenized_args[arg_index], ";") == 0)
            {
                /* Reset all the tokenized arguments, wait for next command */
                memset((void *)&tokenized_args, 0, sizeof(tokenized_args));
                arg_index = 0;
            }
        }
    }
    
    return status;
}

void appCliShowBanner(void)
{
    appCliPrintf("\n");
    appCliPrintf("Builded " __DATE__ " " __TIME__ "\n");
    appCliPrintf("\n");

    appCliPrintf("Press 'Enter' to see command line prompt. Type 'help' for list of supported commands\n");
    appCliPrintf("\n");
}
