################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Classe\ Matriz\ (Ricardo)/Matriz.cpp 

OBJS += \
./Classe\ Matriz\ (Ricardo)/Matriz.o 

CPP_DEPS += \
./Classe\ Matriz\ (Ricardo)/Matriz.d 


# Each subdirectory must supply rules for building sources it contributes
Classe\ Matriz\ (Ricardo)/Matriz.o: ../Classe\ Matriz\ (Ricardo)/Matriz.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -lm -I"/home/ricardo/Dropbox/Workspace/Trapezeira_Buscando" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Classe Matriz (Ricardo)/Matriz.d" -MT"Classe\ Matriz\ (Ricardo)/Matriz.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


