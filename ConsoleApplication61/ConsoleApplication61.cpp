#include <iostream>

int main()
{
	int a;

	scanf("%d", &a);

	int sum1 = a * 0.22;
	int sum2 = a * 0.8 + a - (a * 0.8) - (a - a * 0.8) * 0.22;

	printf("%d %d", a - sum1, sum2);
}