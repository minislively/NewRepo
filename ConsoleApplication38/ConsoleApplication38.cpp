#include <iostream>

int main()
{
    char ch, t = 'a';

    scanf("%c", &ch);

    while (1)
    {

        printf("%c ", t++);

        if (t > ch)
            break;
    }
}