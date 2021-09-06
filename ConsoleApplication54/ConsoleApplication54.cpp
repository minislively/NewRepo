#include <iostream>

int main()
{
	int a, sum = 0;

	scanf("%d", &a);

	for (int i = 1; i <= a; i++)
	{
		sum = sum + i;

		if (sum >= a)
		{
			sum = i;
			break;
		}
	}
	printf("%d", sum);
}