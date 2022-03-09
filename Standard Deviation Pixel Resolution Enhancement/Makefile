# File: Makefile
# Author: Matthew Pugh
# Date last modified: 10-25-2019
# Description: Makefile for Stacker class in Assignment 5.

#compiler
CC = g++

#debug
DEBUG = -g

#excutable
TARGET = testo

#all warnings
CFLAGS = -c $(DEBUG)

all: $(TARGET)

$(TARGET): main.o stacker.o
	   $(CC) main.o stacker.o -o $(TARGET)

main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) main.cpp

stacker.o: stacker.cpp stacker.h
	  $(CC) $(CFLAGS) stacker.cpp

clean:
	rm *.o *~ $(TARGET)
