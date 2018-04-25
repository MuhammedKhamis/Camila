################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lexical/Graph/Edge.cpp \
../src/Lexical/Graph/Graph.cpp \
../src/Lexical/Graph/Node.cpp 

OBJS += \
./src/Lexical/Graph/Edge.o \
./src/Lexical/Graph/Graph.o \
./src/Lexical/Graph/Node.o 

CPP_DEPS += \
./src/Lexical/Graph/Edge.d \
./src/Lexical/Graph/Graph.d \
./src/Lexical/Graph/Node.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Graph/%.o: ../src/Lexical/Graph/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


