################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/STM32F103C6_GPIO_Driver.c 

OBJS += \
./MCAL/STM32F103C6_GPIO_Driver.o 

C_DEPS += \
./MCAL/STM32F103C6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/STM32F103C6_GPIO_Driver.o: ../MCAL/STM32F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/HP/STM32CubeIDE/workspace_1.4.0/Lab1_Unit7_Lec1/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/STM32F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

