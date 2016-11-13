#include<stdio.h>
void turn(double a[], int n);
int main(void)
{
	double a[] = { 1.1, 2.2, 3.3, 4.4 };
	turn(a, 4);
	printf("%f,%f,%f,%f\n", a[1], a[2], a[3], a[4]);
	
	return 0;
}

void turn(double a[], int n)
{
	int m;
	double mid;
	
	for (m = 0; m < (n / 2); m++)
	{
		mid = *(a + m);
		*(a + m) = *(a + n - m);
		*(a + n - m) = mid;
	}
}
