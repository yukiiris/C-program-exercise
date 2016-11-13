#include<stdio.h>
void copy_ptr(double x[], double y[], int n);
void copy_arr(double * x, double * y, int n);
void copy_ptrs(double * x, double * y, double * z);
int main(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5] = {0};
	double target2[5] = {0};
	double target3[5] = {0};

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);
	printf("source :\t%g\t%g\t%g\t%g\t%g\n",source[0],source[1],source[2],source[3],source[4]);
 	printf("target1:\t%g\t%g\t%g\t%g\t%g\n",target1[0],target1[1],target1[2],target1[3],target1[4]);
 	printf("target2:\t%g\t%g\t%g\t%g\t%g\n",target2[0],target2[1],target2[2],target2[3],target2[4]);
	printf("target3:\t%g\t%g\t%g\t%g\t%g\n",target3[0],target3[1],target3[2],target3[3],target3[4]);

	return 0;
}

void copy_arr(double x[], double y[], int n)
{ 
	int m = 0;
	for (m = 0; m < n; m++)
		x[m] = y[m];
}
void copy_ptr(double * x, double * y, int n)
{
	int m;
	for (m = 0; m < n; m++)
	{
		*x = *y;
		x++;
		y++;
	}
}
void copy_ptrs(double * x, double * y, double * z)
{
	while (y < z)
	{
		*x = *y;
		x++;
		y++;
	}
}

