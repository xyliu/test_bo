#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 16
#define OVERSIZE 8 /* overflow buf2 by OVERSIZE bytes */

int main()
{
	u_long diff;
	static char buf2[BUFSIZE];
	static char buf1[BUFSIZE];

	diff = (u_long)buf2 - (u_long)buf1;
	printf("buf1 = %p, buf2 = %p, diff = 0x%x bytes\n", buf1, buf2, diff);

	memset(buf1, 'A', BUFSIZE-1), buf1[BUFSIZE-1] = '\0';

	printf("before overflow: buf1 = %s\n", buf1);
	memset(buf2, 'B', (u_int)(-diff + OVERSIZE));
	printf("after overflow: buf2 = %s\n", buf1);

	return 0;
}
