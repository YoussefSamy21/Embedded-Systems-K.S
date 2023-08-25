#include "UART.h"

unsigned char string_buffer[100] = "learn-in-depth:<Youssef Samy>";
const unsigned char string_buffer2[100] = "to create the (.ro)data section";

void main(void)
{
    UART_Send_String(string_buffer); // VersatilePB physical Board
}
