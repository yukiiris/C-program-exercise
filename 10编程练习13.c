#include <stdio.h>
double sum_row(float a[], int n);
double sum_all(float a[][5], int n);
double max_all(float a[][5], int n);
int main(void)
{
	int i, j;
	float a[3][5] = {0};

	printf("Please enter fifteen numbers:\n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			scanf("%f", &a[i][j]);
	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			printf("%f\n", a[i][j]);
	printf("The average of first row is %.2f\n", sum_row(a[1], 5) / 5);
	printf("The average of all numbers is %.2f\n", sum_all(a, 3) / 15);
	printf("The maximum of all numbers is %.2f\n", max_all(a, 3));

}
double sum_row(float a[], int n)
{
	int m;
	double tot = 0;
	for (m = 0; m < n; m++)
		tot += *(a + m);
	return tot;
}
double sum_all(float a[][5], int n)
{
	int i, j;
	double tot = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			tot += a[i][j];
	return tot;
}
double max_all(float a[][5], int n)
{
	int i, j;
	double max = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			if (a[i][j] > max)
				max = a[i][j];

	return max;
}

