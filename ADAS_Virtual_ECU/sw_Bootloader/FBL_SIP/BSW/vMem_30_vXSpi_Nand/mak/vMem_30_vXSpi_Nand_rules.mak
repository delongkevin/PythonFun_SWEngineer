############################################################################### 
# File Name  : vMem_30_vXSpi_Nand_rules.mak 
# Description: Rules makefile 
#------------------------------------------------------------------------------
# COPYRIGHT
#------------------------------------------------------------------------------
# Copyright (c) 2022 by Vector Informatik GmbH.  All rights reserved.
#------------------------------------------------------------------------------
# REVISION HISTORY
#------------------------------------------------------------------------------
# Version   Date        Author  Description
#------------------------------------------------------------------------------
# 1.00.00   2022-02-24  virskl  Initial creation.                 
#------------------------------------------------------------------------------
# TemplateVersion = 1.02
###############################################################################

# Component Files
CC_FILES_TO_BUILD       += vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_DetChecks.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL_InstanceModifier.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL_InstanceReadAccessor.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL_InstanceInitializer.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL_InstanceSectorReplacer.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL_InstanceDataRecoverer.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL_FlsCmdSequences.c \
                           vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand_LL_FlsCmdSeqExecuter.c

GENERATED_SOURCE_FILES  += $(GENDATA_DIR)\vMem_30_vXSpi_Nand_Lcfg.c

# Library Settings
LIBRARIES_TO_BUILD      += vMem_30_vXSpi_Nand
vMem_30_vXSpi_Nand_FILES   =  vMem_30_vXSpi_Nand$(BSW_SRC_DIR)\vMem_30_vXSpi_Nand.c
