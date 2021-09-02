#include <iostream>

int main()
{
	int arr[9][9];
	int max = 0;
	int n = 0, m = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				m = i + 1;
				n = j + 1;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", m, n);
}