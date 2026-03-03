#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t tweak_override_ip_address;
extern uint32_t SERV_PORT;


typedef enum
{
    config_null = 0,
    config_pvs_view_config = 1,
    config_isp_full = 2,
    config_NUM = 3,
}config_type_t;

int tweak_connect(void);
void tweak_add_layout(unsigned int width, unsigned int horizontal_vertical, const char* name);
void tweak_close(void);

void tweak_add_slider(const char* name, double minv, double maxv, double def, unsigned int precision);
void tweak_add_spinbox(const char* name, double minv, double maxv, double def, unsigned int precision);
void tweak_add_checkbox(const char* name, int def_val);
void tweak_add_button(const char* name);
void tweak_add_groupbox(const char* name, const char* desc, unsigned int def);
void tweak_add_widget(const char* name);

double tweak_get(const char* name, double defval);
void tweak_set(const char* name, double val);
double tweak_get_string(const char* name, double defval);

void tweak_on_update(const char* name);

uint64_t tweak_fopen(const char* name, const char* mode);
uint64_t tweak_fclose(uint64_t fd);
uint64_t tweak_ftell(uint64_t fd);
uint64_t tweak_fseek(uint64_t fd, int32_t offset, int32_t where);
uint64_t tweak_fwrite(uint64_t fd, uint32_t sz, void* p_data);
uint64_t tweak_fread(uint64_t fd, uint32_t sz, void* p_data);

uint64_t tweak_config_fopen(const char* name, const char* mode);
uint64_t tweak_config_fclose(uint64_t fd);
uint64_t tweak_config_add(uint32_t sz, void* p_data);

void tweak_get_file_path(char* dst, const char* mask, uint32_t read);
uint32_t tweak_json_config_read(void* p_data, uint32_t max_sz, int cfg_enum, const char* cfg_name_ver, const char* path);
uint32_t tweak_json_config_write(void* p_data, uint32_t max_sz, int cfg_enum, const char* cfg_name_ver, const char* path);

#ifdef __cplusplus
}
#endif