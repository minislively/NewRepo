#include <iostream>

int main()
{
	int n, i, s = 0;

	scanf("%d", &n);

	for (i = 1;; i++)
	{
		s += i;
		if (s >= n)
			break;
	}
	printf("%d", s);
}
