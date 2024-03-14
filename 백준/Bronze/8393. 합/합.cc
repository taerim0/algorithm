#include <stdio.h>

int main()
{

    int n;
    int value = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        value = value + (i+1);
    }
    printf("%d", value);

    return 0;
}
