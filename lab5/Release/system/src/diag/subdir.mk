################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../system/src/diag/trace-impl.c \
../system/src/diag/trace.c 

C_DEPS += \
./system/src/diag/trace-impl.d \
./system/src/diag/trace.d 

OBJS += \
./system/src/diag/trace-impl.o \
./system/src/diag/trace.o 


# Each subdirectory must supply rules for building sources it contributes
system/src/diag/%.o: ../system/src/diag/%.c system/src/diag/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab-and-assignment-5-embedded_spting24_team_10\Lib" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab-and-assignment-5-embedded_spting24_team_10\Rcc" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab-and-assignment-5-embedded_spting24_team_10\Gpio" -I"C:\Users\Sara\SBME\year 3\2nd Term\Embeded\tasks\lab-and-assignment-5-embedded_spting24_team_10\Keypad" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


