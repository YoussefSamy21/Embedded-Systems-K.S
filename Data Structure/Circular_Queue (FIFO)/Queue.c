#include "Queue.h"

#ifndef NULL
#define NULL    ((void*)0)
#endif


FIFO_STATUS QUEUE_init(FIFO_BUFF *buffer , element_type *ptr_arr , element_type length)
{
    FIFO_STATUS status;
    if(buffer == NULL)
    {
        status = QUEUE_NULL;
    }
    else
    {
        buffer->base = ptr_arr;
        buffer->head = ptr_arr;
        buffer->tail = ptr_arr;
        buffer->length = length;
        buffer->count = 0;
        status = QUEUE_NO_ERROR;
    }

    return status;
}

FIFO_STATUS Enqueue_item(FIFO_BUFF *buffer , element_type item)
{
    FIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->head == NULL) || (buffer->tail == NULL) ) // check if the Buffer Exists
    {
        status = QUEUE_NULL;
    }
    else if(Is_Queue_Full(buffer) == QUEUE_FULL)
    {
        status = QUEUE_FULL;
    }
    else
    {
        *(buffer->head) = item;
        buffer->count++;

        // Circular Queue
        if(buffer->head == (buffer->base + (buffer->length  * sizeof(element_type) ) )) 
        {
            buffer->head = buffer->base; // main feauture of the circular queue , that if the head reaches max length , start from the base again
        }
        else
        {
            buffer->head++;
        }
        status = QUEUE_NO_ERROR;
    }
    return status;
}


FIFO_STATUS Dequeue_item(FIFO_BUFF *buffer , element_type *ptr_item)
{
    FIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->head == NULL) || (buffer->tail == NULL) ) // check if the Buffer Exists
    {
        status = QUEUE_NULL;
    }
    else if(Is_Queue_Empty(buffer) == QUEUE_EMPTY)
    {
        status = QUEUE_EMPTY;
    }
    else
    {
        *ptr_item = *(buffer->tail);
        buffer->count--;

        // Circular Queue
       if(buffer->tail == (buffer->base + (buffer->length  * sizeof(element_type) ) ))
        {
            buffer->tail = buffer->base; // main feauture of the circular queue , that if the tail reaches max length , start from the base again
        }
        else
        {
            buffer->tail++;
        }
        status = QUEUE_NO_ERROR;
    }
    return status;
}


FIFO_STATUS Is_Queue_Full(FIFO_BUFF *buffer)
{
    FIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->head == NULL) || (buffer->tail == NULL) ) // check if the Buffer Exists
    {
        status = QUEUE_NULL;
    }
    else if(buffer->count == buffer->length)
    {
        status = QUEUE_FULL;
    }
    else
    {
        status = QUEUE_NO_ERROR;
    }
    return status;
}


FIFO_STATUS Is_Queue_Empty(FIFO_BUFF *buffer)
{
    FIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->head == NULL) || (buffer->tail == NULL) ) // check if the Buffer Exists
    {
        status = QUEUE_NULL;
    }
    else if(buffer->count == 0)
    {
        status = QUEUE_EMPTY;
    }
    else
    {
        status = QUEUE_NO_ERROR;
    }
    return status;
}

