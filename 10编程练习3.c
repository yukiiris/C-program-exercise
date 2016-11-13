int Max(int a[], int n)
{
	int max, m;

	for (max = *a, m = 1; m < n; m++)
	{
		if (*(a + m) > max)
			max = *(a + m);
	}
	
	return max;
}
