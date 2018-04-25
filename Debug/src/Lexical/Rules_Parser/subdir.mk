################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lexical/Rules_Parser/FileRulesReader.cpp \
../src/Lexical/Rules_Parser/Rules.cpp \
../src/Lexical/Rules_Parser/RulesParser.cpp 

OBJS += \
./src/Lexical/Rules_Parser/FileRulesReader.o \
./src/Lexical/Rules_Parser/Rules.o \
./src/Lexical/Rules_Parser/RulesParser.o 

CPP_DEPS += \
./src/Lexical/Rules_Parser/FileRulesReader.d \
./src/Lexical/Rules_Parser/Rules.d \
./src/Lexical/Rules_Parser/RulesParser.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Rules_Parser/%.o: ../src/Lexical/Rules_Parser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


