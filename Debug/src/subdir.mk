################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Board.cpp \
../src/Cell.cpp \
../src/Hlf.cpp \
../src/Interface.cpp \
../src/Player.cpp 

OBJS += \
./src/Board.o \
./src/Cell.o \
./src/Hlf.o \
./src/Interface.o \
./src/Player.o 

CPP_DEPS += \
./src/Board.d \
./src/Cell.d \
./src/Hlf.d \
./src/Interface.d \
./src/Player.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


