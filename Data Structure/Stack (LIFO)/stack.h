/*
    Array based Stack Buffer (Static Allocation) 
*/
#ifndef STACK_H_
#define STACK_H_

// User Configuration : Select element type (unsigned char,unsigned int,signed char, .... )
#define element_type    unsigned int

/*
    to create more than one Buffer, (for ex: UART Stack, TEMP_SENSOR Stack , .... ) we can create more than one struct , 
    each struct has its own base and stack_top , length and count.
*/
typedef struct
{
    element_type length;
    element_type count;
    element_type *base;
    element_type *stack_top; 
}LIFO_BUFF;

typedef enum
{
    STACK_FULL,             // LIFO BUFFER is Full
    STACK_EMPTY,           // LIFO BUFFER is Empty
    STACK_NO_ERROR,        // No Error from calling the API 
    STACK_NULL            // LIFO Buffer does not exist  
}LIFO_STATUS;


// APIS

LIFO_STATUS Stack_init( LIFO_BUFF *buffer , element_type *ptr_arr , element_type length);
LIFO_STATUS Stack_Push(LIFO_BUFF *buffer , element_type item);
LIFO_STATUS Stack_Pop(LIFO_BUFF *buffer , element_type *ptr_item);
LIFO_STATUS Is_Stack_Full(LIFO_BUFF *buffer);
LIFO_STATUS Is_Stack_Empty(LIFO_BUFF *buffer);
// LIFO_STATUS Stack_Display(LIFO_BUFF *buffer); // for testing

#endif  /* STACK_H_ */

