################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Arquivo_Matrizes.cpp \
../Driver.cpp \
../Matriz.cpp 

OBJS += \
./Arquivo_Matrizes.o \
./Driver.o \
./Matriz.o 

CPP_DEPS += \
./Arquivo_Matrizes.d \
./Driver.d \
./Matriz.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -lm -I"/home/ricardo/Dropbox/Workspace/Trapezeira_Buscando" -include"/home/ricardo/Dropbox/Workspace/Trapezeira_Buscando/Matriz.hpp" -include"/home/ricardo/Dropbox/Workspace/Trapezeira_Buscando/Arquivo_Matrizes.hpp" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


