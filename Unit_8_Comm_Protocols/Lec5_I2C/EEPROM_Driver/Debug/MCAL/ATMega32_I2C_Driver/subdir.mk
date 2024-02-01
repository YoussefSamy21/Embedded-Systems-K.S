################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ATMega32_I2C_Driver/I2C_interface.c 

OBJS += \
./MCAL/ATMega32_I2C_Driver/I2C_interface.o 

C_DEPS += \
./MCAL/ATMega32_I2C_Driver/I2C_interface.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ATMega32_I2C_Driver/%.o: ../MCAL/ATMega32_I2C_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


