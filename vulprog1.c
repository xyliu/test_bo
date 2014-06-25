/*
 * This is a typical vulnerable program.  It will store user input in a
 * temporary file.
 *
 * Compile as: gcc -o vulprog1 vulprog1.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define ERROR -1
#define BUFSIZE 16

/*
 * Run this vulprog as root or change the "vulfile" to something else.
 * Otherwise, even if the exploit works, it won't have permission to
 * overwrite /root/.rhosts (the default "example").
 */

int main(int argc, char **argv)
{
	FILE *tmpfd;
	static char buf[BUFSIZE], *tmpfile;

	if (argc <= 1)
	{
		fprintf(stderr, "Usage: %s <garbage>\n", argv[0]);
		exit(ERROR);
	}

	tmpfile = "/tmp/vulprog.tmp"; /* no, this is not a temp file vul */
	printf("before: tmpfile = %s\n", tmpfile);

	printf("Enter one line of data to put in %s: ", tmpfile);
	gets(buf);

	printf("\nafter: tmpfile = %s\n", tmpfile);

	tmpfd = fopen(tmpfile, "w");
	if (tmpfd == NULL)
	{
		fprintf(stderr, "error opening %s: %s\n", tmpfile, 
				strerror(errno));

		exit(ERROR);
	}

	fputs(buf, tmpfd);
	fclose(tmpfd);
}

