CC = gcc

all : program.exe

program.exe : main.c Reelection.h Reelection.o
	${CC} -std=c99 -o program.exe main.c Reelection.o

Reelection.o : Reelection.c Reelection.h
	${CC} -c -std=c99 Reelection.c

clean : 
	del /f *.o *.exe