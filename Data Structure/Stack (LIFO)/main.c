#include <stdio.h>
#include "stack.h"

#define BUFFSIZE 7

element_type Buffer[BUFFSIZE] ;	

// testing the APIs
void main(void)
{
    LIFO_BUFF UART_BUFF;
    LIFO_STATUS status;
    status = Stack_init(&UART_BUFF , Buffer , BUFFSIZE );
    element_type i;
    if(status == STACK_NO_ERROR)
    {
        /**** Testing Stack Push ****/
        for(i = 0; i < 10; i++)
        {
            status = Stack_Push(&UART_BUFF , i);
            if(status == STACK_NO_ERROR)
            {
                printf("UART ADD item: %d\n",i);
            }
            else if(status == STACK_FULL)
            {
                printf("============== Stack Full ==============\n");
                break;
            }
        }
        /**** Testing Stack Pop ****/
        element_type var = 0;
        for(i = 0; i < 10; i++)
        {
            status = Stack_Pop(&UART_BUFF , &var);
            if(status == STACK_NO_ERROR)
            {
                printf("UART Get item: %d\n",var);
            }
            else if(status == STACK_EMPTY)
            {
                printf("============== Stack Empty ==============\n");
                break;
            }
        }

    }
    else
    {
        printf("stack does not exist\n");
    }    
}
