################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC.c \
../Src/LCD_4BIT.c \
../Src/LCD_8BIT.c \
../Src/USART2.c \
../Src/delay.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC.o \
./Src/LCD_4BIT.o \
./Src/LCD_8BIT.o \
./Src/USART2.o \
./Src/delay.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC.d \
./Src/LCD_4BIT.d \
./Src/LCD_8BIT.d \
./Src/USART2.d \
./Src/delay.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F401RETx -DSTM32F4 -DSTM32F401xE -c -I../Inc -I"F:/STM_06-09-22/Drivers/CMSIS/Include" -I"F:/STM_06-09-22/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC.d ./Src/ADC.o ./Src/ADC.su ./Src/LCD_4BIT.d ./Src/LCD_4BIT.o ./Src/LCD_4BIT.su ./Src/LCD_8BIT.d ./Src/LCD_8BIT.o ./Src/LCD_8BIT.su ./Src/USART2.d ./Src/USART2.o ./Src/USART2.su ./Src/delay.d ./Src/delay.o ./Src/delay.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

