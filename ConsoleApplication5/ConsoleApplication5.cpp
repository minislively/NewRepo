#include <iostream>

int main()
{
	int a1, b1, c1;
	int a3, b3, c3;

	scanf("%d %d %d", &a1, &b1, &c1);
	scanf("%d %d %d", &a3, &b3, &c3);

	printf("%d %d %d", a3 - c1, b3 / b1, c3 - a1);

}