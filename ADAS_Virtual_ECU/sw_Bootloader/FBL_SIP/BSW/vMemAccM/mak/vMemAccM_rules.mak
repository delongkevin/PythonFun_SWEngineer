############################################################################### 
# File Name  : vMemAccM_rules.mak 
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
# 1.00.00   2018-02-08  viroto  Initial version.
# 1.01.00   2019-02-06  vircbl  Added support of component-based SIP structure.
# 2.00.00   2019-07-31  viroto  Updated version because of component major version update.
# 3.00.00   2021-05-11  virbka  Added wildcard as component was extended with new unit.
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += vMemAccM$(BSW_SRC_DIR)\vMemAccM*.c

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\vMemAccM_Lcfg.c
