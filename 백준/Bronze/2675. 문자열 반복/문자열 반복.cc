#include <stdio.h>

int main()
{
	int T, R;
	char S[50];
    
	scanf("%d", &T);

	for (int z = 0; z < T; z++)
	{
		scanf("\n%d %s", &R, &S);

		for (int x = 0; x < 50; x++)
		{
			if (S[x] == NULL)
			{
				printf("\n");
				break;
			}
			for (int c = 0; c < R; c++)
			{
				printf("%c", S[x]);
			}
		}
	}

	return 0;
}