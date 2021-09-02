#include <iostream>

int main()
{
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);

	while (1)
	{
		if (b + c >= 60)
			printf("%d %d", a++, 60 - (b + c));
		if (b + c >= 0 && b + c < 60)
			break;
		else
		{
			printf("%d %d", a, b + c);
			break;
		}
	}
}