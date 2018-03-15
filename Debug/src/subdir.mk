################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FileRulesReader.cpp \
../src/Rules.cpp \
../src/RulesParser.cpp \
../src/Test.cpp 

OBJS += \
./src/FileRulesReader.o \
./src/Rules.o \
./src/RulesParser.o \
./src/Test.o 

CPP_DEPS += \
./src/FileRulesReader.d \
./src/Rules.d \
./src/RulesParser.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


