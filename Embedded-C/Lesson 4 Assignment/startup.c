/*
    Startup.c for ARM CORTEX-M4
    Eng.Youssef Samy
*/
void RESET_HANDLER(void);
extern void main(void);

void Default_Handler()
{
    RESET_HANDLER();
}

void NMI_HANDLER() __attribute__ ((weak, alias("Default_Handler")));;
void H_Fault_HANDLER() __attribute__ ((weak, alias("Default_Handler")));;

/************   Reserving the Stack Size  ************/
static unsigned long STACK_TOP[256];
// STACK_TOP is now included in .bss section , size of bss = 256*4 = 1024 Byte (0x400 in HEXA)


/************   Vectors section is an Array of Constant pointer to functions taking void and Returning void  ************/
void ( * const g_PTR_FUN_Vectors[]) (void) __attribute__((section(".vectors"))) = 
{
    // Specifing the ==> STACK_TOP + <Size> to Stack_Pointer Register
    (void (*)(void)) ((unsigned long)STACK_TOP + sizeof(STACK_TOP)),
    &RESET_HANDLER,
    &NMI_HANDLER,
    &H_Fault_HANDLER
};

extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void RESET_HANDLER(void)
{
    unsigned int i;
    /*********  Copying Data from FLASH TO SRAM  *********/
    unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
    unsigned char *ptr_src = (unsigned char*)&_E_TEXT ; 
    unsigned char *ptr_dest = (unsigned char*)&_S_DATA ;
    for(i = 0; i < DATA_SIZE; i++)
    {
        *((unsigned char*)ptr_dest) = *((unsigned char*)ptr_src);
        ptr_src++;
        ptr_dest++;
    }
    /*********  Initializing the .bss section in SRAM with ZERO  *********/
    unsigned int BSS_SIZE = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS ;
    ptr_dest = (unsigned char *)&_S_BSS;
    for(i = 0; i < BSS_SIZE; i++)
    {
        *((unsigned char*) ptr_dest) = (unsigned char)0 ;
        ptr_dest++;
    }
    main(); // Finally jumping to the main :)
}