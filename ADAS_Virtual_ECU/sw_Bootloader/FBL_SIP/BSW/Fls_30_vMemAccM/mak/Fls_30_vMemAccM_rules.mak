############################################################################### 
# File Name  : Fls_30_vMemAccM_rules.mak 
# Description: Rules makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2019 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2018-04-24  virbka  Initial version
# 1.00.01   2018-06-06  virbka  Correct wrong string concatination(ESCAN00099590)
# 2.00.00   2018-06-13  virbka  Update of module name (STORY-6259)
# 2.01.00   2019-02-06  vircbl  Added support of component-based SIP structure
# 3.00.00   2019-10-02  virjwa  Involve new source files added to implementation
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += Fls_30_vMemAccM$(BSW_SRC_DIR)\Fls_30_vMemAccM.c 
CC_FILES_TO_BUILD       += Fls_30_vMemAccM$(BSW_SRC_DIR)\Fls_30_vMemAccM_Job.c 
CC_FILES_TO_BUILD       += Fls_30_vMemAccM$(BSW_SRC_DIR)\Fls_30_vMemAccM_StateMachine.c
CC_FILES_TO_BUILD       += Fls_30_vMemAccM$(BSW_SRC_DIR)\Fls_30_vMemAccM_FlsAccessor.c  
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\Fls_30_vMemAccM_Lcfg.c

