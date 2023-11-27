#include <stdio.h>

int N, M, arr[10], k = 0;

void printseq(int size)
{
	for (int z = 0; z < size; z++)
	{
		printf("%d ", arr[z]);
	}
	printf("\n");
}

int calcul(int n)
{
	if (n == M)
	{
		printseq(n);
		return 1;
	}

	for (int z = 1; z <= N; z++)
	{
		k = 0;

		for (int x = 0; x < n; x++)
		{
			if (z == arr[x])
			{
				k = 1;
			}
		}

		if (k == 1) continue;

		arr[n] = z;

		calcul(n + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	calcul(0);
}