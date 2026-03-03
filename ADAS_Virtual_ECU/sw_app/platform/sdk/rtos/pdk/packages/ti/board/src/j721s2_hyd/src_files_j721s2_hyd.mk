
SRCDIR += src/j721s2_hyd src/j721s2_hyd/include
INCDIR += src/j721s2_hyd src/j721s2_hyd/include

# Common source files across all platforms and cores
SRCS_COMMON += board_init.c board_lld_init.c board_clock.c board_mmr.c board_pll.c
SRCS_COMMON += board_ddr.c board_info.c board_ethernet_config.c board_utils.c board_control.c board_i2c_io_exp.c 
ifeq ($(CORE),mcu1_0)
SRCS_COMMON += board_power.c
endif
SRCS_COMMON += board_pinmux.c J721S2_pinmux_data.c
PACKAGE_SRCS_COMMON = src/j721s2_hyd/src_files_j721s2_hyd.mk
