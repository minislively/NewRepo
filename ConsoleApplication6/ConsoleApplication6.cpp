#include <iostream>

int main()
{
	int n, t, c, p, num = 0;

	scanf("%d %d %d %d", &n, &t, &c, &p);

	for (int i = 1; i <= n; i++)
	{
		if (t * i < n) // 1<=t<=n-1, n일이 지나면 바로 시들어버림
			num = num + c;

		else
			break;
	}
	printf("%d", num * p);
}