typedef struct _MMCLONE_HEADER
{
  /* 0x0000 */ unsigned long NumberOfPtes;
  /* 0x0004 */ volatile unsigned long NumberOfProcessReferences;
  /* 0x0008 */ struct _MMCLONE_BLOCK* ClonePtes;
} MMCLONE_HEADER, *PMMCLONE_HEADER; /* size: 0x000c */

