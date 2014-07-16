################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../List.o \
../Polynomial.o \
../main.o 

CPP_SRCS += \
../List.cpp \
../Polynomial.cpp \
../main.cpp 

OBJS += \
./List.o \
./Polynomial.o \
./main.o 

CPP_DEPS += \
./List.d \
./Polynomial.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


