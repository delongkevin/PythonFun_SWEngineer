############################################################################### 
# File Name  : vFeeAcc_rules.mak 
# Description: Rules makefile 
#-----------------------------------------------------------------------------
# COPYRIGHT
#-----------------------------------------------------------------------------
# Copyright (c) 2020 by Vector Informatik GmbH.  All rights reserved.
#-----------------------------------------------------------------------------
# REVISION HISTORY
#-----------------------------------------------------------------------------
# Date         Version  Sign Description
# ----------   -------  ---- -------------------------------------------------
# 2019-02-25   1.00.00  Ck   Initial creation
# 2020-10-29   2.00.00  Jwa  Support Fee BUSY_INTERNAL state
#-----------------------------------------------------------------------------
# TemplateVersion = 1.01
############################################################################### 

LIBRARIES_TO_BUILD      += vFeeAcc
vFeeAcc_FILES            = vFeeAcc$(BSW_SRC_DIR)\vFeeAcc.c vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_EventProc.c vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_ForwardReq.c vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_PublicStates.c \
                           vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_StateCancelWaitFee.c vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_StateDefaultEventHandlers.c vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_StateIdle.c \
                           vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_StateWaitFee.c vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_StateWaitLock.c vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_StateWaitUnlock.c \
                           vFeeAcc$(BSW_SRC_DIR)\vFeeAcc_StateWaitFeeBusyInternal.c

CC_FILES_TO_BUILD       += $(vFeeAcc_FILES)
CPP_FILES_TO_BUILD      +=
ASM_FILES_TO_BUILD      +=


