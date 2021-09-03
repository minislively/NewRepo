#include <iostream>

int main()
{
	int a;

	scanf("%d", &a);

	if (a >= 90 && a <= 100)
	{
		printf("%c", 'A');
	}
	else
	{
		if (a >= 70 && a <= 89)
		{
			printf("%c", 'B');
		}
		else
		{
			if (a >= 40 && a <= 69)
			{
				printf("%c", 'C');
			}
			else
			{
				if(a>=0 && a<=39)
					printf("%c", 'D');
			}
		}
	}
}