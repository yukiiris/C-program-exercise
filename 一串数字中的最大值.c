#include <stdio.h>
//#include <string.h>
int min = 9, max = 0;
int Max(long int n);
int Min(long int n);
int main(void)
{
	long int num;
	printf("���������ѧ��:");
	scanf("%ld", &num);
	printf("��ѧ�������������ǣ�%d\n", Max(num));
	printf("��ѧ������С�������ǣ�%d\n", Min(num));
	
	/*while (i >= 0)
	{
		if ((num % dp) > max)
			max = num % dp;printf("!%d\n",num % dp);
		if ((num % dp) < min)
			min = num % dp;
		num = (num - (num % dp) * (dp / 10)) / 10;
		i--;
		//dp *= 10;
		printf("%ld\n",num);
	}

	printf("max %d\nmin %d", max, min);*/
	return 0;
}
int Max(long int n)
{
	if (n / 10 > 0)
		Max(n / 10);
	if (n % 10 > max)
		max = n % 10;
	
	
	return max;
}
int Min(long int n)
{
	if (n / 10 > 0)
		Min(n / 10);
	if (n % 10 < min)
		min = n % 10;
	
	return min;
}
