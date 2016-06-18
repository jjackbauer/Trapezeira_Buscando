################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Classe\ Ler\ Matriz\ de\ Arquivo\ (Ricardo)/Arquivo_Matrizes.cpp 

OBJS += \
./Classe\ Ler\ Matriz\ de\ Arquivo\ (Ricardo)/Arquivo_Matrizes.o 

CPP_DEPS += \
./Classe\ Ler\ Matriz\ de\ Arquivo\ (Ricardo)/Arquivo_Matrizes.d 


# Each subdirectory must supply rules for building sources it contributes
Classe\ Ler\ Matriz\ de\ Arquivo\ (Ricardo)/Arquivo_Matrizes.o: ../Classe\ Ler\ Matriz\ de\ Arquivo\ (Ricardo)/Arquivo_Matrizes.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -lm -I"/home/ricardo/Dropbox/Workspace/Trapezeira_Buscando" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Classe Ler Matriz de Arquivo (Ricardo)/Arquivo_Matrizes.d" -MT"Classe\ Ler\ Matriz\ de\ Arquivo\ (Ricardo)/Arquivo_Matrizes.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


