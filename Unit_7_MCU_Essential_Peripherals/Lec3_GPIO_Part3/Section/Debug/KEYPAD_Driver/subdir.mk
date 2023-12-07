################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KEYPAD_Driver/KEYPAD_interface.c 

OBJS += \
./KEYPAD_Driver/KEYPAD_interface.o 

C_DEPS += \
./KEYPAD_Driver/KEYPAD_interface.d 


# Each subdirectory must supply rules for building sources it contributes
KEYPAD_Driver/KEYPAD_interface.o: ../KEYPAD_Driver/KEYPAD_interface.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"KEYPAD_Driver/KEYPAD_interface.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

