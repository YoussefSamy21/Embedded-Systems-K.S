################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/STM32F103C6_EXTI_Driver.c \
../MCAL/STM32F103C6_GPIO_Driver.c \
../MCAL/STM32F103C6_RCC_Driver.c \
../MCAL/STM32F103C6_SPI_Driver.c \
../MCAL/STM32F103C6_USART_Driver.c 

OBJS += \
./MCAL/STM32F103C6_EXTI_Driver.o \
./MCAL/STM32F103C6_GPIO_Driver.o \
./MCAL/STM32F103C6_RCC_Driver.o \
./MCAL/STM32F103C6_SPI_Driver.o \
./MCAL/STM32F103C6_USART_Driver.o 

C_DEPS += \
./MCAL/STM32F103C6_EXTI_Driver.d \
./MCAL/STM32F103C6_GPIO_Driver.d \
./MCAL/STM32F103C6_RCC_Driver.d \
./MCAL/STM32F103C6_SPI_Driver.d \
./MCAL/STM32F103C6_USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/STM32F103C6_EXTI_Driver.o: ../MCAL/STM32F103C6_EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/STM32F103C6_EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/STM32F103C6_GPIO_Driver.o: ../MCAL/STM32F103C6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/STM32F103C6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/STM32F103C6_RCC_Driver.o: ../MCAL/STM32F103C6_RCC_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/STM32F103C6_RCC_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/STM32F103C6_SPI_Driver.o: ../MCAL/STM32F103C6_SPI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/STM32F103C6_SPI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/STM32F103C6_USART_Driver.o: ../MCAL/STM32F103C6_USART_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/STM32F103C6_USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

