################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Lexical/Builders/Builder.cpp \
../src/Lexical/Builders/Postfix_handler.cpp \
../src/Lexical/Builders/Subset_Builder.cpp \
../src/Lexical/Builders/Thomson_Builder.cpp 

OBJS += \
./src/Lexical/Builders/Builder.o \
./src/Lexical/Builders/Postfix_handler.o \
./src/Lexical/Builders/Subset_Builder.o \
./src/Lexical/Builders/Thomson_Builder.o 

CPP_DEPS += \
./src/Lexical/Builders/Builder.d \
./src/Lexical/Builders/Postfix_handler.d \
./src/Lexical/Builders/Subset_Builder.d \
./src/Lexical/Builders/Thomson_Builder.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lexical/Builders/%.o: ../src/Lexical/Builders/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


