# MPLAB IDE generated this makefile for use with GNU make.
# Project: led.mcp
# Date: Thu Mar 14 17:53:19 2024

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

led.cof : task2.o
	$(LD) /p18F4550 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.45\lib" "task2.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"led.cof" /M"led.map" /W

task2.o : task2.c ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.45/h/p18f4550.h
	$(CC) -p=18F4550 "task2.c" -fo="task2.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "task2.o" "led.cof" "led.hex"

