############################################################################### 
# File Name  : Fee_30_FlexNor_rules.mak 
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
# 1.00.00   2007-06-13  visaba  Initial Version of Template (1.0)
# 1.01.00   2017-05-30  vismas  Clean-up
# 1.02.00   2019-01-22  vircbl  Added support of component-based SIP structure
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += Fee_30_FlexNor$(BSW_SRC_DIR)\Fee_30_FlexNor*.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\Fee_30_Flexor_Lcfg.c
