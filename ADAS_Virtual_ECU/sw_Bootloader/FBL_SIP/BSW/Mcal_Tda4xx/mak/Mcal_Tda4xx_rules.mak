
###############################################################################
# File Name  : Mcal_Tda4xx_rules.mak                                     	  #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported  from version 3.24 .                          #
#                                                                             #
# This Template is based on AUTOSAR_BSW_MakefileInterface.doc version 0.4     #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2023 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version  Sign    Description                                   #
# ----------   -------  ------  ----------------------------------------------#
# 2017-08-31   1.00.00  virgaj  Integration of MCUSW_00_09_01_02 			  #
# 2017-11-21   1.00.01  virgaj  Added modules Can and Eth		 			  #
# 2020-04-17   1.01.00	virnid	Integration of MCUSW_01_01_00_06              #
# 2020-06-26   1.02.00	virnid	Integration of mcusw_01_02_00_x;			  #
#								Adding flash module							  #
# 2021-01-26   1.03.00  virelt	Integration of mcusw_01_03_00_x;			  #
#								Deleting Can								  #
# 2021-03-10   1.03.01  virelt	Adding Fls_Priv*.c for backward compatibility #
# 2021-08-10   1.04.00	virnid	integration of MCUSW_01_03_02_04_CONFIG		  #
# 2022-01-10   1.05.00	virelt	Integration of MCUSW_01_03_05_02_CONFIG		  #
# 2022-10-25   1.06.00  virelt  Integration of MCUSW_01_05_00_01_CONFIG,      #
#                               MCUSW_01_03_05_02_CONFIG                      #
# 2023-01-17   1.07.00  jmaier  Integration of mcusw 2.00.00/MCUSW_2_00_00_06 #
# 2023-03-15   1.08.00	virnid	Integration of MCUSW_03_00_00_06_CONFIG		  #
#									/ SDK8.6								  #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################


###############################################################
# REGISTRY
#

#Defaults for component switches
#Can be overwritten in Makefile.Project.Part.Defines
ifeq ($(MCAL_EXCLUDE_ADC),)
MCAL_EXCLUDE_ADC = 0
endif
ifeq ($(MCAL_EXCLUDE_CDD_IPC),)
MCAL_EXCLUDE_CDD_IPC = 0
endif
ifeq ($(MCAL_EXCLUDE_DIO),)
MCAL_EXCLUDE_DIO = 0
endif
ifeq ($(MCAL_EXCLUDE_ETH),)
MCAL_EXCLUDE_ETH = 0
endif
ifeq ($(MCAL_EXCLUDE_FLS),)
MCAL_EXCLUDE_FLS = 0
endif
ifeq ($(MCAL_EXCLUDE_GPT),)
MCAL_EXCLUDE_GPT = 0
endif
ifeq ($(MCAL_EXCLUDE_ICU),)
MCAL_EXCLUDE_ICU = 0
endif
ifeq ($(MCAL_EXCLUDE_MCU),)
MCAL_EXCLUDE_MCU = 0
endif
ifeq ($(MCAL_EXCLUDE_PWM),)
MCAL_EXCLUDE_PWM = 0
endif
ifeq ($(MCAL_EXCLUDE_SPI),)
MCAL_EXCLUDE_SPI = 0
endif
ifeq ($(MCAL_EXCLUDE_WDG),)
MCAL_EXCLUDE_WDG = 0
endif
ifeq ($(MCAL_EXCLUDE_EXAMPLEFILES),)
MCAL_EXCLUDE_EXAMPLEFILES = 1
endif
ifeq ($(MCAL_EXCLUDE_STUBFILES),)
MCAL_EXCLUDE_STUBFILES = 0
endif
#e.g.: LIBRARIES_TO_BUILD      +=    $(LIB_OUPUT_PATH)\vendorx_canlib1.$(LIB_FILE_SUFFIX)
LIBRARIES_TO_BUILD      +=

ifeq ($(MCAL_EXCLUDE_PDK),)
MCAL_EXCLUDE_PDK = 0
endif

# e.g.: CC_FILES_TO_BUILD       += drv\can_drv.c
						   
#Path to Mcal source and include files
MCAL_PATH = ..\ThirdParty\Mcal_Tda4xx\Supply\mcusw\mcal_drv\mcal
MCAL_SUPPLY_PATH = ..\ThirdParty\Mcal_Tda4xx\Supply
MCAL_TARGET = J721S2
PDK_PATH = ..\ThirdParty\Mcal_Tda4xx\Supply\pdk_j721s2_08_04_00_20

ADC_BASE_PATH = $(MCAL_PATH)\Adc
CDD_IPC_BASE_PATH = $(MCAL_PATH)\CddIpc
DIO_BASE_PATH = $(MCAL_PATH)\Dio
ETH_BASE_PATH = $(MCAL_PATH)\Eth
FLS_BASE_PATH = $(MCAL_PATH)\Fls
GPT_BASE_PATH = $(MCAL_PATH)\Gpt
ICU_BASE_PATH = $(MCAL_PATH)\Icu
MCU_BASE_PATH = $(MCAL_PATH)\Mcu
PWM_BASE_PATH = $(MCAL_PATH)\Pwm
SPI_BASE_PATH = $(MCAL_PATH)\Spi
WDG_BASE_PATH = $(MCAL_PATH)\Wdg

BOARD_BASE_PATH = $(MCAL_PATH)\Board

CC_INCLUDE_PATH	+=	$(MCAL_PATH)

ifneq ($(MCAL_EXCLUDE_PDK),1)
CC_INCLUDE_PATH	+=	$(PDK_PATH)\packages
endif

ifneq ($(MCAL_EXCLUDE_STUBFILES),1)
CC_INCLUDE_PATH	+=	$(MCAL_PATH)\Bsw_Stubs\AsrGnrl\inc			\
					$(MCAL_PATH)\Bsw_Stubs\MemMap\inc			\
					$(MCAL_PATH)\Bsw_Stubs\Fee\inc				\
					$(MCAL_PATH)\Bsw_Stubs\EthIf\inc   
endif

ifneq ($(MCAL_EXCLUDE_ADC),1)
CC_FILES_TO_BUILD  += $(ADC_BASE_PATH)\src\Adc*.c

CC_INCLUDE_PATH    += $(ADC_BASE_PATH)\include \
					  $(ADC_BASE_PATH)\src
					  
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Adc*.c
endif

ifneq ($(MCAL_EXCLUDE_CDD_IPC),1)
CC_FILES_TO_BUILD  += $(CDD_IPC_BASE_PATH)\src\Cdd_Ipc*.c  
#                     $(PDK_PATH)\packages\ti\osal\src\nonos\delay\v4\delay.c

CC_FILES_TO_BUILD  += $(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\src\ipc_api.c	\
						$(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\src\ipc_virtio.c	\
						$(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\src\ipc_utils.c	\
						$(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\src\ipc_mp.c		\
						$(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\src\ipc_mailbox.c
						
ifeq ($(MCAL_TARGET),J7200)
CC_FILES_TO_BUILD  += $(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\soc\V1\ipc_soc.c
endif
						
ifeq ($(MCAL_TARGET),J721E)
CC_FILES_TO_BUILD  += $(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\soc\V1\ipc_soc.c
endif

ifeq ($(MCAL_TARGET),J721S2)
CC_FILES_TO_BUILD  += $(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\soc\V2\ipc_soc.c
endif

ifeq ($(MCAL_TARGET),J784S4)
CC_FILES_TO_BUILD  += $(CDD_IPC_BASE_PATH)\ipc_baremetal_hw\soc\V3\ipc_soc.c
endif

CC_INCLUDE_PATH    += $(CDD_IPC_BASE_PATH)\include 										\
			          $(CDD_IPC_BASE_PATH)\src                      								
					
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Cdd_Ipc*.c

ASM_FILES_TO_BUILD      += 
							
endif

ifneq ($(MCAL_EXCLUDE_DIO),1)
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio.c \
						$(DIO_BASE_PATH)\src\Dio_Priv.c	\
						$(DIO_BASE_PATH)\src\Dio_Platform.c
						
ifeq ($(MCAL_TARGET),J7200)
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio_PlatformJ7200.c
endif
						
ifeq ($(MCAL_TARGET),J721E)
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio_PlatformJ721e.c
endif

ifeq ($(MCAL_TARGET),J721S2)
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio_PlatformJ721s2.c
endif

ifeq ($(MCAL_TARGET),J784S4)
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio_PlatformJ784S4.c
endif

ifeq ($(MCAL_TARGET),DRA80X)
CC_FILES_TO_BUILD  += $(DIO_BASE_PATH)\src\Dio_PlatformDra80x.c
endif

CC_INCLUDE_PATH    += $(DIO_BASE_PATH)\include \
					$(DIO_BASE_PATH)\src
					
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Dio*.c
endif

ifneq ($(MCAL_EXCLUDE_ETH),1)
CC_FILES_TO_BUILD  += $(ETH_BASE_PATH)\src\Eth.c           \
               	      $(ETH_BASE_PATH)\src\Eth_Irq.c       \
               		  $(ETH_BASE_PATH)\src\Eth_Priv.c      \
					  $(ETH_BASE_PATH)\src\Eth_Packet.c	   \
					  $(ETH_BASE_PATH)\src\Eth_IrqPacing.c

ifeq ($(MCAL_TARGET),$(filter $(MCAL_TARGET), J721E J7200 J784S4))                     
CC_FILES_TO_BUILD  += $(ETH_BASE_PATH)\src\Eth_Rpc.c           \
                      $(ETH_BASE_PATH)\src\Eth_VirtMac.c	
endif               		
					
CC_FILES_TO_BUILD  +=  $(ETH_BASE_PATH)\src\Udma\Udma*.c
               		  
CC_FILES_TO_BUILD  += $(ETH_BASE_PATH)\src\cpsw\Cpsw*.c \
     				  $(ETH_BASE_PATH)\src\csl\csl_cpsw.c \
               		  $(ETH_BASE_PATH)\src\csl\csl_cpsw_ale_9g_tblcfg.c \
               		  $(ETH_BASE_PATH)\src\csl\csl_cpgmac_sl.c \
               		  $(ETH_BASE_PATH)\src\csl\csl_mdio.c \
               		  $(ETH_BASE_PATH)\src\csl\csl_cpts.c 

CC_INCLUDE_PATH    += $(ETH_BASE_PATH)\include \
					  $(ETH_BASE_PATH)\src \
					  $(ETH_BASE_PATH)\src\cpsw\include \
                      $(ETH_BASE_PATH)\src\cpsw\include\cpsw \
					  $(ETH_BASE_PATH)\src\csl \
                      $(ETH_BASE_PATH)\src\udma
					  					  
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Eth*.c

ifneq ($(MCAL_EXCLUDE_EXAMPLEFILES),1)
CC_FILES_TO_BUILD  += $(MCAL_PATH)\examples\Eth\eth_app\utils\EthUtils.c \
						$(MCAL_PATH)\examples\utils\src\app_utils_eth*.c		\
						$(MCAL_PATH)\examples\utils\src\app_utils.c			\
						$(MCAL_PATH)\examples\utils\src\app_r5f_Pmu*.c
#						$(MCAL_PATH)\examples\Eth\eth_app\target\EthApp*.c	\

CC_INCLUDE_PATH    += $(MCAL_PATH)\examples\Eth\eth_app\utils	\
					  $(MCAL_PATH)\examples\utils				\
					  $(MCAL_PATH)\examples\utils\src

endif
endif

ifneq ($(MCAL_EXCLUDE_FLS),1)
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls.c \
						$(FLS_BASE_PATH)\src\Fls_Spi*.c \
						$(FLS_BASE_PATH)\src\Fls_Priv*.c \
						$(FLS_BASE_PATH)\src\Fls_Soc*.c \
						$(FLS_BASE_PATH)\src\Fls_Ospi*.c \
						$(FLS_BASE_PATH)\src\Fls_NOR*.c \
						$(FLS_BASE_PATH)\src\Fls_Irq*.c \
						$(FLS_BASE_PATH)\src\nor_spi*.c \
						$(FLS_BASE_PATH)\fls_hw\ospi\V0\priv\lld_ospi.c \
						$(BOARD_BASE_PATH)\flash\src\nor_spi*.c 
                        
						
ifeq ($(MCAL_TARGET),J721E)
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls_Brd_Nor_Ospi.c \
					  $(BOARD_BASE_PATH)\flash\src\Fls_Brd_Nor_Ospi.c			  
endif

ifeq ($(MCAL_TARGET),J7200)
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls_Brd_Nor_Xspi.c	\
						$(BOARD_BASE_PATH)\flash\src\Fls_Brd_Nor_Xspi.c
endif

ifeq ($(MCAL_TARGET),J721S2)
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls_Brd_Nor_Xspi.c \
					  $(BOARD_BASE_PATH)\flash\src\Fls_Brd_Nor_Xspi.c
endif

ifeq ($(MCAL_TARGET),J784S4)
CC_FILES_TO_BUILD  += $(FLS_BASE_PATH)\src\Fls_Brd_Nor_Xspi.c \
					  $(BOARD_BASE_PATH)\flash\src\Fls_Brd_Nor_Xspi.c
endif

CC_INCLUDE_PATH    += $(FLS_BASE_PATH)\include \
					  $(FLS_BASE_PATH)\src \
					  $(BOARD_BASE_PATH)\flash\inc

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Fls*.c
endif

ifneq ($(MCAL_EXCLUDE_GPT),1)
CC_FILES_TO_BUILD  += $(GPT_BASE_PATH)\src\Gpt*.c

CC_INCLUDE_PATH    += $(GPT_BASE_PATH)\include \
					$(GPT_BASE_PATH)\src	

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Gpt*.c
endif

ifneq ($(MCAL_EXCLUDE_ICU),1)
CC_FILES_TO_BUILD  += $(ICU_BASE_PATH)\src\Icu*.c \
                      $(ICU_BASE_PATH)\ecap_hw\V0\ecap.c

CC_INCLUDE_PATH    += $(ICU_BASE_PATH)\include \
					$(ICU_BASE_PATH)\src

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Icu*.c
endif

ifneq ($(MCAL_EXCLUDE_MCU),1)
CC_FILES_TO_BUILD  += $(MCU_BASE_PATH)\src\Mcu*.c

CC_INCLUDE_PATH    += $(MCU_BASE_PATH)\include \
					$(MCU_BASE_PATH)\src

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Mcu*.c
endif


ifneq ($(MCAL_EXCLUDE_PWM),1)
CC_FILES_TO_BUILD  += $(PWM_BASE_PATH)\src\Pwm*.c  \
                      $(PWM_BASE_PATH)\epwm_hw\V0\priv\lld_epwm.c \
                      $(PWM_BASE_PATH)\epwm_hw\V0_1\priv\lld_hrpwm.c \
                      $(PWM_BASE_PATH)\epwm_hw\V0_1\priv\timer.c

CC_INCLUDE_PATH    += $(PWM_BASE_PATH)\include \
					  $(PWM_BASE_PATH)\src

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Pwm*.c
endif

ifneq ($(MCAL_EXCLUDE_SPI),1)
CC_FILES_TO_BUILD  += $(SPI_BASE_PATH)\src\Spi*.c   \
                      $(SPI_BASE_PATH)\mcspi_hw\V0\mcspi.c

CC_INCLUDE_PATH    += $(SPI_BASE_PATH)\include \
					$(SPI_BASE_PATH)\src

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Spi*.c
endif

ifneq ($(MCAL_EXCLUDE_WDG),1)
CC_FILES_TO_BUILD  += $(WDG_BASE_PATH)\src\Wdg*.c

CC_INCLUDE_PATH    += $(WDG_BASE_PATH)\include \
					$(WDG_BASE_PATH)\src

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\src\Wdg*.c
endif

CPP_FILES_TO_BUILD      +=
ASM_FILES_TO_BUILD      +=

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

# e.g.:  GENERATED_SOURCE_FILES += $(GENDATA_DIR)\drv_par.c

ADDITIONAL_INCLUDES     += $(GENDATA_DIR)\include


#e.g.: COMMON_SOURCE_FILES     += $(GENDATA_DIR)\v_par.c
COMMON_SOURCE_FILES     +=

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automaticly.
# e.g.: $(<PATH>)\can_test.c
#-------------------------------------------------------------------------------------------------
MAKE_CLEAN_RULES        +=
#MAKE_GENERATE_RULES     +=
#MAKE_COMPILER_RULES     +=
#MAKE_DEBUG_RULES        +=
#MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES          +=


###############################################################
# REQUIRED   (defined in BaseMake (global.Makefile.target.make...))
#
# SSC_ROOT		(required)
# PROJECT_ROOT	(required)
#
# LIB_OUTPUT_PATH	(optional)
# OBJ_OUTPUT_PATH	(optional)
#
# OBJ_FILE_SUFFIX
# LIB_FILE_SUFFIX
#
###############################################################


###############################################################
# PROVIDE   this Section can be used to define own additional rules
#
# In vendorx_can_cfg.mak:
# Please configure the project file:
#CAN_CONFIG_FILE = $(PROJECT_ROOT)\source\network\can\my_can_config.cfg

#In vendorx_can_config :
#generate_can_config:
#$(SSC_ROOT)\core\com\can\tools\canconfiggen.exe -o $(CAN_CONFIG_FILE)


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the
# Rules-Makefile. Each author is free to create temporary
# variables or to use other resources of GNU-MAKE
#
###############################################################


