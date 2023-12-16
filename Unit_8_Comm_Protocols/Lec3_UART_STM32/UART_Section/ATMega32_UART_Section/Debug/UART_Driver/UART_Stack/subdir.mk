################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UART_Driver/UART_Stack/Stack.c 

OBJS += \
./UART_Driver/UART_Stack/Stack.o 

C_DEPS += \
./UART_Driver/UART_Stack/Stack.d 


# Each subdirectory must supply rules for building sources it contributes
UART_Driver/UART_Stack/%.o: ../UART_Driver/UART_Stack/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


