#include <iostream>

int main()
{
	int arr1[100][100];
	int arr2[100][100];
	int arr3[100][100];
	int a = 0, b = 0;

	scanf("%d %d", &a, &b);

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			scanf("%d", &arr2[i][j]);
		}
	}


	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr3[i][j] = arr1[i][j] + arr2[i][j];
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
}