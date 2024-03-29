# MPLAB IDE generated this makefile for use with GNU make.
# Project: Task1.mcp
# Date: Thu Mar 14 17:47:11 2024

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

Task1.cof : task1.o
	$(LD) /p18F4550 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.45\lib" "task1.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"Task1.cof" /M"Task1.map" /W

task1.o : task1.c ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.45/h/stdio.h task1.c ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.45/h/p18f4550.h ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.45/h/stdarg.h ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.45/h/stddef.h
	$(CC) -p=18F4550 "task1.c" -fo="task1.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "task1.o" "Task1.cof" "Task1.hex"

