#include <stdio.h>
#include "Queue.h"

#define BUFFSIZE 7

element_type Buffer[BUFFSIZE] ;	

// testing the APIs
void main(void)
{
    FIFO_BUFF UART_BUFF;
    FIFO_STATUS status;
    status = QUEUE_init(&UART_BUFF , Buffer , BUFFSIZE );
    element_type i;
    if(status == QUEUE_NO_ERROR)
    {
        /**** Testing Enqueue ****/
        for(i = 0; i < 10; i++)
        {
            status = Enqueue_item(&UART_BUFF , i);
            if(status == QUEUE_NO_ERROR)
            {
                printf("UART Enqueue item: %d\n",i);
            }
            else if(status == QUEUE_FULL)
            {
                printf("============== Queue Full ==============\n");
                break;
            }
        }
        /**** Testing Dequeue ****/
        element_type var = 0;
        for(i = 0; i < 10; i++)
        {
            status = Dequeue_item(&UART_BUFF , &var);
            if(status == QUEUE_NO_ERROR)
            {
                printf("UART Dequeue item: %d\n",var);
            }
            else if(status == QUEUE_EMPTY)
            {
                printf("============== Queue Empty ==============\n");
                break;
            }
        }

    }
    else
    {
        printf("Queue does not exist\n");
    }
}