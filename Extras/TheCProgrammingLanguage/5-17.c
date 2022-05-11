#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercise 5-17 (P. 100)
 * Add to sort program a field-searching capability
 */

#define	MAXLINES	5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void lqsort(void *lineptr[], int left, int nlines, int (*comp)(void *, void *));
int numcmp(char *, char *);

int reverse = 0;

int main(int argc, char *argv[]) {

	int nlines;
	int numeric = 0;

	if (argc > 1 && (strcmp(argv[1], "-n") || strcmp(argv[2], "-n")) == 0) numeric = 1;
	if (argc > 1 && (strcmp(argv[1], "-r") || strcmp(argv[2], "-r")) == 0) reverse = 1;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

		lqsort((void**) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));

		writelines(lineptr, nlines);
		return 0;

	} else {

		printf("input too big to sort\n");
		return 1;

	}

}

void lqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {

	int i, last;

	void swap(void *v[], int, int);

	if (left >= right) return;

	swap(v, left, (left + right) / 2);
	last = left;

	for (i = left + 1; i <= right; i++) if ((*comp)(v[i], v[left]) < 0) swap(v, ++last, i);
	swap(v, left, last);

	lqsort(v, left, last - 1, comp);
	lqsort(v, last + 1, right, comp);

}

int numcmp(char *s1, char *s2) {

	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;

}

void swap(void *v[], int i, int j) {

	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;

}

void writelines(char *lineptr[], int nlines) {

	if (reverse) {
		for (int i = nlines; i >= 0; i--) printf("%s\n", *lineptr[i]);
	else
		for (int i = 0; i < nlines; i++) printf("%s\n", *lineptr[i]);

}

