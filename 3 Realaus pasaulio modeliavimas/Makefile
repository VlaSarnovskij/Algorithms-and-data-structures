TARGET = KaskoSim.exe
CC = gcc
FLAGS = -std=c99

all : $(TARGET)

$(TARGET) : main.o simulation.o priorityQueue.o BigInteger.o
	$(CC) $(FLAGS) -o $(TARGET) main.o simulation.o priorityQueue.o BigInteger.o

main.o : main.c simulation.h priorityQueue.h BigInteger.h
	$(CC) $(FLAGS) -c main.c

simulation.o : simulation.c simulation.h priorityQueue.h BigInteger.h
	$(CC) $(FLAGS) -c simulation.c

priorityQueue.o : priorityQueue.c priorityQueue.h
	$(CC) $(FLAGS) -c priorityQueue.c

BigInteger.o : BigInteger.c BigInteger.h
	$(CC) $(FLAGS) -c BigInteger.c
