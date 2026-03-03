/**********************************************************************************************************************
 *  EXAMPLE CODE ONLY
 *  -------------------------------------------------------------------------------------------------------------------
 *  This Example Code is only intended for illustrating an example of a possible BSW integration and BSW configuration.
 *  The Example Code has not passed any quality control measures and may be incomplete. The Example Code is neither
 *  intended nor qualified for use in series production. The Example Code as well as any of its modifications and/or
 *  implementations must be tested with diligent care and must comply with all quality requirements which are necessary
 *  according to the state of the art before their use.
 *********************************************************************************************************************/


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
  FblFCAheaderArea : ORIGIN = 0x90900000 , LENGTH = 0x000001C0 /* 448 Byte */
  FblHeaderArea : ORIGIN = 0x909001C0 , LENGTH = 0x00000020 /* 32 Byte */
  FblBmHdrHeaderArea : ORIGIN = 0x909001E0 , LENGTH = 0x00000020 /* 32 Byte */
  FblCodeConstArea : ORIGIN = 0x90900200 , LENGTH = 0x0007A000 /* 488 KiB */
  EepDummyArea : ORIGIN = 0x9097A200 , LENGTH = 0x00001000 /* 4 KiB */
  FblLBPPArea : ORIGIN = 0x9097C000 , LENGTH = 0x00002000 /* 8 KiB */
  FblBlockPPArea : ORIGIN = 0x9097E000 , LENGTH = 0x00002000 /* 8 KiB */
  ApplUpdBmHdrHeaderArea : ORIGIN = 0x90A00000 , LENGTH = 0x00000020 /* 32 Byte */
  ApplUpdCodeConstArea : ORIGIN = 0x90A00020 , LENGTH = 0x003FFBE0 /* 4 MiB */
  ApplUpdBlockPPArea : ORIGIN = 0x90DFFC00 , LENGTH = 0x00000200 /* 512 Byte */
  ApplUpdLBPPArea : ORIGIN = 0x90DFFE00 , LENGTH = 0x00000200 /* 512 Byte */
}

SECTIONS
{
  .ApplPresPatternSecGroup :
  {
    *(.ApplPresPatternSection)
  } > ApplUpdBlockPPArea,
  RUN_START(_ApplPresPatternSecGroup_RUN_START),
  RUN_END(_ApplPresPatternSecGroup_RUN_LIMIT)

  .ApplPresPatternGroup_LABELS :
  {
    _ApplPresPatternSecGroup_START = _ApplPresPatternSecGroup_RUN_START;
    _ApplPresPatternSecGroup_LIMIT = _ApplPresPatternSecGroup_RUN_LIMIT;
    _ApplPresPatternSecGroup_END = _ApplPresPatternSecGroup_LIMIT - 1;
    _ApplPresPatternGroup_ALL_START = _ApplPresPatternSecGroup_START;
    _ApplPresPatternGroup_ALL_END = _ApplPresPatternSecGroup_END;
    _ApplPresPatternGroup_ALL_LIMIT = _ApplPresPatternSecGroup_LIMIT;
  }

  .ApplUpdBmHdrHeaderSecGroup :
  {
    *(.BmHdrHeaderSection)
  } > ApplUpdBmHdrHeaderArea,
  RUN_START(_ApplUpdBmHdrHeaderSecGroup_RUN_START),
  RUN_END(_ApplUpdBmHdrHeaderSecGroup_RUN_LIMIT)

  .ApplUpdBmHdrHeaderGroup_LABELS :
  {
    _ApplUpdBmHdrHeaderSecGroup_START = _ApplUpdBmHdrHeaderSecGroup_RUN_START;
    _ApplUpdBmHdrHeaderSecGroup_LIMIT = _ApplUpdBmHdrHeaderSecGroup_RUN_LIMIT;
    _ApplUpdBmHdrHeaderSecGroup_END = _ApplUpdBmHdrHeaderSecGroup_LIMIT - 1;
    _ApplUpdBmHdrHeaderGroup_ALL_START = _ApplUpdBmHdrHeaderSecGroup_START;
    _ApplUpdBmHdrHeaderGroup_ALL_END = _ApplUpdBmHdrHeaderSecGroup_END;
    _ApplUpdBmHdrHeaderGroup_ALL_LIMIT = _ApplUpdBmHdrHeaderSecGroup_LIMIT;
  }

  .ApplUpdCodeConstSecArea :
  {
    *(.boardcfg_data)
    *(.const*)
    *(.rodata*)
    *(.text)
  } > ApplUpdCodeConstArea,
  RUN_START(_ApplUpdCodeConstSecArea_RUN_START),
  RUN_END(_ApplUpdCodeConstSecArea_RUN_LIMIT)

  .ApplUpdCodeConstArea_LABELS :
  {
    _ApplUpdCodeConstSecArea_START = _ApplUpdCodeConstSecArea_RUN_START;
    _ApplUpdCodeConstSecArea_LIMIT = _ApplUpdCodeConstSecArea_RUN_LIMIT;
    _ApplUpdCodeConstSecArea_END = _ApplUpdCodeConstSecArea_LIMIT - 1;
    _ApplUpdCodeConstArea_ALL_START = _ApplUpdCodeConstSecArea_START;
    _ApplUpdCodeConstArea_ALL_END = _ApplUpdCodeConstSecArea_END;
    _ApplUpdCodeConstArea_ALL_LIMIT = _ApplUpdCodeConstSecArea_LIMIT;
  }

  .ApplUpdPresPatternSecGroup :
  {
    *(.PresencePatternSection)
  } > ApplUpdLBPPArea,
  RUN_START(_ApplUpdPresPatternSecGroup_RUN_START),
  RUN_END(_ApplUpdPresPatternSecGroup_RUN_LIMIT)

  .ApplUpdPresPatternGroup_LABELS :
  {
    _ApplUpdPresPatternSecGroup_START = _ApplUpdPresPatternSecGroup_RUN_START;
    _ApplUpdPresPatternSecGroup_LIMIT = _ApplUpdPresPatternSecGroup_RUN_LIMIT;
    _ApplUpdPresPatternSecGroup_END = _ApplUpdPresPatternSecGroup_LIMIT - 1;
    _ApplUpdPresPatternGroup_ALL_START = _ApplUpdPresPatternSecGroup_START;
    _ApplUpdPresPatternGroup_ALL_END = _ApplUpdPresPatternSecGroup_END;
    _ApplUpdPresPatternGroup_ALL_LIMIT = _ApplUpdPresPatternSecGroup_LIMIT;
  }

  .EepDummySectionGroup :
  {
    *(.EepDummySection)
  } > EepDummyArea,
  RUN_START(_EepDummySectionGroup_RUN_START),
  RUN_END(_EepDummySectionGroup_RUN_LIMIT)

  .EepDummyGroup_LABELS :
  {
    _EepDummySectionGroup_START = _EepDummySectionGroup_RUN_START;
    _EepDummySectionGroup_LIMIT = _EepDummySectionGroup_RUN_LIMIT;
    _EepDummySectionGroup_END = _EepDummySectionGroup_LIMIT - 1;
    _EepDummyGroup_ALL_START = _EepDummySectionGroup_START;
    _EepDummyGroup_ALL_END = _EepDummySectionGroup_END;
    _EepDummyGroup_ALL_LIMIT = _EepDummySectionGroup_LIMIT;
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
  } > FblCodeConstArea, RUN > IPCRAM_BMStack,
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
  } > ApplUpdCodeConstArea, RUN > DataBssRegion,
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


