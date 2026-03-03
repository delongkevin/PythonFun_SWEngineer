#pragma once
#include "tweak.h"
#include <stdint.h>

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

#include <string.h>
#include <stdbool.h>

#define SOCKET_STRING_SIZE 800
#define SOCKET_STRING_SIZE_GRBOX_NAME 200
#define SOCKET_STRING_SIZE_GRBOX_DESC 800
#define SOCKET_DATA_SIZE (1024 - 4)

enum
{
    func_tweak_resp               = 1,
    func_tweak_add_layout         = 2,
    func_tweak_close              = 3,
    func_tweak_add_slider         = 4,
    func_tweak_add_spinbox        = 5,
    func_tweak_add_checkbox       = 6,
    func_tweak_add_groupbox       = 7,
    func_tweak_set                = 8,
    func_tweak_get                = 9,
    func_tweak_on_update          = 10,
    func_tweak_estab              = 11,
    func_tweak_estab2             = 12,
    func_tweak_fopen              = 13,
    func_tweak_fclose             = 14,
    func_tweak_fread              = 16,
    func_tweak_fwrite             = 15,
    func_tweak_fseek              = 17,
    func_tweak_ftell              = 18,
    func_tweak_echo               = 19,
    func_tweak_add_widget         = 20,
    func_tweak_config_fopen       = 21,
    func_tweak_config_fclose      = 22,
    func_tweak_config_add         = 23,
    func_tweak_get_file_path      = 24,
    func_tweak_json_config_read   = 25,
    func_tweak_json_config_write  = 26,
    func_tweak_add_button         = 27,
};


#define PORT 5944

typedef enum
{
    RecieveStatus_OK = 0,
    RecieveStatus_Failed = 1,
    RecieveStatus_Timeout = 2
}RecieveStatus;

typedef union
{
    double f64;
    uint64_t ui64;
}Answer;


typedef struct
{
    char name[SOCKET_STRING_SIZE];
} tweak_add_widget_t;

typedef struct
{
    unsigned int width;
    unsigned int horizontal_vertical;
    char name[SOCKET_STRING_SIZE];
} tweak_add_layout_t;

typedef struct
{
    char name[SOCKET_STRING_SIZE];
    double minv;
    double maxv;
    double def;
    unsigned int precision;
} tweak_add_slider_t;

typedef struct
{
    char name[SOCKET_STRING_SIZE];
    int def_val;
} tweak_add_checkbox_t;


typedef struct
{
    char name[SOCKET_STRING_SIZE_GRBOX_NAME];
    char desc[SOCKET_STRING_SIZE_GRBOX_DESC];
    uint32_t def_value;
} tweak_add_groupbox_t;

typedef struct
{
    char name[SOCKET_STRING_SIZE];
    double defval;
} tweak_get_t;

typedef struct
{
    char name[256];
    char mode[4];
} tweak_fopen_t;

typedef struct
{
    uint64_t fd;
} tweak_fclose_t;

typedef struct
{
    uint64_t fd;
    int32_t  offset;
    int32_t  where;
} tweak_fseek_t;

typedef struct
{
    uint64_t fd;
    uint32_t sz;
} tweak_fwrite_t;

typedef struct
{
    uint64_t fd;
    uint32_t sz;
} tweak_fread_t;

typedef struct
{
    char mask[256];
    uint32_t read;
} tweak_get_file_path_t;

typedef struct
{
    uint32_t max_sz;
    int32_t cfg_enum;
    char cfg_name_ver[256];
    char path[512];
} tweak_json_config_read_t;

typedef struct
{
    int32_t message_id;
    uint8_t data[SOCKET_DATA_SIZE];
}tweak_socket_data_t;


