ifeq ($(fisker_apps_make_include), )

############################
# Library
# List of components included under fisker lib
# The components included here are built and will be part of fisker lib
############################
MagnaBaseSW_LIB_LIST =

# AddRuntime Stats
AddRuntimeStats_COMP_LIST = AddRuntimeStats
AddRuntimeStats_RELPATH = bookshelf/PerformanceStats/AddRuntimeStats/
AddRuntimeStats_PATH = $(fisker_hydra_PATH)/bookshelf/PerformanceStats/AddRuntimeStats
AddRuntimeStats_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export AddRuntimeStats_MAKEFILE
AddRuntimeStats_BOARD_DEPENDENCY = no
AddRuntimeStats_CORE_DEPENDENCY = yes
export AddRuntimeStats_COMP_LIST
export AddRuntimeStats_BOARD_DEPENDENCY
export AddRuntimeStats_CORE_DEPENDENCY
AddRuntimeStats_PKG_LIST = AddRuntimeStats
export AddRuntimeStats_PKG_LIST
AddRuntimeStats_INCLUDE = $(AddRuntimeStats_PATH)/inc
AddRuntimeStats_SOCLIST = j721s2
export AddRuntimeStats_SOCLIST
AddRuntimeStats_CORELIST = mcu2_0 mcu2_1
AddRuntimeStats_j721e_CORELIST = $(AddRuntimeStats_CORELIST)
export AddRuntimeStats_j721e_CORELIST
MagnaBaseSW_LIB_LIST += AddRuntimeStats

# Runtime Stats for 2_1 & 2_0 core
RunTimeStats_COMP_LIST = RunTimeStats
RunTimeStats_RELPATH = bookshelf/PerformanceStats/RunTimeStats/
RunTimeStats_PATH = $(fisker_hydra_PATH)/bookshelf/PerformanceStats/RunTimeStats
RunTimeStats_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export RunTimeStats_MAKEFILE
RunTimeStats_BOARD_DEPENDENCY = no
RunTimeStats_CORE_DEPENDENCY = yes
export RunTimeStats_COMP_LIST
export RunTimeStats_BOARD_DEPENDENCY
export RunTimeStats_CORE_DEPENDENCY
RunTimeStats_PKG_LIST = RunTimeStats
export RunTimeStats_PKG_LIST
RunTimeStats_INCLUDE = $(RunTimeStats_PATH)/inc
RunTimeStats_SOCLIST = j721s2
export RunTimeStats_SOCLIST
RunTimeStats_CORELIST = mcu2_0 mcu2_1
RunTimeStats_j721e_CORELIST = $(RunTimeStats_CORELIST)
export RunTimeStats_j721e_CORELIST
MagnaBaseSW_LIB_LIST += RunTimeStats

# Error Manager
errormanager_COMP_LIST = errormanager
errormanager_RELPATH = bookshelf/ErrorManager/
errormanager_PATH = $(fisker_hydra_PATH)/bookshelf/ErrorManager
errormanager_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export errormanager_MAKEFILE
errormanager_BOARD_DEPENDENCY = no
errormanager_CORE_DEPENDENCY = yes
export errormanager_COMP_LIST
export errormanager_BOARD_DEPENDENCY
export errormanager_CORE_DEPENDENCY
errormanager_PKG_LIST = errormanager
export errormanager_PKG_LIST
errormanager_INCLUDE = $(errormanager_PATH)/cfg
errormanager_INCLUDE += $(errormanager_PATH)/inc
errormanager_INCLUDE += $(errormanager_PATH)/gen
errormanager_INCLUDE += $(errormanager_PATH)/../includes
errormanager_SOCLIST = j721s2
export errormanager_SOCLIST
errormanager_CORELIST= mcu1_0 mcu2_0 mcu2_1
errormanager_j721s2_CORELIST = $(errormanager_CORELIST)
export errormanager_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += errormanager

# Degradation Manager
degmanager_COMP_LIST = degmanager
degmanager_RELPATH = bookshelf/ErrorManager/
degmanager_PATH = $(fisker_hydra_PATH)/bookshelf/ErrorManager
degmanager_MAKEFILE = -fdegmanagermake XDC_DISABLE_THUMB_MODE=yes
export degmanager_MAKEFILE
degmanager_BOARD_DEPENDENCY = no
degmanager_CORE_DEPENDENCY = yes
export degmanager_COMP_LIST
export degmanager_BOARD_DEPENDENCY
export degmanager_CORE_DEPENDENCY
degmanager_PKG_LIST = degmanager
export degmanager_PKG_LIST
degmanager_INCLUDE = $(degmanager_PATH)/cfg
degmanager_INCLUDE += $(degmanager_PATH)/inc
degmanager_INCLUDE += $(degmanager_PATH)/gen
ifeq ($(CORE),$(filter $(CORE), mcu1_0))
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/GenData/mcu1_0/Components
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/GenData/mcu1_0
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/Common/Implementation
INCDIR += $(fisker_hydra_PATH)/platform/asr/app_sip/Os/Implementation
endif
degmanager_SOCLIST = j721s2
export degmanager_SOCLIST
degmanager_CORELIST= mcu1_0
degmanager_j721s2_CORELIST = $(degmanager_CORELIST)
export degmanager_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += degmanager


signalmgr_COMP_LIST = signalmgr
signalmgr_RELPATH = bookshelf/SignalMgr/
signalmgr_PATH = $(fisker_hydra_PATH)/bookshelf/SignalMgr
signalmgr_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export signalmgr_MAKEFILE
signalmgr_BOARD_DEPENDENCY = no
signalmgr_CORE_DEPENDENCY = yes
export signalmgr_COMP_LIST
export signalmgr_BOARD_DEPENDENCY
export signalmgr_CORE_DEPENDENCY
signalmgr_PKG_LIST = signalmgr
export signalmgr_PKG_LIST
signalmgr_INCLUDE = $(signalmgr_PATH)/inc
signalmgr_INCLUDE += $(signalmgr_PATH)/cfg
signalmgr_INCLUDE += $(signalmgr_PATH)/gen
signalmgr_SOCLIST = j721s2
export signalmgr_SOCLIST
signalmgr_CORELIST=  mcu2_0 mcu2_1 
signalmgr_j721s2_CORELIST = $(signalmgr_CORELIST)
export signalmgr_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += signalmgr


# View Manager
ViewManager_COMP_LIST = ViewManager
ViewManager_RELPATH = bookshelf/magna_apps/ViewManager/
ViewManager_PATH = $(fisker_hydra_PATH)/bookshelf/magna_apps/ViewManager
ViewManager_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export ViewManager_MAKEFILE
ViewManager_BOARD_DEPENDENCY = no
ViewManager_CORE_DEPENDENCY = yes
export ViewManager_COMP_LIST
export ViewManager_BOARD_DEPENDENCY
export ViewManager_CORE_DEPENDENCY
ViewManager_PKG_LIST = ViewManager
export ViewManager_PKG_LIST
ViewManager_INCLUDE = $(ViewManager_PATH)/algo/inc
ViewManager_INCLUDE += $(ViewManager_PATH)/code
ViewManager_SOCLIST = j721s2
export ViewManager_SOCLIST
ViewManager_CORELIST= mcu2_0
ViewManager_j721s2_CORELIST = $(ViewManager_CORELIST)
export ViewManager_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += ViewManager

systemstate_manager_COMP_LIST = systemstate_manager
systemstate_manager_RELPATH = bookshelf/SSM/
systemstate_manager_PATH = $(fisker_hydra_PATH)/bookshelf/SSM
systemstate_manager_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export systemstate_manager_MAKEFILE
systemstate_manager_BOARD_DEPENDENCY = no
systemstate_manager_CORE_DEPENDENCY = yes
export systemstate_manager_COMP_LIST
export systemstate_manager_BOARD_DEPENDENCY
export systemstate_manager_CORE_DEPENDENCY
systemstate_manager_PKG_LIST = systemstate_manager
export systemstate_manager_PKG_LIST
systemstate_manager_INCLUDE = $(systemstate_manager_PATH)/inc
systemstate_manager_INCLUDE += $(systemstate_manager_PATH)/cfg
systemstate_manager_SOCLIST = j721s2
export systemstate_manager_SOCLIST
systemstate_manager_CORELIST = mcu1_0 mcu2_0 mcu2_1
systemstate_manager_j721s2_CORELIST = $(systemstate_manager_CORELIST)
export systemstate_manager_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += systemstate_manager

CalDataProvider_COMP_LIST = CalDataProvider
CalDataProvider_RELPATH = bookshelf/CalDataProvider/
CalDataProvider_PATH = $(fisker_hydra_PATH)/bookshelf/CalDataProvider
CalDataProvider_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export CalDataProvider_MAKEFILE
CalDataProvider_BOARD_DEPENDENCY = no
CalDataProvider_CORE_DEPENDENCY = yes
export CalDataProvider_COMP_LIST
export CalDataProvider_BOARD_DEPENDENCY
export CalDataProvider_CORE_DEPENDENCY
CalDataProvider_PKG_LIST = CalDataProvider
export CalDataProvider_PKG_LIST
CalDataProvider_INCLUDE = $(CalDataProvider_PATH)/inc
CalDataProvider_SOCLIST = j721s2
export CalDataProvider_SOCLIST
CalDataProvider_CORELIST = mcu1_0
CalDataProvider_CORELIST = $(CalDataProvider_CORELIST)
export CalDataProvider_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += CalDataProvider

trsc_COMP_LIST = trsc
trsc_RELPATH = bookshelf/magna_apps/trsc/
trsc_PATH = $(fisker_hydra_PATH)/bookshelf/magna_apps/trsc
trsc_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export trsc_MAKEFILE
trsc_BOARD_DEPENDENCY = no
trsc_CORE_DEPENDENCY = yes
export trsc_COMP_LIST
export trsc_BOARD_DEPENDENCY
export trsc_CORE_DEPENDENCY
trsc_PKG_LIST = trsc
export trsc_PKG_LIST
trsc_INCLUDE += $(trsc_PATH)
trsc_INCLUDE += $(trsc_PATH)/algo
trsc_INCLUDE += $(trsc_PATH)/code
trsc_SOCLIST = j721s2
export trsc_SOCLIST
trsc_INCLUDE += $(trsc_PATH)/algo/_sharedutils
trsc_CORELIST = mcu2_1
trsc_CORELIST = $(trsc_CORELIST)
export trsc_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += trsc

#Auto Park (APA, RPA with breaking, VC, full and semi auto park)
autopark_COMP_LIST = autopark
autopark_RELPATH = bookshelf/magna_apps/autopark/$(CORE)
autopark_PATH = $(fisker_hydra_PATH)/bookshelf/magna_apps/autopark
autopark_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export autopark_MAKEFILE
autopark_BOARD_DEPENDENCY = no
autopark_CORE_DEPENDENCY = yes
export autopark_COMP_LIST
export autopark_BOARD_DEPENDENCY
export autopark_CORE_DEPENDENCY
autopark_PKG_LIST = autopark
export autopark_PKG_LIST
autopark_INCLUDE += $(autopark_PATH)
autopark_INCLUDE += $(autopark_PATH)/CVADAS_AutoPark_ert_rtw/_sharedutils
autopark_INCLUDE += $(autopark_PATH)/CVADAS_AutoPark_ert_rtw/common/inc
autopark_INCLUDE += $(autopark_PATH)CVADAS_AutoPark_ert_rtw/SWC_APA
autopark_SOCLIST = j721s2
export autopark_SOCLIST
autopark_j721e_CORELIST = mcu2_1
export autopark_j721e_CORELIST
MagnaBaseSW_LIB_LIST += autopark

#THA SM VC
tha_sm_vc_COMP_LIST = tha_sm_vc
tha_sm_vc_RELPATH = bookshelf/magna_apps/tha_sm_vc/$(CORE)
tha_sm_vc_PATH = $(fisker_hydra_PATH)/bookshelf/magna_apps/tha_sm_vc
tha_sm_vc_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export tha_sm_vc_MAKEFILE
tha_sm_vc_BOARD_DEPENDENCY = no
tha_sm_vc_CORE_DEPENDENCY = yes
export tha_sm_vc_COMP_LIST
export tha_sm_vc_BOARD_DEPENDENCY
export tha_sm_vc_CORE_DEPENDENCY
tha_sm_vc_PKG_LIST = tha_sm_vc
export tha_sm_vc_PKG_LIST
tha_sm_vc_INCLUDE += $(tha_sm_vc_PATH)/algo/_sharedutils
tha_sm_vc_INCLUDE += $(tha_sm_vc_PATH)/algo/common
tha_sm_vc_SOCLIST = j721s2
export tha_sm_vc_SOCLIST
tha_sm_vc_j721s2_CORELIST = mcu2_1
export tha_sm_vc_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += tha_sm_vc

# KM Feature
KM_COMP_LIST = KM
KM_RELPATH = bookshelf/KM/
KM_PATH = $(fisker_hydra_PATH)/bookshelf/magna_apps/KM
KM_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export KM_MAKEFILE
KM_BOARD_DEPENDENCY = no
KM_CORE_DEPENDENCY = yes
export KM_COMP_LIST
export KM_BOARD_DEPENDENCY
export KM_CORE_DEPENDENCY
KM_PKG_LIST = KM
export KM_PKG_LIST
KM_INCLUDE += $(KM_PATH)/algo/common/inc/simulink
KM_INCLUDE += $(KM_PATH)/algo/common/inc
KM_INCLUDE += $(KM_PATH)/../includes
KM_SOCLIST = j721s2
export KM_SOCLIST
KM_CORELIST= mcu1_0
KM_j721s2_CORELIST = $(KM_CORELIST)
export KM_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += KM

#FOD
FOD_COMP_LIST = FOD
FOD_RELPATH = bookshelf/magna_apps/FOD/
FOD_PATH = $(fisker_hydra_PATH)/bookshelf/magna_apps/FOD
FOD_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export FOD_MAKEFILE
FOD_BOARD_DEPENDENCY = no
FOD_CORE_DEPENDENCY = yes
export FOD_COMP_LIST
export FOD_BOARD_DEPENDENCY
export FOD_CORE_DEPENDENCY
FOD_PKG_LIST = FOD
export FOD_PKG_LIST
FOD_INCLUDE += $(FOD_PATH)
FOD_INCLUDE += $(FOD_PATH)/algo/inc
FOD_INCLUDE += $(FOD_PATH)/algo/common
FOD_INCLUDE += $(FOD_PATH)/DataProvider
FOD_INCLUDE += $(FOD_PATH)/FrontObjectDetection
FOD_SOCLIST = j721s2
export FOD_SOCLIST
FOD_j721e_CORELIST = mcu2_1
export FOD_j721e_CORELIST
MagnaBaseSW_LIB_LIST += FOD

#Arbiter
Arbiter_COMP_LIST = Arbiter
Arbiter_RELPATH = bookshelf/magna_apps/Arbiter/$(CORE)
Arbiter_PATH = $(fisker_hydra_PATH)/bookshelf/magna_apps/Arbiter
Arbiter_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export Arbiter_MAKEFILE
Arbiter_BOARD_DEPENDENCY = no
Arbiter_CORE_DEPENDENCY = yes
export Arbiter_COMP_LIST
export Arbiter_BOARD_DEPENDENCY
export Arbiter_CORE_DEPENDENCY
Arbiter_PKG_LIST = Arbiter
export Arbiter_PKG_LIST
Arbiter_INCLUDE += $(Arbiter_PATH)
Arbiter_INCLUDE += $(Arbiter_PATH)/algo/inc
Arbiter_SOCLIST = j721s2
export Arbiter_SOCLIST
Arbiter_j721e_CORELIST = mcu2_1
export Arbiter_j721e_CORELIST
MagnaBaseSW_LIB_LIST += Arbiter

#FUSA
FUSA_COMP_LIST = FUSA
FUSA_RELPATH = bookshelf/FuSa
FUSA_PATH = $(fisker_hydra_PATH)/bookshelf/FuSa
FUSA_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export FUSA_MAKEFILE
FUSA_BOARD_DEPENDENCY = no
FUSA_CORE_DEPENDENCY = no
export FUSA_COMP_LIST
export FUSA_BOARD_DEPENDENCY
export FUSA_CORE_DEPENDENCY
FUSA_PKG_LIST = FUSA
export FUSA_PKG_LIST
FUSA_INCLUDE = $(FUSA_PATH)/inc
FUSA_SOCLIST = j721s2
export FUSA_SOCLIST
FUSA_CORELIST = mcu1_0
FUSA_j721s2_CORELIST = $(FUSA_CORELIST)
export FUSA_j721s2_CORELIST
MagnaBaseSW_LIB_LIST += FUSA

cpu_load_COMP_LIST = cpu_load
cpu_load_RELPATH = bookshelf/PerformanceStats/cpu_load/
cpu_load_PATH = $(fisker_hydra_PATH)/bookshelf/PerformanceStats/cpu_load
cpu_load_MAKEFILE = -fmakefile XDC_DISABLE_THUMB_MODE=yes
export cpu_load_MAKEFILE
cpu_load_BOARD_DEPENDENCY = no
cpu_load_CORE_DEPENDENCY = yes
export cpu_load_COMP_LIST
export cpu_load_BOARD_DEPENDENCY
export cpu_load_CORE_DEPENDENCY
cpu_load_PKG_LIST = cpu_load
export cpu_load_PKG_LIST
cpu_load_INCLUDE = $(cpu_load_PATH)/inc
cpu_load_SOCLIST = j721s2
export cpu_load_SOCLIST
cpu_load_CORELIST = mcu2_0 mcu2_1
cpu_load_CORELIST = $(cpu_load_CORELIST)
export cpu_load_j721e_CORELIST
MagnaBaseSW_LIB_LIST += cpu_load

MagnaBaseSW_make_include := 1

endif
