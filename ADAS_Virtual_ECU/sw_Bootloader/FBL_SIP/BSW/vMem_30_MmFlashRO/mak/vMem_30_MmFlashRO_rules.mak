############################################################################### 
# File Name  : vMem_30_MmFlashRO_rules.mak 
# Description: Rules makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2021 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2018-08-13  virbka  Initial creation
# 1.01.00   2019-02-06  vircbl  Added support of component-based SIP structure
# 2.00.00   2021-12-02  virbka  Added source file for shared DET check functions.
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += vMem_30_MmFlashRO$(BSW_SRC_DIR)\vMem_30_MmFlashRO.c \
                           vMem_30_MmFlashRO$(BSW_SRC_DIR)\vMem_30_MmFlashRO_DetChecks.c \
                           vMem_30_MmFlashRO$(BSW_SRC_DIR)\vMem_30_MmFlashRO_LL.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\vMem_30_MmFlashRO_Lcfg.c
