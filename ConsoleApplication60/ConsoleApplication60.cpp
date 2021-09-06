#include <iostream>

int main()
{
	int a, b, c, sum = 0;

	scanf("%d %d %d", &a, &b, &c);

	sum = (a + 1) * (b + 1) / (c + 1) - 1;

	printf("%d", sum);
}