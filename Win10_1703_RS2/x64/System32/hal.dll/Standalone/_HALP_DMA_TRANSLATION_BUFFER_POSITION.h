typedef struct _HALP_DMA_TRANSLATION_BUFFER_POSITION
{
  /* 0x0000 */ struct _HALP_DMA_TRANSLATION_BUFFER* Buffer;
  /* 0x0008 */ unsigned long Offset;
  /* 0x000c */ long __PADDING__[1];
} HALP_DMA_TRANSLATION_BUFFER_POSITION, *PHALP_DMA_TRANSLATION_BUFFER_POSITION; /* size: 0x0010 */
