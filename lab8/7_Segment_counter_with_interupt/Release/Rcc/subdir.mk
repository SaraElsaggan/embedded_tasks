################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Rcc/Rcc.c 

C_DEPS += \
./Rcc/Rcc.d 

OBJS += \
./Rcc/Rcc.o 


# Each subdirectory must supply rules for building sources it contributes
Rcc/%.o: ../Rcc/%.c Rcc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\7_Segment_counter_with_interupt\EXTI" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\7_Segment_counter_with_interupt\Lib" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\7_Segment_counter_with_interupt\Rcc" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\7_Segment_counter_with_interupt\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab_8\7_Segment_counter_with_interupt\Nvic" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


