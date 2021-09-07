#include <iostream>

int main()
{
	int a;
	double x;

	scanf("%d", &a);

	for (int i = 0; i < a; i++)
	{
		scanf("%lf", &x);
		printf("$%.2lf\n", x - x * 0.2);
	}

}