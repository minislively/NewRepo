#include <iostream>

int main()
{
	char ch[30]; 

	for (int i = 0; i < 30; i++)
	{
		scanf("%c", &ch[i]);
		if (ch[i] == 'q')
			break;
		printf("%c\n", ch[i]);
	}
}