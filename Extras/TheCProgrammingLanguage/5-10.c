#include <stdio.h>

/*
 * Exercise 5-10 (P. 98)
 * Write a program to evaluate a reverse Polish expression
 */

void put(char c);
int pop();

int main(int argc, char *argv[]) {

	int i = 0, j = 0;

	while (i++ < argc - 1) {

		switch ((char)*argv[i]) {

			case '+' :
				j = pop() + pop();
				put(j + '0');
				printf("%d\n", j);
				break;

			case '-' :
				j = pop() - pop();
				put(j + '0');
				printf("%d\n", j);
				break;

			default :
				put((int)*argv[i]);
				break;

		}

	}

}

#define	MAXBUF	100
int buf[MAXBUF];
int bufs = 0;

void put(char c) {

	if (bufs == MAXBUF) printf("Error: Buf is full\n");;
	buf[bufs++] = c - '0';

}

int pop() {
	
	return buf[--bufs];

}

