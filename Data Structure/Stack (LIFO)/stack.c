#include "stack.h"


#ifndef NULL
#define NULL    ((void*)0)
#endif

/*
    The Implmentaion of this Stack mainly based on that initially the Stack_top & the base are pointing to the same location (when the stack is empty)..
    and the 
*/
LIFO_STATUS Stack_init( LIFO_BUFF *buffer , element_type *ptr_arr , element_type length)
{
    LIFO_STATUS status;
    if(buffer == NULL)
    {
        status = STACK_NULL;
    }
    else
    {
        buffer->stack_top = ptr_arr;
        buffer->base = ptr_arr;
        buffer->count = 0;
        buffer->length = length;

        status = STACK_NO_ERROR;
    }
    return status;
}


LIFO_STATUS Stack_Push(LIFO_BUFF *buffer , element_type item)
{
    LIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->stack_top == NULL) ) // check if the Buffer Exists
    {
        status = STACK_NULL;
    }
    else if(Is_Stack_Full(buffer) == STACK_FULL)
    {
        status = STACK_FULL;
    }
    else
    {
        *(buffer->stack_top) = item;
        buffer->count++;
        buffer->stack_top++;
        status = STACK_NO_ERROR;
    }
    return status;
}


LIFO_STATUS Stack_Pop(LIFO_BUFF *buffer , element_type *ptr_item)
{
    LIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->stack_top == NULL) ) // check if the Buffer Exists
    {
        status = STACK_NULL;
    }
    else if(Is_Stack_Empty(buffer) == STACK_EMPTY)
    {
        status = STACK_EMPTY;
    }
    else
    {
        buffer->stack_top--;
        *ptr_item = *(buffer->stack_top);
        buffer->count--;
        status = STACK_NO_ERROR;
    }
    return status;
}


LIFO_STATUS Is_Stack_Full(LIFO_BUFF *buffer)
{
    LIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->stack_top == NULL) ) // check if the Buffer Exists
    {
        status = STACK_NULL;
    }
    else if(buffer->count == buffer->length)
    {
        status = STACK_FULL;
    }
    else
    {
        status = STACK_NO_ERROR;
    }
    return status;
}


LIFO_STATUS Is_Stack_Empty(LIFO_BUFF *buffer)
{
    LIFO_STATUS status;
    if( (buffer->base == NULL) || (buffer->stack_top == NULL) ) // check if the Buffer Exists
    {
        status = STACK_NULL;
    }
    else if(buffer->count == 0)
    {
        status = STACK_EMPTY;
    }
    else
    {
        status = STACK_NO_ERROR;
    }
    return status;
}