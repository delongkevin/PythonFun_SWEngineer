/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/

-e _BmBrsExcVecSecGroup_RUN_START

/**********************************************************************************************************************
 * CAUTION - DO NOT EDIT
 * -------------------------------------------------------------------------------------------------------------------
 * Never manually edit the following memory definitions in this file. Only change them in the vLinkGen configuration
 * (/MICROSAR/vLinkGen/vLinkGenMemLayout/vLinkGenMemoryRegion/vLinkGenMemoryRegionBlock) and regenerate the files.
 *********************************************************************************************************************/
MEMORY
{
  MagicFlagRegion : ORIGIN = 0x40280000 , LENGTH = 0x00000008 /* 8 Byte */
  SafeShutDownRegion : ORIGIN = 0x40280008 , LENGTH = 0x00000004 /* 4 Byte */
  FBLAuthRegion : ORIGIN = 0x4028000C , LENGTH = 0x00000002 /* 2 Byte */
  OCMCRAM_VecExc : ORIGIN = 0x41010000 , LENGTH = 0x00000200 /* 512 Byte */
  OCMCRAM_Startup_Code : ORIGIN = 0x41010200 , LENGTH = 0x00001000 /* 4 KiB */
  vHsmIpcMemory : ORIGIN = 0x41C00000 , LENGTH = 0x00000380 /* 896 Byte */
  vHsmComm_HsmReserved : ORIGIN = 0x41C00380 , LENGTH = 0x00000580 /* 1 KiB */
  vHsmComm_Host2Hsm : ORIGIN = 0x41C00900 , LENGTH = 0x00000004 /* 4 Byte */
  vHSMComm_Hsm2Host : ORIGIN = 0x41C00904 , LENGTH = 0x00000004 /* 4 Byte */
  vHsmGlobalRamBuffer (XIRW) : ORIGIN = 0x41C00908 , LENGTH = 0x00002000 /* 8 KiB */
  IPCRAM_BMStack : ORIGIN = 0x41C02910 , LENGTH = 0x00001400 /* 5 KiB */
  OCMRAM_Stack : ORIGIN = 0x41CC0000 , LENGTH = 0x00001000 /* 4 KiB */
  OCMCRAM_Common_StartupCode : ORIGIN = 0x41CC1000 , LENGTH = 0x00000800 /* 2 KiB */
  OCMCRAM_Common : ORIGIN = 0x41CC1800 , LENGTH = 0x0000A800 /* 42 KiB */
  OCMCRAM_Common_NonCache : ORIGIN = 0x41CCC000 , LENGTH = 0x00000400 /* 1024 Byte */
  OCMCRAM_Core0 : ORIGIN = 0x41CCC400 , LENGTH = 0x00000400 /* 1024 Byte */
  EthArea : ORIGIN = 0x70040000 , LENGTH = 0x00018000 /* 96 KiB */
  CddIpcArea : ORIGIN = 0x70058000 , LENGTH = 0x00068000 /* 416 KiB */
  DataBssRegion_Shared : ORIGIN = 0x700C0000 , LENGTH = 0x00000100 /* 256 Byte */
  DataBssRegion : ORIGIN = 0x700C0100 , LENGTH = 0x0005FF00 /* 384 KiB */
  BmHdrArea : ORIGIN = 0x90800000 , LENGTH = 0x00000020 /* 32 Byte */
  BmCodeConstArea : ORIGIN = 0x90800020 , LENGTH = 0x000FFFE0 /* 1024 KiB */
  FblHeaderArea : ORIGIN = 0x90900000 , LENGTH = 0x00000020 /* 32 Byte */
  FblBmHdrHeaderArea : ORIGIN = 0x90900020 , LENGTH = 0x00000020 /* 32 Byte */
  FblCodeConstArea : ORIGIN = 0x90900040 , LENGTH = 0x000FFBC0 /* 1023 KiB */
  FblLBPPArea : ORIGIN = 0x909FFC00 , LENGTH = 0x00000200 /* 512 Byte */
  FblBlockPPArea : ORIGIN = 0x909FFE00 , LENGTH = 0x00000200 /* 512 Byte */
  ApplUpdBmHdrHeaderArea : ORIGIN = 0x90A00000 , LENGTH = 0x00000020 /* 32 Byte */
  ApplUpdCodeConstArea : ORIGIN = 0x90A00020 , LENGTH = 0x003FFBE0 /* 4 MiB */
  ApplUpdBlockPPArea : ORIGIN = 0x90DFFC00 , LENGTH = 0x00000200 /* 512 Byte */
  ApplUpdLBPPArea : ORIGIN = 0x90DFFE00 , LENGTH = 0x00000200 /* 512 Byte */
}

SECTIONS
{
  .FblBmHdrHeaderSecGroup :
  {
    *(.BmHdrHeaderSection)
  } > FblBmHdrHeaderArea,
  RUN_START(_FblBmHdrHeaderSecGroup_RUN_START),
  RUN_END(_FblBmHdrHeaderSecGroup_RUN_LIMIT)

  .FblBmHdrHeaderGroup_LABELS :
  {
    _FblBmHdrHeaderSecGroup_START = _FblBmHdrHeaderSecGroup_RUN_START;
    _FblBmHdrHeaderSecGroup_LIMIT = _FblBmHdrHeaderSecGroup_RUN_LIMIT;
    _FblBmHdrHeaderSecGroup_END = _FblBmHdrHeaderSecGroup_LIMIT - 1;
    _FblBmHdrHeaderGroup_ALL_START = _FblBmHdrHeaderSecGroup_START;
    _FblBmHdrHeaderGroup_ALL_END = _FblBmHdrHeaderSecGroup_END;
    _FblBmHdrHeaderGroup_ALL_LIMIT = _FblBmHdrHeaderSecGroup_LIMIT;
  }

  .FblCodeConstSecGroup :
  {
    *(.boardcfg_data)
    *(.const*)
    *(.rodata*)
    *(.text)
  } > FblCodeConstArea,
  RUN_START(_FblCodeConstSecGroup_RUN_START),
  RUN_END(_FblCodeConstSecGroup_RUN_LIMIT)

  .FblCodeConstGroup_LABELS :
  {
    _FblCodeConstSecGroup_START = _FblCodeConstSecGroup_RUN_START;
    _FblCodeConstSecGroup_LIMIT = _FblCodeConstSecGroup_RUN_LIMIT;
    _FblCodeConstSecGroup_END = _FblCodeConstSecGroup_LIMIT - 1;
    _FblCodeConstGroup_ALL_START = _FblCodeConstSecGroup_START;
    _FblCodeConstGroup_ALL_END = _FblCodeConstSecGroup_END;
    _FblCodeConstGroup_ALL_LIMIT = _FblCodeConstSecGroup_LIMIT;
  }

  .FblHeaderSecGroup :
  {
    *(.FblHeaderSection)
  } > FblHeaderArea,
  RUN_START(_FblHeaderSecGroup_RUN_START),
  RUN_END(_FblHeaderSecGroup_RUN_LIMIT)

  .FblHeaderGroup_LABELS :
  {
    _FblHeaderSecGroup_START = _FblHeaderSecGroup_RUN_START;
    _FblHeaderSecGroup_LIMIT = _FblHeaderSecGroup_RUN_LIMIT;
    _FblHeaderSecGroup_END = _FblHeaderSecGroup_LIMIT - 1;
    _FblHeaderGroup_ALL_START = _FblHeaderSecGroup_START;
    _FblHeaderGroup_ALL_END = _FblHeaderSecGroup_END;
    _FblHeaderGroup_ALL_LIMIT = _FblHeaderSecGroup_LIMIT;
  }

  .FblPresPatternSecGroup :
  {
    *(.PresencePatternSection)
  } > FblLBPPArea,
  RUN_START(_FblPresPatternSecGroup_RUN_START),
  RUN_END(_FblPresPatternSecGroup_RUN_LIMIT)

  .FblPresPatternGroup_LABELS :
  {
    _FblPresPatternSecGroup_START = _FblPresPatternSecGroup_RUN_START;
    _FblPresPatternSecGroup_LIMIT = _FblPresPatternSecGroup_RUN_LIMIT;
    _FblPresPatternSecGroup_END = _FblPresPatternSecGroup_LIMIT - 1;
    _FblPresPatternGroup_ALL_START = _FblPresPatternSecGroup_START;
    _FblPresPatternGroup_ALL_END = _FblPresPatternSecGroup_END;
    _FblPresPatternGroup_ALL_LIMIT = _FblPresPatternSecGroup_LIMIT;
  }

  .MagicFlagSectionGroup :
  {
    *(.MagicFlagSection)
  } > MagicFlagRegion,
  RUN_START(_MagicFlagSectionGroup_RUN_START),
  RUN_END(_MagicFlagSectionGroup_RUN_LIMIT)

  .MagicFlagGroup_LABELS :
  {
    _MagicFlagSectionGroup_START = _MagicFlagSectionGroup_RUN_START;
    _MagicFlagSectionGroup_LIMIT = _MagicFlagSectionGroup_RUN_LIMIT;
    _MagicFlagSectionGroup_END = _MagicFlagSectionGroup_LIMIT - 1;
    _MagicFlagGroup_ALL_START = _MagicFlagSectionGroup_START;
    _MagicFlagGroup_ALL_END = _MagicFlagSectionGroup_END;
    _MagicFlagGroup_ALL_LIMIT = _MagicFlagSectionGroup_LIMIT;
  }

  .MasterSatelliteSharedRamSection : ALIGN(4)
  {
    *(.vMemAccMPartition)
    . = ALIGN(4);
  } > BmCodeConstArea, RUN > IPCRAM_BMStack,
  RUN_START(_MasterSatelliteSharedRamSection_RUN_START),
  RUN_END(_MasterSatelliteSharedRamSection_RUN_LIMIT),
  LOAD_START(_MasterSatelliteSharedRamSection_ROM_START),
  LOAD_END(_MasterSatelliteSharedRamSection_ROM_LIMIT)

  .MasterSatelliteSharedRamGroup_LABELS :
  {
    _MasterSatelliteSharedRamSection_START = _MasterSatelliteSharedRamSection_RUN_START;
    _MasterSatelliteSharedRamSection_LIMIT = _MasterSatelliteSharedRamSection_RUN_LIMIT;
    _MasterSatelliteSharedRamSection_END = _MasterSatelliteSharedRamSection_LIMIT - 1;
    _MasterSatelliteSharedRamGroup_ALL_START = _MasterSatelliteSharedRamSection_START;
    _MasterSatelliteSharedRamGroup_ALL_END = _MasterSatelliteSharedRamSection_END;
    _MasterSatelliteSharedRamGroup_ALL_LIMIT = _MasterSatelliteSharedRamSection_LIMIT;
  }

  .McalCddIpcDataSection : ALIGN(128)
  {
    *(.CDD_IPC_NOINIT_SECTION)
    . = ALIGN(128);
  } > CddIpcArea,
  RUN_START(_McalCddIpcDataSection_RUN_START),
  RUN_END(_McalCddIpcDataSection_RUN_LIMIT)

  .McalCddIpcDataGroup_LABELS :
  {
    _McalCddIpcDataSection_START = _McalCddIpcDataSection_RUN_START;
    _McalCddIpcDataSection_LIMIT = _McalCddIpcDataSection_RUN_LIMIT;
    _McalCddIpcDataSection_END = _McalCddIpcDataSection_LIMIT - 1;
    _McalCddIpcDataGroup_ALL_START = _McalCddIpcDataSection_START;
    _McalCddIpcDataGroup_ALL_END = _McalCddIpcDataSection_END;
    _McalCddIpcDataGroup_ALL_LIMIT = _McalCddIpcDataSection_LIMIT;
  }

  .McalUdmaEthSection : ALIGN(128)
  {
    *(.ETH_RX_DATA_SECTION)
    *(.ETH_TX_DATA_SECTION)
    *(.ETH_UDMA_DESC_SECTION)
    *(.ETH_UDMA_RING_SECTION)
    *(.ETH_UDMA_SECTION)
    . = ALIGN(128);
  } > EthArea,
  RUN_START(_McalUdmaEthSection_RUN_START),
  RUN_END(_McalUdmaEthSection_RUN_LIMIT)

  .McalUdmaEthGroup_LABELS :
  {
    _McalUdmaEthSection_START = _McalUdmaEthSection_RUN_START;
    _McalUdmaEthSection_LIMIT = _McalUdmaEthSection_RUN_LIMIT;
    _McalUdmaEthSection_END = _McalUdmaEthSection_LIMIT - 1;
    _McalUdmaEthGroup_ALL_START = _McalUdmaEthSection_START;
    _McalUdmaEthGroup_ALL_END = _McalUdmaEthSection_END;
    _McalUdmaEthGroup_ALL_LIMIT = _McalUdmaEthSection_LIMIT;
  }

  .RamBssSecGroup : ALIGN(4)
  {
    *(.bss*)
    . = ALIGN(4);
  } > DataBssRegion,
  RUN_START(_RamBssSecGroup_RUN_START),
  RUN_END(_RamBssSecGroup_RUN_LIMIT)

  .RamBssGroup_LABELS :
  {
    _RamBssSecGroup_START = _RamBssSecGroup_RUN_START;
    _RamBssSecGroup_LIMIT = _RamBssSecGroup_RUN_LIMIT;
    _RamBssSecGroup_END = _RamBssSecGroup_LIMIT - 1;
    _RamBssGroup_ALL_START = _RamBssSecGroup_START;
    _RamBssGroup_ALL_END = _RamBssSecGroup_END;
    _RamBssGroup_ALL_LIMIT = _RamBssSecGroup_LIMIT;
  }

  .RamSharedGroup :
  {
    *(.BRS_SHARED_SECTION)
  } > DataBssRegion_Shared,
  RUN_START(_RamSharedGroup_RUN_START),
  RUN_END(_RamSharedGroup_RUN_LIMIT)

  .RamSharedGroup_LABELS :
  {
    _RamSharedGroup_START = _RamSharedGroup_RUN_START;
    _RamSharedGroup_LIMIT = _RamSharedGroup_RUN_LIMIT;
    _RamSharedGroup_END = _RamSharedGroup_LIMIT - 1;
    _RamSharedGroup_ALL_START = _RamSharedGroup_START;
    _RamSharedGroup_ALL_END = _RamSharedGroup_END;
    _RamSharedGroup_ALL_LIMIT = _RamSharedGroup_LIMIT;
  }

  .STACK_C0 : ALIGN(4)
  {
    *(.stack)
    . = ALIGN(4);
  } > OCMRAM_Stack,
  RUN_START(_STACK_C0_RUN_START),
  RUN_END(_STACK_C0_RUN_LIMIT)

  .STACK_C0_LABELS :
  {
    _STACK_C0_START = _STACK_C0_RUN_START;
    _STACK_C0_LIMIT = _STACK_C0_RUN_LIMIT;
    _STACK_C0_END = _STACK_C0_LIMIT - 1;
    _STACK_C0_ALL_START = _STACK_C0_START;
    _STACK_C0_ALL_END = _STACK_C0_END;
    _STACK_C0_ALL_LIMIT = _STACK_C0_LIMIT;
  }

  .Startup_Stack_Symbols :
  {
    __section_stack_c0_end = _STACK_C0_LIMIT;
  }

  .SysMem :
  {
    *(.sysmem)
  } > OCMCRAM_Common_NonCache,
  RUN_START(_SysMem_RUN_START),
  RUN_END(_SysMem_RUN_LIMIT)

  .SysMem_LABELS :
  {
    _SysMem_START = _SysMem_RUN_START;
    _SysMem_LIMIT = _SysMem_RUN_LIMIT;
    _SysMem_END = _SysMem_LIMIT - 1;
    _SysMem_ALL_START = _SysMem_START;
    _SysMem_ALL_END = _SysMem_END;
    _SysMem_ALL_LIMIT = _SysMem_LIMIT;
  }

  .FBLAuthSectionGroup :
  {
    *(.FBLAuthSection)
  } > FBLAuthRegion,
  RUN_START(_FBLAuthSectionGroup_RUN_START),
  RUN_END(_FBLAuthSectionGroup_RUN_LIMIT)

  .FBLAuthGroup_LABELS :
  {
    _FBLAuthSectionGroup_START = _FBLAuthSectionGroup_RUN_START;
    _FBLAuthSectionGroup_LIMIT = _FBLAuthSectionGroup_RUN_LIMIT;
    _FBLAuthSectionGroup_END = _FBLAuthSectionGroup_LIMIT - 1;
    _FBLAuthGroup_ALL_START = _FBLAuthSectionGroup_START;
    _FBLAuthGroup_ALL_END = _FBLAuthSectionGroup_END;
    _FBLAuthGroup_ALL_LIMIT = _FBLAuthSectionGroup_LIMIT;
  }

  .RamDataSecGroup : ALIGN(4)
  {
    *(.data*)
    . = ALIGN(4);
  } > FblCodeConstArea, RUN > DataBssRegion,
  RUN_START(_RamDataSecGroup_RUN_START),
  RUN_END(_RamDataSecGroup_RUN_LIMIT),
  LOAD_START(_RamDataSecGroup_ROM_START),
  LOAD_END(_RamDataSecGroup_ROM_LIMIT)

  .RamDataGroup_LABELS :
  {
    _RamDataSecGroup_START = _RamDataSecGroup_RUN_START;
    _RamDataSecGroup_LIMIT = _RamDataSecGroup_RUN_LIMIT;
    _RamDataSecGroup_END = _RamDataSecGroup_LIMIT - 1;
    _RamDataGroup_ALL_START = _RamDataSecGroup_START;
    _RamDataGroup_ALL_END = _RamDataSecGroup_END;
    _RamDataGroup_ALL_LIMIT = _RamDataSecGroup_LIMIT;
  }

  .SafeShutDownSectionGroup :
  {
    *(.SafeShutDownSection)
  } > SafeShutDownRegion,
  RUN_START(_SafeShutDownSectionGroup_RUN_START),
  RUN_END(_SafeShutDownSectionGroup_RUN_LIMIT)

  .SafeShutDownGroup_LABELS :
  {
    _SafeShutDownSectionGroup_START = _SafeShutDownSectionGroup_RUN_START;
    _SafeShutDownSectionGroup_LIMIT = _SafeShutDownSectionGroup_RUN_LIMIT;
    _SafeShutDownSectionGroup_END = _SafeShutDownSectionGroup_LIMIT - 1;
    _SafeShutDownGroup_ALL_START = _SafeShutDownSectionGroup_START;
    _SafeShutDownGroup_ALL_END = _SafeShutDownSectionGroup_END;
    _SafeShutDownGroup_ALL_LIMIT = _SafeShutDownSectionGroup_LIMIT;
  }

  .SysMem_Symbols :
  {
    __SYSMEM_SIZE = 1024;
  }

}


