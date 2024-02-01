################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EEPROM_Driver/EEPROM.c 

OBJS += \
./HAL/EEPROM_Driver/EEPROM.o 

C_DEPS += \
./HAL/EEPROM_Driver/EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EEPROM_Driver/EEPROM.o: ../HAL/EEPROM_Driver/EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/EEPROM_Driver/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

