CC=gcc
CFLAGS=-lWarn -pedantic

tempRead: tempRead.o
	cc tempRead.o -lwiringPi -o tempRead

tempRead.o: tempRead.c tempReadDef.h
	$(CC) $(CFLAGS) -c -ansi $<

