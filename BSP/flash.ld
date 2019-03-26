/* Entry Point */
ENTRY(Reset_Handler)

_Min_Heap_Size = 0x9000;      /* required amount of heap  */
_Min_Stack_Size = 0x2000; /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
/*FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 2048K*/
FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 2048K
RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 128K
/*RAM (xrw)       : ORIGIN = 0x20020000, LENGTH = 100K */
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

/* Define output sections */
SECTIONS
{
  .text :
  {
    KEEP(*(.isr_vector))
    . = ALIGN(4);
    _stext = .;
    *(.text*)
    *(.rodata*)

    KEEP(*(.init))
    KEEP(*(.fini))

    . = ALIGN(4);
    _etext = .;
  } > FLASH

  .ARM.extab : 
  {
      *(.ARM.extab*)
  } > FLASH

  .ARM.exidx :
  {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } > FLASH

  .preinit_array :
  {
      PROVIDE_HIDDEN(__preinit_array_start = .);
      KEEP(*(.preinit_array*))
      PROVIDE_HIDDEN(__preinit_array_end = .);
  } > FLASH
  .init_array :
  {
      PROVIDE_HIDDEN(__init_array_start = .);
      KEEP(*(SORT(.init_array.*)))
      KEEP(*(.init_array*))
      PROVIDE_HIDDEN(__init_array_end = .);
  } > FLASH
  .fini_array :
  {
      PROVIDE_HIDDEN(__fini_array_start = .);
      KEEP(*(SORT(.fini_array.*)))
      KEEP(*(.fini_array*))
      PROVIDE_HIDDEN(__fini_array_end = .);
  } > FLASH

  _sidata = .;
  .data : AT(_sidata)
  {
      . = ALIGN(4);
      _sdata = .;
      *(.data*)
      . = ALIGN(4);
      _edata = .;
  } > RAM

  .bss :
  {
      . = ALIGN(4);
      _sbss = .;
      *(.bss*)
      *(COMMON)
      . = ALIGN(4);
      _ebss = .;
  } > RAM

  ._user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM

  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
