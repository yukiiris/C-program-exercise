#include<stdio.h>
int Max(double a[], int n);
int main(void)
{
	double a[] = { 1.2, 45.3, 23.4, 65.4 };
	printf("%d\n", Max(a, 4));
	
	return 0;
}

int Max(double a[], int n)
{
	int m, M = 0;
	double max;

	for (m = 0, max = *a; m < n; m++)
	{
		if (*(a + m) > max)
			M = m + 1;
	}
	return M;
}
