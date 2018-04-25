################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lexical/Machines/Machine.cpp \
../src/Lexical/Machines/State.cpp \
../src/Lexical/Machines/Transition_Table.cpp 

OBJS += \
./src/Lexical/Machines/Machine.o \
./src/Lexical/Machines/State.o \
./src/Lexical/Machines/Transition_Table.o 

CPP_DEPS += \
./src/Lexical/Machines/Machine.d \
./src/Lexical/Machines/State.d \
./src/Lexical/Machines/Transition_Table.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Machines/%.o: ../src/Lexical/Machines/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


