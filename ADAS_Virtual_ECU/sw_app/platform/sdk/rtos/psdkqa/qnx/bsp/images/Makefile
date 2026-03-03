ROOT_DIR := $(notdir $(CURDIR))
ifndef QCONFIG
QCONFIG=qconfig.mk
endif
include $(QCONFIG)

HOST_MKIFS := mkifs

SUFFIXES := .build .ifs .raw

export BSP_TARGET_EXTRA=$(CURDIR)/target-extra
# Always specify PSDK_QNX_PATH as path to PSDKQA: this backup path is for internal builds only
export PSDK_QNX_PATH?=../src/hardware/support/ti/j721s2/psdkqa

.PHONY: all clean

# Looks like mkifs can produce broken image if more than one instance runs in parallel
.NOTPARALLEL:

all: ifs-j721s2-magna-fca.raw ifs-j721s2-magna-fca_single_ifs_$(BOOTMODE).raw ifs-j721s2-evm-ti.raw

clean:
	$(RM_HOST) ifs-*.raw *.sym

ifs-%.raw: %.build
	$(HOST_MKIFS) -r../install -v $(MKIFSFLAGS) $^ $@

