CC = gcc
CFLAGS = -Wall

all: isort txtfind

isort: mains.o isort.o
	$(CC) $(CFLAGS) -o isort mains.o isort.o

txtfind: maint.o txtfind.o
	$(CC) $(CFLAGS) -o txtfind maint.o txtfind.o

maint.o: maint.c
	$(CC) $(CFLAGS) -c maint.c

mains.o: mains.c
	$(CC) $(CFLAGS) -c mains.c

isort.o: isort.c isort.h
	$(CC) $(CFLAGS) -c isort.c

txtfind.o: txtfind.c txtfind.h
	$(CC) $(CFLAGS) -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o  txtfind isort