################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Graph/Edge.cpp \
../src/Graph/Graph.cpp \
../src/Graph/Node.cpp 

OBJS += \
./src/Graph/Edge.o \
./src/Graph/Graph.o \
./src/Graph/Node.o 

CPP_DEPS += \
./src/Graph/Edge.d \
./src/Graph/Graph.d \
./src/Graph/Node.d 


# Each subdirectory must supply rules for building sources it contributes
src/Graph/%.o: ../src/Graph/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


