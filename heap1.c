/* demonstrates dynamic overflow in heap (initialized data) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 16
#define OVERSIZE 8 /* overflow buf2 by OVERSIZE bytes */

int main()
{
	unsigned diff;
	char *buf1 = (char *)malloc(BUFSIZE), *buf2 = (char *)malloc(BUFSIZE);

	diff = (size_t)buf2 - (size_t)buf1;
	printf("buf1[%p] = %p, buf2[%p] = %p, diff = 0x%x bytes\n", &buf1, buf1, &buf2, buf2, diff);

	memset(buf2, 'A', BUFSIZE-1), buf2[BUFSIZE-1] = '\0';

	printf("before overflow: buf2 = %s\n", buf2);
	memset(buf1, 'B', (u_int)(diff + OVERSIZE));
	printf("after overflow: buf2 = %s\n", buf2);

	return 0;
}

