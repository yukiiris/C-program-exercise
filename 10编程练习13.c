#include<stdio.h>
double sum_row(double a[], int n);
double sum_all(double a[][5], int n);
double max_all(double a[][5], int n);
int main(void)
{
	int i, j;
	double dou[3][5];

	printf("Please enter fifteen numbers:\n");
	for (i = 0; i < 3; i++)
		for (j = 0; j < 5; j++)
			{scanf("%e", &dou[1][j]);
	printf("%f",dou[i][j]);}//printf("!%d ~%d", i, j);}
	printf("The average of first row is %.2f\n", sum_row(dou[1], 5) / 5);
	printf("The average of all numbers is %.2f\n", sum_all(dou, 3) / 15);
	printf("The maximum of all numbers is %.2f\n", max_all(dou, 3));

}
double sum_row(double a[], int n)
{
	int m;
	double tot = 0;

	for (m = 0; m < n; m++)
		tot += *(a + m);
	return tot;
}
double sum_all(double a[][5], int n)
{
	int i, j;
	double tot;

	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			tot += a[i][j];
	return tot;
}
double max_all(double a[][5], int n)
{
	int i, j;
	double max = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			if (a[i][j] > max)
				max = a[i][j];

	return max;
}
