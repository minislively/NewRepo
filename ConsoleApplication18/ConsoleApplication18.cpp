#include <iostream>

int main()
{
	int n;

	scanf("%d", &n);

	if (n >= 2)
	{
		for (int i = 1; i < n; i++)
		{
			printf(" ");
		}
	}
	if (n >= 1)
	{
		printf("*\n");
	}

	for (int i = 2; i <= n; i++)
	{
		for (int k = i; k < n; k++)
		{
			printf(" ");
		}
		printf("*");
		for (int m = 1; m <= 2 * (i - 1) - 1; m++)
		{
			printf(" ");
		}
		printf("*\n");

	}
}