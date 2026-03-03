############################################################################### 
# File Name  : WrapNv_rules.mak 
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
# 1.00.00   2021-04-01  visrcn  Initial commit
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += WrapNv$(BSW_SRC_DIR)\WrapNv.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\WrapNv_Cfg.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\..\Source\WrapNv_Callout_Stubs.c

# Library Settings
LIBRARIES_TO_BUILD      += WrapNv
WrapNv_FILES            += WrapNv$(BSW_SRC_DIR)\WrapNv.c