/* demonstrates static pointer overflow in bss (uninitialized data) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 16
#define ADDRLEN 4 /* # of bytes in an address */

int main()
{
	u_long diff;
	static char *bufptr0;
	static char buf[BUFSIZE];
	static char *bufptr;
	bufptr0 = bufptr = buf, diff = (u_long)&bufptr - (u_long)buf;

	printf("bufptr (%p) = %p, buf = %p, diff = 0x%x (%d) bytes\n",
			&bufptr, bufptr, buf, diff, diff);
	printf("bufptr0 (%p) = %p\n", &bufptr0, bufptr0);

	memset(buf, 'A', (u_int)(abs(diff) + ADDRLEN));

	printf("bufptr (%p) = %p, buf = %p, diff = 0x%x (%d) bytes\n", 
			&bufptr, bufptr, buf, diff, diff);
	printf("bufptr0 (%p) = %p, buf2 = %p, diff = 0x%x (%d) bytes\n", 
			&bufptr0, bufptr0, buf, diff, diff);

	return 0;
}
