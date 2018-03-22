################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Machines/Machine.cpp \
../src/Machines/State.cpp \
../src/Machines/Transition_Table.cpp 

OBJS += \
./src/Machines/Machine.o \
./src/Machines/State.o \
./src/Machines/Transition_Table.o 

CPP_DEPS += \
./src/Machines/Machine.d \
./src/Machines/State.d \
./src/Machines/Transition_Table.d 


# Each subdirectory must supply rules for building sources it contributes
src/Machines/%.o: ../src/Machines/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


