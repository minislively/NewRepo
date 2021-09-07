#include <iostream>

int main()
{
	int n, num, cnt = 0;

	scanf("%d", &n);

	int i;

	while (n--)
	{
		scanf("%d", &num);
		for (i = 2; i < num; i++)
		{
			if (num % i == 0) break;
		}
		if (i == num) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}