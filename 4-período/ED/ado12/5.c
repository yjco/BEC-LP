#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 50
#define R (int)(N/2)

int even(int n) { return (n % 2 == 0) ? 1 : 0; }
int rnd() { return rand() % 101; }

int main() {

	srand(time(NULL));

	int* fighters = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) *(fighters+i) = rnd();

	int** fights = (int**)malloc(sizeof(int*) * R);
	for (int i = 0; i < R; i++) *(fights+i) = (int*)malloc(sizeof(int) * 2);

	int b = 0, m = 0;
	for (int i = 0, f = -1; i < N && b < R && m < R; i++) *(*(fights+((even(*(fighters+i)))?b++:m++))+(even(*(fighters+i)))) = *(fighters+i);

	int pairs = (b < m) ? b : m;
	if (!pairs) {
		printf("Rivality does not exist\n");
		return 1;
	}

	for (int i = 0; i < pairs; i++) printf("%d %d\n", *(*(fights+i)), *(*(fights+i)+1));
	printf(">>> %d fighters without a rival\n", 50-(pairs*2));

	return 0;

}
