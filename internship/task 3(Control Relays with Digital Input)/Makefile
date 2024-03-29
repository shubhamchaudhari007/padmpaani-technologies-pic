# MPLAB IDE generated this makefile for use with GNU make.
# Project: relay.mcp
# Date: Thu Mar 14 17:57:17 2024

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

relay.cof : task3.o
	$(LD) /p18F4550 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.45\lib" "task3.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"relay.cof" /M"relay.map" /W

task3.o : task3.c ../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.45/h/p18f4550.h
	$(CC) -p=18F4550 "task3.c" -fo="task3.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "task3.o" "relay.cof" "relay.hex"

