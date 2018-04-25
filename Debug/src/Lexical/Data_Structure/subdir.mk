################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lexical/Data_Structure/Token_Saver.cpp 

OBJS += \
./src/Lexical/Data_Structure/Token_Saver.o 

CPP_DEPS += \
./src/Lexical/Data_Structure/Token_Saver.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Data_Structure/%.o: ../src/Lexical/Data_Structure/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


