################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Parser/Grammar_parser/Input_parser.cpp \
../src/Parser/Grammar_parser/Input_reader.cpp 

OBJS += \
./src/Parser/Grammar_parser/Input_parser.o \
./src/Parser/Grammar_parser/Input_reader.o 

CPP_DEPS += \
./src/Parser/Grammar_parser/Input_parser.d \
./src/Parser/Grammar_parser/Input_reader.d 


# Each subdirectory must supply rules for building sources it contributes
src/Parser/Grammar_parser/%.o: ../src/Parser/Grammar_parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

