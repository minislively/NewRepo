#include <iostream>

int print(int n);

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", print(n));

}

int d[100];

int print(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (d[n] != 0) return d[n];
	return print(n - 1) + print(n - 2);

}