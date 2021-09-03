#include <iostream>

int main()
{
	int arr[20];
	int max1 = 0, max2 = 0;
	int num1 = 0, num2 = 0;
	int temp = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 10; i < 20; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 10; i < 20; i++)
	{
		for (int j = i + 1; j < 20; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("%d\n", arr[0] + arr[1] + arr[2]);
	printf("%d\n", arr[10] + arr[11] + arr[12]);
	{

	}
}