#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
 * Exercise 8-1 (P. 142)
 * Rewrite cat with read, write, open and close
 */

int main(int argc, char *argv[]) {

	if (argc < 2) exit(1);

	char buf[BUFSIZ];
	int n;

	int fd = open(argv[1], O_RDONLY, 0);
	
	while ((n = read(fd, buf, BUFSIZ)) > 0) write(1, buf, n);
	return 0;

}

