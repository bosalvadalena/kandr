#
#	exercise6-1/Makefile
#

CC = /usr/bin/cc
CFLAGS =
PROGRAM = exercise6-1
OBJS = main.o getword.o escape.o

.SUFFIXES : .o .c

default : $(OBJS)
	$(CC) -o $(PROGRAM).out $(CFLAGS) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $<

clean :
	rm $(OBJS)
