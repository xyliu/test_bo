CC=gcc
CFLAGS=-g

all:heap1 heap2 heap3 vulprog1 exploit01
heap1:heap1.c
	$(CC) $(CFLAGS) -o $@ $<
heap2:heap2.c
	$(CC) $(CFLAGS) -o $@ $<
heap3:heap3.c
	$(CC) $(CFLAGS) -o $@ $<
vulprog1:vulprog1.c
	$(CC) $(CFLAGS) -o $@ $<
exploit01:exploit01.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o heap1 heap2 heap3 vulprog1 exploit01
	
