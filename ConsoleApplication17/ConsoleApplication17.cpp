#include <iostream>

int main()
{
	long long n, m;

	scanf("%lld %lld", &n, &m);

	if (n > m)
		printf("%lld", n - m);
	else
		printf("%lld", -n + m);

}