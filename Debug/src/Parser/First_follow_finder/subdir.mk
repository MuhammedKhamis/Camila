################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Parser/First_follow_finder/first_follow_generator.cpp 

OBJS += \
./src/Parser/First_follow_finder/first_follow_generator.o 

CPP_DEPS += \
./src/Parser/First_follow_finder/first_follow_generator.d 


# Each subdirectory must supply rules for building sources it contributes
src/Parser/First_follow_finder/%.o: ../src/Parser/First_follow_finder/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I../__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0  -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


