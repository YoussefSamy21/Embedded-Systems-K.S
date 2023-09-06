/*
    Linker Script Cortex-M4
    Eng.Youssef Samy
*/

MEMORY
{
    FLASH(RX) : ORIGIN = 0x00000000, LENGTH = 512M
    SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 512M 
}


SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_TEXT = . ; /* symbol has the address of the end of .text section */

    }> FLASH 

    .data :
    {
        _S_DATA = . ;   /* symbol has the address of the Start of .data section */
        *(.data)
        . = ALIGN(4) ;  /* Alignment by 4 Bytes */
        _E_DATA = . ;   /* symbol has the address of the End of .data section */

    } > SRAM AT> FLASH

    .bss :
    {
        _S_BSS = . ;    /* symbol has the address of the Start of .bss section */
        *(.bss*)
        _E_BSS = . ;    /* symbol has the address of the end of .bss section */

    } > SRAM
}

