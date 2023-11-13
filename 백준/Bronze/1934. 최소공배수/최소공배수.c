#include <stdio.h>

int main()
{
    int T, A, B, a[50000] = { 0, }, b[50000] = { 0, }, value, h;

    scanf("%d", &T);

    for (int z = 0; z < T; z++)
    {
        scanf("%d %d", &A, &B);

        value = 1;

        h = 2;

        while (A != 1)
        {
            if (A % h == 0)
            {
                A /= h;
                a[h]++;
                continue;
            }

            h++;
        }

        h = 2;

        while (B != 1)
        {
            if (B % h == 0)
            {
                B /= h;
                b[h]++;
                continue;
            }

            h++;
        }

        for (int x = 0; x < 45000; x++)
        {
            if (a[x] > 0 || b[x] > 0)
            {
                if (a[x] > b[x])
                {
                    h = a[x];
                    for (int c = 0; c < h; c++)
                    {
                        value *= x;
                    }
                }
                else
                {
                    h = b[x];
                    for (int c = 0; c < h; c++)
                    {
                        value *= x;
                    }
                }
            }
            a[x] = 0;
            b[x] = 0;
        }

        printf("%d\n", value);
    }

    return 0;
}