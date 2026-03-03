#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "isp_process.h"
#include "isp_algo.h"




typedef enum
{
    TYPE_A = 0,
    TYPE_S = 1,
    TYPE_U = 2,
    TYPE_M = 3
}PARAM_TYPE; /* PRQA S 3229 */

typedef struct
{
    uint16_t val_upd[5];
    const char* name;
    uint16_t reg_val0;
    uint16_t reg_val1;
    uint16_t minv;
    uint16_t maxv;
    uint16_t val;
    uint64_t tweak_id;
}tweak_table_ui16_t;


typedef struct
{
    uint16_t val_upd[5];
    uint32_t type;
    double val;
    double minv;
    double maxv;
    uint32_t prec;
    flag_isp_cfg_t enable_bit;
    char name[256];
    char name_tab[256];
    uint32_t id;
    uint32_t p_next;
    uint32_t y;
    uint32_t x;
    uint64_t tweak_id;
    bool    checkbox;
}tweak_table_isp_t;

#define table_isp_max_sz 256

typedef tweak_table_isp_t (*tweak_table_isp_create_t)(uint32_t type, double minv, double maxv, uint32_t prec,
    uint32_t enable_bit, const char* name_tab, const char* name, uint32_t id, uint32_t x, uint32_t y, uint32_t p_next);

typedef struct
{
    tweak_table_isp_t table_isp[table_isp_max_sz];
    const tweak_table_ui16_t* table_sensor;
    uint32_t table_isp_sz;
    uint32_t table_sensor_sz;
    uint32_t tweak_established;
    tweak_table_isp_create_t create_table_func;
    ae_auto_tables_t* common_isp_auto_tables;
    uint64_t common_isp_auto_tables_tweak_handle[MAX_AE_TUNABLE_PARAMETERS_SZ];
}tweak_context_t;

bool tweak_is_established(void);

tweak_table_isp_t* tweak_get_isp_tables(uint32_t* sz);
tweak_table_ui16_t* tweak_get_sensor_tables(uint32_t* sz);
extern void tweak_init(tweak_table_isp_create_t create_table_func, ae_auto_tables_t* tables);

void tweak_context_init(tweak_context_t* context, tweak_table_isp_create_t create_table_func, ae_auto_tables_t* tables);

