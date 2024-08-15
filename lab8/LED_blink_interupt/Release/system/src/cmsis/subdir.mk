################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/cmsis/system_stm32f4xx.c \
../system/src/cmsis/vectors_stm32f401xe.c 

C_DEPS += \
./system/src/cmsis/system_stm32f4xx.d \
./system/src/cmsis/vectors_stm32f401xe.d 

OBJS += \
./system/src/cmsis/system_stm32f4xx.o \
./system/src/cmsis/vectors_stm32f401xe.o 


# Each subdirectory must supply rules for building sources it contributes
system/src/cmsis/system_stm32f4xx.o: ../system/src/cmsis/system_stm32f4xx.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Lib" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Rcc" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Nvic" -std=gnu11 -Wno-padded -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/src/cmsis/%.o: ../system/src/cmsis/%.c system/src/cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Lib" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Rcc" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\LED_Toggle_with_interupt\Nvic" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


