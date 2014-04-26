CC=gcc
CFLAGS=-g

all:heap1 heap2 heap3 vulpro1.c
heap1:heap1.c
	$(CC) $(CFLAGS) -o $@ $<
heap2:heap2.c
	$(CC) $(CFLAGS) -o $@ $<
heap3:heap3.c
	$(CC) $(CFLAGS) -o $@ $<
vulpro1:vulpro1.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o heap1 heap2 heap3 vulpro1
	
