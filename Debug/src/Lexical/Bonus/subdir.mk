################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lexical/Bonus/lex.yy.c \
../src/Lexical/Bonus/scanner.c 

OBJS += \
./src/Lexical/Bonus/lex.yy.o \
./src/Lexical/Bonus/scanner.o 

C_DEPS += \
./src/Lexical/Bonus/lex.yy.d \
./src/Lexical/Bonus/scanner.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Bonus/%.o: ../src/Lexical/Bonus/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


