.PHONY: qnx_sdk copy_spl_uboot

# override the default QNX_TARGET to point to staged mirror
#QNX_TARGET=$(PSDK_QNX_PATH)/qnx/qnx710_stage/qnx7

PROFILE ?= release
BOARD ?= j721s2_hyd

ifeq ($(PROFILE), $(filter $(PROFILE),release all))
BUILD_PROFILE_QNX_O=o.le
BUILD_PROFILE_QNX_SO=so.le
BUILD_PROFILE_QNX_D=dll.le
BUILD_PROFILE_QNX_SUFFIX=
endif
ifeq ($(PROFILE), $(filter $(PROFILE),debug))
BUILD_PROFILE_QNX_O=o.le.g
BUILD_PROFILE_QNX_SO=so.le.g
BUILD_PROFILE_QNX_D=dll.le.g
BUILD_PROFILE_QNX_SUFFIX=_g
endif

ifeq ($(QNX_SDP_VERSION), 700)
  $(error SDP700 not supported)
endif

ifeq ($(BOARD),$(filter $(BOARD), j721e_evm))
  SOC = j721e
else ifeq ($(BOARD),$(filter $(BOARD), j7200_evm))
  SOC = j7200
else ifeq ($(BOARD),$(filter $(BOARD), j721s2_evm j721s2_hyd))
  SOC = j721s2
else ifeq ($(BOARD),$(filter $(BOARD), am62x_evm))
  SOC = am62x
else ifeq ($(BOARD),$(filter $(BOARD), am62a_evm))
  SOC = am62a
else ifeq ($(BOARD),$(filter $(BOARD), j784s4_evm))
  SOC = j784s4
endif

qnx_sdk:
	########################
	##### Common Stuff #####
	########################
	## create needed dirs
	mkdir -p ${QNX_FS_PATH}/boot
	mkdir -p ${QNX_FS_PATH}/bin
	mkdir -p ${QNX_FS_PATH}/etc/system/config
	mkdir -p ${QNX_FS_PATH}/lib
	mkdir -p ${QNX_FS_PATH}/lib/dll
	mkdir -p ${QNX_FS_PATH}/sbin
	mkdir -p ${QNX_FS_PATH}/usr/bin
	mkdir -p ${QNX_FS_PATH}/usr/sbin
	mkdir -p ${QNX_FS_PATH}/usr/lib
ifeq ($(SOC),$(filter $(SOC), j721e))
	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics
	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics/j721e
endif
ifeq ($(SOC),$(filter $(SOC), am62x))
	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics
	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics/am62x
endif
	mkdir -p ${QNX_FS_PATH}/tilib
	mkdir -p ${QNX_FS_PATH}/tibin
	mkdir -p ${QNX_FS_PATH}/scripts
ifeq ($(SOC),$(filter $(SOC), j721e))
	mkdir -p ${QNX_FS_PATH}/codec_test/bitstream
	mkdir -p ${QNX_FS_PATH}/codec_test/nv12
	mkdir -p ${QNX_FS_PATH}/codec_test/output
endif
#ifeq ($(SOC),$(filter $(SOC), j721s2))
#	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics
#	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics/j721s2
#endif
ifeq ($(SOC),$(filter $(SOC), j784s4))
	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics
	mkdir -p ${QNX_FS_PATH}/usr/lib/graphics/j784s4
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	mkdir -p ${QNX_FS_PATH}/tilib/firmware
	mkdir -p ${QNX_FS_PATH}/codec_test/bitstream
	mkdir -p ${QNX_FS_PATH}/codec_test/vpu/cfg
	mkdir -p ${QNX_FS_PATH}/codec_test/vpu/nv12
	mkdir -p ${QNX_FS_PATH}/codec_test/vpu/output
endif
	## Other misc QNX binaries
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/ability            ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/cat                ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/cdpub              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/chgrp              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/chmod              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/chown              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/confstr            ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/cp                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/cpio               ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/csplit             ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/dd                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/df                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/du                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/echo               ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/isend              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/isendrecv          ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/kill               ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/ksh                ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/ln                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/ls                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/mkdir              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/mount              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/mv                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/on                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/pidin              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/ps                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/pwd                ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/restart            ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/rm                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/sed                ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/sh                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/slay               ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/slog2info          ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/slogger2           ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/stty               ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/sync               ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/tar                ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/umount             ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/uname              ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/usblauncher_otg    ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/vi                 ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/waitfor            ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/ptpd_ctrl          ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/sbin/mq                ${QNX_FS_PATH}/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/sbin/mqueue            ${QNX_FS_PATH}/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/sbin/mkdosfs           ${QNX_FS_PATH}/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/sbin/ifconfig          ${QNX_FS_PATH}/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/sbin/brconfig          ${QNX_FS_PATH}/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/sbin/route             ${QNX_FS_PATH}/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/which          ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/nice           ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/coreinfo       ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/diff           ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/find           ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/grep           ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/iperf2         ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/iperf3         ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/netstat        ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/ssh            ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/ssh-keyscan    ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/ssh-agent      ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/ssh-add        ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/ssh-keygen     ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/hogs           ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/sbin/tcpdump       ${QNX_FS_PATH}/usr/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/sbin/ptpd          ${QNX_FS_PATH}/usr/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/sbin/ptpd-avb      ${QNX_FS_PATH}/usr/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/sbin/tracelogger   ${QNX_FS_PATH}/usr/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/sbin/nicinfo       ${QNX_FS_PATH}/usr/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/sbin/sshd          ${QNX_FS_PATH}/usr/sbin/
	## QNX libs
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libhiddi.so*        ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libm.so*            ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libpps.so*          ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libslog2.so*        ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmtouch-devi.so*  ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libgestures.so*     ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libcatalog.so*      ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libtracelog.so*     ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libmq.so*       ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libxml2.so*     ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libiconv.so*    ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libc++.so*      ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/librpc.so*      ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libstringsa64.so* ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libaoi.so*      ${QNX_FS_PATH}/usr/lib/
ifeq ($(SOC),$(filter $(SOC), j721e j784s4 am62x))
	######## screen package start ######
	##### Graphics support - apps
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/screencmd          ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/bin/screeninfo         ${QNX_FS_PATH}/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/sbin/screen            ${QNX_FS_PATH}/sbin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/calib-touch    ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/events         ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/egl-configs    ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/gles1-gears    ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/gles1-vsync    ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/gles2-gears    ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/gles3-gears    ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/screen-gles2-tools     ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/screenshot     ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/sharewin       ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/sw-vsync       ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/bin/win-vsync      ${QNX_FS_PATH}/usr/bin/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/sbin/mtouch        ${QNX_FS_PATH}/usr/sbin/
	##### Graphics base libraries
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/dll/libwfdcfg-sample.so    ${QNX_FS_PATH}/lib/dll/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/dll/screen-stdbuf.so       ${QNX_FS_PATH}/lib/dll/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/dll/screen-debug.so        ${QNX_FS_PATH}/lib/dll/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/dll/screen-gles1.so        ${QNX_FS_PATH}/lib/dll/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/dll/screen-gles2.so        ${QNX_FS_PATH}/lib/dll/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/dll/screen-gles2blt.so     ${QNX_FS_PATH}/lib/dll/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/dll/screen-sw.so           ${QNX_FS_PATH}/lib/dll/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmtouch-devi.so          ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmtouch-fake.so          ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmtouch-hid.so           ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmtouch-inject.so        ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libgestures.so.1           ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libscrmem.so               ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmemobj.so               ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libinputevents.so.1        ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libkalman.so.1             ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmtouch-calib.so.1       ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libscrmem.so.1             ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/lib/libmemobj.so.1             ${QNX_FS_PATH}/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libCL.so               ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libfontconfig.so       ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libfreetype.so         ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libGLESv2.so.1         ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libGLESv1_CL.so.1      ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libGLESv1_CM.so.1      ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libEGL.so.1            ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libscreen.so.1         ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libswblit.so.1         ${QNX_FS_PATH}/usr/lib/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/libWFD.so.1            ${QNX_FS_PATH}/usr/lib/
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/graphics/dummy/libWFDdummy.so  ${QNX_FS_PATH}/usr/lib/graphics/j721e/
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/graphics/j721e/*            ${QNX_FS_PATH}/usr/lib/graphics/j721e/
#else ifeq ($(SOC),$(filter $(SOC), j721s2))
#	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/graphics/j721s2/*              ${QNX_FS_PATH}/usr/lib/graphics/j721s2/
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/graphics/j784s4/*              ${QNX_FS_PATH}/usr/lib/graphics/j784s4/
else ifeq ($(SOC),$(filter $(SOC), am62x))
	cp -rfL ${QNX_TARGET}/${QNX_ARCH}/usr/lib/graphics/am62x/*    ${QNX_FS_PATH}/usr/lib/graphics/am62x/
endif
	######## screen package end ######
endif
ifeq ($(SOC),$(filter $(SOC), j721s2))

	# screen.base package
	(cd ${QNX_TARGET}/${QNX_ARCH}/ && tar cphf - \
		bin/display-adjustment \
		sbin/screen \
		usr/bin/cl10-pi \
		usr/bin/cl11-ray \
		usr/bin/clinfo \
		usr/bin/egl-configs \
		usr/bin/events \
		usr/bin/gles1-gears \
		usr/bin/gles1-vsync \
		usr/bin/gles2-gears \
		usr/bin/gles2-maze \
		usr/bin/gles2-teapot \
		usr/bin/gles3-gears \
		usr/bin/screen-gles2-tools \
		usr/bin/screenshot \
		usr/bin/sharewin \
		usr/bin/sw-vsync \
		usr/bin/vg-tiger \
		usr/bin/vkcube \
		usr/bin/vk-fsray \
		usr/bin/vk-gears \
		usr/bin/vk-maze \
		usr/bin/vk-teapot \
		usr/bin/vulkaninfo \
		usr/bin/win-vsync \
		lib/libmemobj.so.1 \
		lib/libscrmem.so.1 \
		lib/dll/libwfdcfg-sample.so \
		lib/dll/screen-debug.so \
		lib/dll/screen-gles1.so \
		lib/dll/screen-gles2blt.so \
		lib/dll/screen-gles2.so \
		lib/dll/screen-stdbuf.so \
		lib/dll/screen-sw.so \
		usr/lib/libCL.so.1 \
		usr/lib/libEGL.so.1 \
		usr/lib/libGLESv1_CL.so.1 \
		usr/lib/libGLESv1_CM.so.1 \
		usr/lib/libGLESv2.so.1 \
		usr/lib/libOpenCL.so.1 \
		usr/lib/libOpenVG.so.1 \
		usr/lib/libOpenVGU.so.1 \
		usr/lib/libscreen.so.1 \
		usr/lib/libswblit.so.1 \
		usr/lib/libvulkan.so.1 \
		usr/lib/libWFD.so.1 \
		usr/lib/graphics/vulkan/libVkLayer_api_dump.so \
		usr/lib/graphics/vulkan/libVkLayer_khronos_validation.so \
		usr/lib/graphics/vulkan/libVkLayer_MESA_overlay.so \
		usr/lib/graphics/vulkan/VkLayer_api_dump.json \
		usr/lib/graphics/vulkan/VkLayer_khronos_validation.json \
		usr/lib/graphics/vulkan/VkLayer_MESA_overlay.json \
		usr/lib/graphics/vulkan/vk_layer_settings.txt \
	) | (cd ${QNX_FS_PATH} && tar xpf -)

	# screen.board.j721s2 package
	(cd ${QNX_TARGET}/${QNX_ARCH}/ && tar cphf - \
		usr/lib/graphics/j721s2/screen-rgx-alloc.so \
		usr/lib/graphics/j721s2/graphics.conf \
		usr/lib/graphics/j721s2/libglslcompiler.so \
		usr/lib/graphics/j721s2/libIMGegl.so \
		usr/lib/graphics/j721s2/libIMGGLESv1_CM.so \
		usr/lib/graphics/j721s2/libIMGGLESv2.so \
		usr/lib/graphics/j721s2/libPVROCL.so \
		usr/lib/graphics/j721s2/libpvrSCREEN_WSEGL.so \
		usr/lib/graphics/j721s2/libsrv_km.so \
		usr/lib/graphics/j721s2/libsrv_um.so \
		usr/lib/graphics/j721s2/libufwriter.so \
		usr/lib/graphics/j721s2/libVK_IMG.so \
		usr/lib/graphics/j721s2/libWFDdummy.so \
		usr/lib/graphics/j721s2/rgx_vulkan_icd.json \
	) | (cd ${QNX_FS_PATH} && tar xpf -)

	# screen.utils package
	(cd ${QNX_TARGET}/${QNX_ARCH}/ && tar cphf - \
		bin/gltracelogger \
		bin/gltraceprinter \
		bin/screencmd \
		bin/screeninfo \
		bin/vncserv \
	) | (cd ${QNX_FS_PATH} && tar xpf -)

	# screen.img_codecs package
	(cd ${QNX_TARGET}/${QNX_ARCH}/ && tar cphf - \
		lib/dll/img_codec_bmp.so \
		lib/dll/img_codec_gif.so \
		lib/dll/img_codec_jpg.so \
		lib/dll/img_codec_pcx.so \
		lib/dll/img_codec_png.so \
		lib/dll/img_codec_sgi.so \
		lib/dll/img_codec_tga.so \
		lib/dll/img_codec_tif.so \
		lib/dll/img_codec_wbmp.so \
		lib/libimg.so.1 \
		lib/libjpeg.so.9 \
		usr/lib/libgif.so.7 \
		usr/lib/libpng16.so.16 \
		usr/lib/libtiff.so.5 \
	) | (cd ${QNX_FS_PATH} && tar xpf -)
endif
	######## ti bins & libs ######
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so                                $(QNX_FS_PATH)/tilib/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/pdk/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so                                $(QNX_FS_PATH)/tilib/libti-pdk$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so                    $(QNX_FS_PATH)/tilib/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/sciclient/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so                    $(QNX_FS_PATH)/tilib/libti-sciclient$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/udmalld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/udmalld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-udmalld$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/ipclld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/ipclld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-ipclld$(BUILD_PROFILE_QNX_SUFFIX).so.1
ifeq ($(SOC),$(filter $(SOC), am62a))
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/csirxlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/csirxlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-csirxlld$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/fvid2lld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/fvid2lld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so                      $(QNX_FS_PATH)/tilib/libti-fvid2lld$(BUILD_PROFILE_QNX_SUFFIX).so.1
endif

ifneq ($(SOC),$(filter $(SOC), am62x am62a))
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/enetlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/pdk_libs/enetlld/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so                        $(QNX_FS_PATH)/tilib/libti-enetlld$(BUILD_PROFILE_QNX_SUFFIX).so.1
endif
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/sciclient_qnx_rsmgr/aarch64/$(BUILD_PROFILE_QNX_O)/tisci-mgr$(BUILD_PROFILE_QNX_SUFFIX)                      $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/tiipc-mgr$(BUILD_PROFILE_QNX_SUFFIX)                     $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/sharedmemallocator/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/shmemallocator$(BUILD_PROFILE_QNX_SUFFIX)                  $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/tiudma-mgr$(BUILD_PROFILE_QNX_SUFFIX)                   $(QNX_FS_PATH)/tibin/
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgr/aarch64/$(BUILD_PROFILE_QNX_O)/ti-vpu-codec-mgr$(BUILD_PROFILE_QNX_SUFFIX)                         $(QNX_FS_PATH)/tibin/
endif
ifeq ($(SOC),$(filter $(SOC), j721e j7200 j721s2 j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw2g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw2g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
endif
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/driver/aarch64/$(BUILD_PROFILE_QNX_O)/vxe_enc$(BUILD_PROFILE_QNX_SUFFIX)                      $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/driver/aarch64/$(BUILD_PROFILE_QNX_O)/vxd_dec$(BUILD_PROFILE_QNX_SUFFIX)                      $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw9g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw9g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
else ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw5g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw5g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw2g-main/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw2g-main$(BUILD_PROFILE_QNX_SUFFIX).so                    $(QNX_FS_PATH)/tilib/
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/devnp/cpsw9g/aarch64/$(BUILD_PROFILE_QNX_D)/devnp-cpsw9g$(BUILD_PROFILE_QNX_SUFFIX).so                              $(QNX_FS_PATH)/tilib/
endif
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so                 $(QNX_FS_PATH)/tilib/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so                 $(QNX_FS_PATH)/tilib/libtiipc-usr$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so               $(QNX_FS_PATH)/tilib/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so               $(QNX_FS_PATH)/tilib/libtiudma-usr$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL ${PSDK_QNX_PATH}/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so          ${QNX_FS_PATH}/tilib/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL ${PSDK_QNX_PATH}/qnx/sharedmemallocator/usr/aarch64/$(BUILD_PROFILE_QNX_SO)/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so          ${QNX_FS_PATH}/tilib/libsharedmemallocator$(BUILD_PROFILE_QNX_SUFFIX).so.1
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmenc$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxe_enc-cli$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so        $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so        $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_enc$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so                       $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so                       $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/lib/aarch64/$(BUILD_PROFILE_QNX_SO)/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so                  $(QNX_FS_PATH)/tilib/libtimmdec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/cli/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so          $(QNX_FS_PATH)/tilib/libvxd_dec-cli$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/components/j721e/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so             $(QNX_FS_PATH)/tilib/omxil_comp_j7_dec$(BUILD_PROFILE_QNX_SUFFIX).so.1
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so                          $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so            $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/core/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so            $(QNX_FS_PATH)/tilib/libomxcore_j7$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/enc/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_enc$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/utility/nto/aarch64/$(BUILD_PROFILE_QNX_SO)/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libomxil_j7_utility$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/resmgrlib/aarch64/$(BUILD_PROFILE_QNX_SO)/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libvpu_usr_lib$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tivpucodec/vpulib/aarch64/$(BUILD_PROFILE_QNX_SO)/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so         $(QNX_FS_PATH)/tilib/libti-vpucodec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/components/vpu/dec/nto/aarch64/$(BUILD_PROFILE_QNX_D)/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so $(QNX_FS_PATH)/tilib/omxil_comp_vpu_dec$(BUILD_PROFILE_QNX_SUFFIX).so.1
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/firmware/wave521c_codec_fw.bin                                                                            ${QNX_FS_PATH}/tilib/firmware/wave521c_codec_fw.bin
endif
	######## ti pdk qnx test bin ######
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/ipc/ipc_test_qnx/aarch64/$(BUILD_PROFILE_QNX_O)/ipc_test$(BUILD_PROFILE_QNX_SUFFIX)                                                ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/udma/udma_memcpy_test_qnx/aarch64/$(BUILD_PROFILE_QNX_O)/udma_memcpy_testapp$(BUILD_PROFILE_QNX_SUFFIX)                            ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/sciclient/sciclient_qnx_app/aarch64/$(BUILD_PROFILE_QNX_O)/sciclient_app$(BUILD_PROFILE_QNX_SUFFIX)                                ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/sharedmemallocator/samples/sharedMemAllocator/usr/aarch64/$(BUILD_PROFILE_QNX_O)/SharedMemoryAllocatorTestApp$(BUILD_PROFILE_QNX_SUFFIX)    ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/osal/sem_test/aarch64/$(BUILD_PROFILE_QNX_O)/osal_sem_testapp$(BUILD_PROFILE_QNX_SUFFIX)                                           ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/gpio/aarch64/$(BUILD_PROFILE_QNX_O)/gpio$(BUILD_PROFILE_QNX_SUFFIX)                                                                ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/crypto/decrypt_app/aarch64/$(BUILD_PROFILE_QNX_O)/decrypt_app$(BUILD_PROFILE_QNX_SUFFIX)                                           ${QNX_FS_PATH}/tibin/
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/cpsw/ptp_test/aarch64/$(BUILD_PROFILE_QNX_O)/ptp_test$(BUILD_PROFILE_QNX_SUFFIX)                                                   ${QNX_FS_PATH}/tibin/
ifeq ($(SOC),$(filter $(SOC), am62a))
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/csirx/csirx_capture_test_qnx/aarch64/$(BUILD_PROFILE_QNX_O)/csirx_capture_testapp$(BUILD_PROFILE_QNX_SUFFIX)                       ${QNX_FS_PATH}/tibin/
endif
ifneq ($(SOC),$(filter $(SOC), am62x am62a))
	cp -rfL ${PSDK_QNX_PATH}/qnx/examples/cpsw/cpsw_test/aarch64/$(BUILD_PROFILE_QNX_O)/cpsw_test$(BUILD_PROFILE_QNX_SUFFIX)                                                 ${QNX_FS_PATH}/tibin/
endif
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/cli_test/aarch64/$(BUILD_PROFILE_QNX_O)/enc_cli_ut$(BUILD_PROFILE_QNX_SUFFIX)                        $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/encoder/test/aarch64/$(BUILD_PROFILE_QNX_O)/timmlibenc$(BUILD_PROFILE_QNX_SUFFIX)                            $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/enc/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_enc$(BUILD_PROFILE_QNX_SUFFIX)             $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/enc_performance/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_enc_p$(BUILD_PROFILE_QNX_SUFFIX)           $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/decoder/test/aarch64/$(BUILD_PROFILE_QNX_O)/timmlibdec$(BUILD_PROFILE_QNX_SUFFIX)                            $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/dec/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_dec$(BUILD_PROFILE_QNX_SUFFIX)             $(QNX_FS_PATH)/tibin/
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/decoder_test/aarch64/$(BUILD_PROFILE_QNX_O)/vpu_decoder_test$(BUILD_PROFILE_QNX_SUFFIX)                                     ${QNX_FS_PATH}/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/encoder_test/aarch64/$(BUILD_PROFILE_QNX_O)/vpu_encoder_test$(BUILD_PROFILE_QNX_SUFFIX)                                     ${QNX_FS_PATH}/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/tests/multi_inst_test/aarch64/$(BUILD_PROFILE_QNX_O)/vpu_multi_inst_test$(BUILD_PROFILE_QNX_SUFFIX)                               ${QNX_FS_PATH}/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/test/enc/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_enc$(BUILD_PROFILE_QNX_SUFFIX)                                  $(QNX_FS_PATH)/tibin/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/test/dec/nto/aarch64/$(BUILD_PROFILE_QNX_O)/omxil_video_dec$(BUILD_PROFILE_QNX_SUFFIX)                                  $(QNX_FS_PATH)/tibin/
endif
	######## ti pdk qnx test bin end ######
	######## qnx codec test files ######
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/codec_clips/nv12                                                                                              ${QNX_FS_PATH}/codec_test/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/img/qnx/OpenMAXIL/test/enc/encoder_parameters.conf                                                            $(QNX_FS_PATH)/codec_test/
endif
ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4))
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/codec_clips/bitstream                                                                                         ${QNX_FS_PATH}/codec_test/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/codec_clips/nv12                                                                                              ${QNX_FS_PATH}/codec_test/vpu/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/test_files/cfg                                                                                            ${QNX_FS_PATH}/codec_test/vpu/
	cp -rfL $(PSDK_QNX_PATH)/qnx/codec/vpu/OpenMAXIL/test/enc/encoder_parameters.conf                                                                $(QNX_FS_PATH)/codec_test/vpu/cfg/
endif
	######## qnx codec test files end ######
	######## ti pdk qnx utils ######
	cp -rfL $(PSDK_QNX_PATH)/qnx/utils/k3conf/qnx/aarch64/$(BUILD_PROFILE_QNX_O)/k3conf$(BUILD_PROFILE_QNX_SUFFIX)                                   $(QNX_FS_PATH)/tibin/
	######## ti pdk qnx utils end ######
	#### copy scripts & extra ####
ifeq ($(SOC),$(filter $(SOC), j721e))
	# This update the user.sh script which is invoked from the .build file, as well as overwriting
	# the graphics.conf that is use
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j721e.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user__dss_on_a72.sh                ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user__dss_on_r5.sh                 ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/screen/usr/lib/graphics/j721e/*    ${QNX_FS_PATH}/usr/lib/graphics/j721e/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j7200.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j721s2.sh                     ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), am62x))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_am62x.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), am62a))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_am62a.sh                      ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/user_j784s4.sh                     ${QNX_FS_PATH}/scripts/user.sh
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_usb-asix.sh       ${QNX_FS_PATH}/scripts/
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/start_qconn_with_devnp-cpsw2g.sh   ${QNX_FS_PATH}/scripts/
endif
	#### copy scripts & extra - end ####


copy_spl_uboot:
ifeq ($(SOC),$(filter $(SOC), j721e))
	###### PSDKLA SPL Boot Binaries #########
	cp ${LINUX_FS_BOOT_PATH}/tiboot3.bin                                    ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/sysfw.itb                                      ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/tispl.bin                                      ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/u-boot.img                                     ${QNX_BOOT_PATH}/
else ifeq ($(SOC),$(filter $(SOC), j721s2 j784s4 am62x am62a))
	###### PSDKLA SPL Boot Binaries #########
	cp ${LINUX_FS_BOOT_PATH}/tiboot3.bin                                    ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/tispl.bin                                      ${QNX_BOOT_PATH}/
	cp ${LINUX_FS_BOOT_PATH}/u-boot.img                                     ${QNX_BOOT_PATH}/
endif
	# Add the uEnv.txt to load the QNX-IFS
ifeq ($(SOC),$(filter $(SOC), j721e))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j721e.txt              ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), j7200))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j7200.txt              ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), j721s2))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j721s2.txt             ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), j784s4))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_j784s4.txt             ${QNX_BOOT_PATH}/uEnv.txt
else ifeq ($(SOC),$(filter $(SOC), am62x am62a))
	cp -rfL ${PSDK_QNX_PATH}/qnx/scripts/u-boot/uEnv_am62x.txt              ${QNX_BOOT_PATH}/uEnv.txt
endif
