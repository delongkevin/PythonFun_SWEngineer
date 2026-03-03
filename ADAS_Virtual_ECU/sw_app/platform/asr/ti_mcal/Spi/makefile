include $(MCUSW_INSTALL_PATH)/build/Rules.make

MODULE_NAME = spi

SRCDIR = src
INCDIR = 

# List all the external components/interfaces, whose interface header files
# need to be included for this component
INCLUDE_EXTERNAL_INTERFACES = pdk autosarBSW autosarConfig autosarCompiler
# List all the internal submodules whose interface header files
# need to be included for this module
INCLUDE_INTERNAL_INTERFACES = spi bsw_stubs

MODULE_SRC_BASE_PATH := $($(CORE)_mcal_PATH)/Spi

# Common source files and CFLAGS across all platforms and cores
SRCS_COMMON += Spi.c Spi_Priv.c Spi_Utils.c Spi_Irq.c Spi_Mcspi.c Spi_Dma.c

PACKAGE_SRCS_COMMON = .
CFLAGS_LOCAL_COMMON = $(MCUSW_CFLAGS)

# Core/SoC/platform specific source files and CFLAGS
# Example:
#   SRCS_<core/SoC/platform-name> =
#   CFLAGS_LOCAL_<core/SoC/platform-name> =

# Include common make files
ifeq ($(MAKERULEDIR), )
#Makerule path not defined, define this and assume relative path from ROOTDIR
  MAKERULEDIR := $(PDK_INSTALL_PATH)/ti/build/makerules
  export MAKERULEDIR
endif
include $(MAKERULEDIR)/common.mk

# OBJs and libraries are built by using rule defined in rules_<target>.mk
#     and need not be explicitly specified here

# Nothing beyond this point
