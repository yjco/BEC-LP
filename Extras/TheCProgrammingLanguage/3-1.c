#include <stdio.h>

/*
 * Exercise 3-1 (P. 52)
 * Write a version of binary search with only 1 test inside the loop
 */

int bins(int x, int v[], int n) {

	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;

	while (low <= high && x != v[mid]) {
		
		if (x < v[mid])
			high = mid + 1;

		else
			low = mid + 1;

		mid = (low + high) / 2;

	}

	if (x == v[mid])
		return mid;

	else
		return -1;
	

}

int main() {

	int a[] = { 3, 14, 25, 36, 47, 58, 69 };

	printf("At %d\n", bins(25, a, 7) + 1);

}

