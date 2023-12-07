################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD_Driver/LCD_interface.c 

OBJS += \
./LCD_Driver/LCD_interface.o 

C_DEPS += \
./LCD_Driver/LCD_interface.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_Driver/LCD_interface.o: ../LCD_Driver/LCD_interface.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD_Driver/LCD_interface.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

