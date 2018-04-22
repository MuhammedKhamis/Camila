################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lexical/Files_Handler/FileReader.cpp 

OBJS += \
./src/Lexical/Files_Handler/FileReader.o 

CPP_DEPS += \
./src/Lexical/Files_Handler/FileReader.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Files_Handler/%.o: ../src/Lexical/Files_Handler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


