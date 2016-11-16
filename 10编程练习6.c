#include <stdio.h>
#define N 8
int main(void)
{
	int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int i, n;
	int * j;

	for (i = 0, j = a; i < (N / 2); i++)
	{
		n = j[i];
		j[i] = j[N - 1 - i];
		j[N - 1 - i] = n;
	}
	
	for (i = 0; i < N; i++)
		printf("%d ", *(a + i));

	return 0;
}
