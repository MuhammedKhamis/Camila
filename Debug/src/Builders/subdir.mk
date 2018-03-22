################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Builders/Builder.cpp \
../src/Builders/Postfix_handler.cpp \
../src/Builders/Subset_Builder.cpp \
../src/Builders/Thomson_Builder.cpp 

OBJS += \
./src/Builders/Builder.o \
./src/Builders/Postfix_handler.o \
./src/Builders/Subset_Builder.o \
./src/Builders/Thomson_Builder.o 

CPP_DEPS += \
./src/Builders/Builder.d \
./src/Builders/Postfix_handler.d \
./src/Builders/Subset_Builder.d \
./src/Builders/Thomson_Builder.d 


# Each subdirectory must supply rules for building sources it contributes
src/Builders/%.o: ../src/Builders/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


