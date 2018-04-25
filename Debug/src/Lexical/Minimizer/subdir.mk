################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lexical/Minimizer/Group.cpp \
../src/Lexical/Minimizer/Groups.cpp \
../src/Lexical/Minimizer/Minimizer.cpp 

OBJS += \
./src/Lexical/Minimizer/Group.o \
./src/Lexical/Minimizer/Groups.o \
./src/Lexical/Minimizer/Minimizer.o 

CPP_DEPS += \
./src/Lexical/Minimizer/Group.d \
./src/Lexical/Minimizer/Groups.d \
./src/Lexical/Minimizer/Minimizer.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Minimizer/%.o: ../src/Lexical/Minimizer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


