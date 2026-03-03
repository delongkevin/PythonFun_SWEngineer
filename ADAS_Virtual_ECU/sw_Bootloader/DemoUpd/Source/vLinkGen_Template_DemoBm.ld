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
  OCMCRAM_VecExc : ORIGIN = 0x41010000 , LENGTH = 0x00000200 /* 512 Byte */
  OCMCRAM_Startup_Code : ORIGIN = 0x41010200 , LENGTH = 0x00001000 /* 4 KiB */
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
  .Startup_Code : ALIGN(4)
  {
    *(.brsResetLabel)
    *(.brsStartup)
  } > OCMCRAM_Common_StartupCode,
  RUN_START(_Startup_Code_RUN_START),
  RUN_END(_Startup_Code_RUN_LIMIT)

  .BmStartup_Code_LABELS :
  {
    _Startup_Code_START = _Startup_Code_RUN_START;
    _Startup_Code_LIMIT = _Startup_Code_RUN_LIMIT;
    _Startup_Code_END = _Startup_Code_LIMIT - 1;
    _BmStartup_Code_ALL_START = _Startup_Code_START;
    _BmStartup_Code_ALL_END = _Startup_Code_END;
    _BmStartup_Code_ALL_LIMIT = _Startup_Code_LIMIT;
  }

  .BmBrsExcVecSecGroup :
  {
    *(.brsExcVect)
  } > OCMCRAM_VecExc,
  RUN_START(_BmBrsExcVecSecGroup_RUN_START),
  RUN_END(_BmBrsExcVecSecGroup_RUN_LIMIT)

  .BmBrsExcVecGroup_LABELS :
  {
    _BmBrsExcVecSecGroup_START = _BmBrsExcVecSecGroup_RUN_START;
    _BmBrsExcVecSecGroup_LIMIT = _BmBrsExcVecSecGroup_RUN_LIMIT;
    _BmBrsExcVecSecGroup_END = _BmBrsExcVecSecGroup_LIMIT - 1;
    _BmBrsExcVecGroup_ALL_START = _BmBrsExcVecSecGroup_START;
    _BmBrsExcVecGroup_ALL_END = _BmBrsExcVecSecGroup_END;
    _BmBrsExcVecGroup_ALL_LIMIT = _BmBrsExcVecSecGroup_LIMIT;
  }

  .BmCodeConstSecGroup :
  {
    *(.boardcfg_data)
    *(.const*)
    *(.text)
  } > BmCodeConstArea,
  RUN_START(_BmCodeConstSecGroup_RUN_START),
  RUN_END(_BmCodeConstSecGroup_RUN_LIMIT)

  .BmCodeConstGroup_LABELS :
  {
    _BmCodeConstSecGroup_START = _BmCodeConstSecGroup_RUN_START;
    _BmCodeConstSecGroup_LIMIT = _BmCodeConstSecGroup_RUN_LIMIT;
    _BmCodeConstSecGroup_END = _BmCodeConstSecGroup_LIMIT - 1;
    _BmCodeConstGroup_ALL_START = _BmCodeConstSecGroup_START;
    _BmCodeConstGroup_ALL_END = _BmCodeConstSecGroup_END;
    _BmCodeConstGroup_ALL_LIMIT = _BmCodeConstSecGroup_LIMIT;
  }

  .BmHeaderSecGroup :
  {
    *(.BmHeaderSection)
  } > BmHdrArea,
  RUN_START(_BmHeaderSecGroup_RUN_START),
  RUN_END(_BmHeaderSecGroup_RUN_LIMIT)

  .BmHeaderGroup_LABELS :
  {
    _BmHeaderSecGroup_START = _BmHeaderSecGroup_RUN_START;
    _BmHeaderSecGroup_LIMIT = _BmHeaderSecGroup_RUN_LIMIT;
    _BmHeaderSecGroup_END = _BmHeaderSecGroup_LIMIT - 1;
    _BmHeaderGroup_ALL_START = _BmHeaderSecGroup_START;
    _BmHeaderGroup_ALL_END = _BmHeaderSecGroup_END;
    _BmHeaderGroup_ALL_LIMIT = _BmHeaderSecGroup_LIMIT;
  }

  .R5F_Startup_Code : ALIGN(4)
  {
    *(.startupCode)
  } > OCMCRAM_Common,
  RUN_START(_R5F_Startup_Code_RUN_START),
  RUN_END(_R5F_Startup_Code_RUN_LIMIT)

  .BmR5F_Startup_Code_LABELS :
  {
    _R5F_Startup_Code_START = _R5F_Startup_Code_RUN_START;
    _R5F_Startup_Code_LIMIT = _R5F_Startup_Code_RUN_LIMIT;
    _R5F_Startup_Code_END = _R5F_Startup_Code_LIMIT - 1;
    _BmR5F_Startup_Code_ALL_START = _R5F_Startup_Code_START;
    _BmR5F_Startup_Code_ALL_END = _R5F_Startup_Code_END;
    _BmR5F_Startup_Code_ALL_LIMIT = _R5F_Startup_Code_LIMIT;
  }

  .R5F_Startup_Data : ALIGN(4)
  {
    *(.startupData)
  } > OCMCRAM_Common,
  RUN_START(_R5F_Startup_Data_RUN_START),
  RUN_END(_R5F_Startup_Data_RUN_LIMIT)

  .BmR5F_Startup_Data_LABELS :
  {
    _R5F_Startup_Data_START = _R5F_Startup_Data_RUN_START;
    _R5F_Startup_Data_LIMIT = _R5F_Startup_Data_RUN_LIMIT;
    _R5F_Startup_Data_END = _R5F_Startup_Data_LIMIT - 1;
    _BmR5F_Startup_Data_ALL_START = _R5F_Startup_Data_START;
    _BmR5F_Startup_Data_ALL_END = _R5F_Startup_Data_END;
    _BmR5F_Startup_Data_ALL_LIMIT = _R5F_Startup_Data_LIMIT;
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

  .RamDataSecGroup : ALIGN(4)
  {
    *(.data*)
    . = ALIGN(4);
  } > BmCodeConstArea, RUN > DataBssRegion,
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

  .SysMem_Symbols :
  {
    __SYSMEM_SIZE = 1024;
  }

}


