############################################################################### 
# File Name  : vMem_30_Fls_rules.mak 
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
# 1.00.00   2018-03-16  virbmz  Initial Version of vMem_30_Fls
# 1.00.01   2018-06-08  virbmz  ESCAN00099625 VMEM_FILES shall use the component
#                               name -> vMem_30_Fls_FILES, otherwise the m.depend
#                               does not work
# 1.01.00   2019-02-06  vircbl  Added support of component-based SIP structure
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += vMem_30_Fls$(BSW_SRC_DIR)\vMem_30_Fls.c
GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\vMem_30_Fls_Lcfg.c

# Library Settings
LIBRARIES_TO_BUILD      += vMem_30_Fls
vMem_30_Fls_FILES       += vMem_30_Fls$(BSW_SRC_DIR)\vMem_30_Fls.c

