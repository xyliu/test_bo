CC=gcc
CFLAGS=-g

SOURCES=heap1.c

all:heap1

heap1:heap1.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o heap1
	
