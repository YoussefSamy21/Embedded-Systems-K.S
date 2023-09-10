#ifndef QUEUE_H_
#define QUEUE_H_

// User Configuration : Select element type (unsigned char,unsigned int,signed char, .... )
#define element_type    unsigned int
/*
    to create more than one Buffer, (for ex: UART TEMP_SENSOR, .... ) we can create more than one struct , 
    each struct has its own base , head, length ....
*/

typedef struct
{
    element_type length;
    element_type count;
    element_type *base;
    element_type *head;
    element_type *tail;

}FIFO_BUFF;

typedef enum
{
    QUEUE_FULL,             // FIFO BUFFER is Full
    QUEUE_EMPTY,           // FIFO BUFFER is Empty
    QUEUE_NO_ERROR,        // No Error from calling the API 
    QUEUE_NULL            // FIFO Buffer does not exist  
}FIFO_STATUS;

FIFO_STATUS QUEUE_init(FIFO_BUFF *buffer , element_type *ptr_arr , element_type length);
FIFO_STATUS Enqueue_item(FIFO_BUFF *buffer , element_type item);
FIFO_STATUS Dequeue_item(FIFO_BUFF *buffer , element_type *ptr_item);
FIFO_STATUS Is_Queue_Full(FIFO_BUFF *buffer);
FIFO_STATUS Is_Queue_Empty(FIFO_BUFF *buffer);


















#endif /*QUEUE_H_*/