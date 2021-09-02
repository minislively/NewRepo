#include <iostream>

int main()
{
	int arr[3];
	int temp = 0;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", arr[i]);
	}
}