#include <iostream>

int main()
{
	int n, num = 0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) // 색깔 겹치지 않게
	{
		for (int j = i + 1; j <= n; j++) // 얘도 
		{
			i* j;
			num++;
		}
	}
	printf("%d", 2 * num); // 2는 바지, 티셔츠 숫자 
}