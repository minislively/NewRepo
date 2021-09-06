#include <iostream>

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a * 1 + b * 2 + c * 3 >= 10)
		printf("happy");
	else
		printf("sad");
}