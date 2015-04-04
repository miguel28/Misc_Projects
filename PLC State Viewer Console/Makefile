###########################################
# Simple Makefile for HIDAPI test program
#
# Alan Ott
# Signal 11 Software
# 2010-07-03
###########################################

all: main

CC=gcc
CXX=g++
COBJS=hid.o 
CPPOBJS=./main.o 
OBJS=$(COBJS) $(CPPOBJS)
CFLAGS+=-I./hidapi -Wall -g -c 
LIBS=-framework IOKit -framework CoreFoundation

USBInterfaceClass: $(OBJS)
	g++ -Wall -g $^ $(LIBS) -o USBInterfaceClass.o
main: $(OBJS) USBInterfaceClass.o
	g++ -Wall -g $^ $(LIBS) ./USBInterfaceClass.h -o main

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(CPPOBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f *.o hidtest $(CPPOBJS)

.PHONY: clean
