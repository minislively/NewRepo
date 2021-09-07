#include <iostream>

int main()
{
	int m, n, cnt = 0, result = 0, min = 10001;

	scanf("%d %d", &m, &n);

	for (int i = m; i <= n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				cnt++;
		}
		if (cnt == 0 && i != 1)
		{
			result += i;
			if (min > i)
				min = i;
		}
		cnt = 0;
	}
	if (min == 10001)
		printf("-1\n");
	else
		printf("%d\n%d\n", result, min);
}