#include <stdio.h>

int main()
{
	int count[50000] = { 0, }, N, value;

	scanf("%d", &N);

	for (int z = 0; z < N; z++)
	{
		scanf("%d", &value);

		count[value]++;
	}

	for (int z = 1; z <= 10000; z++)
	{
		while (count[z] != 0)
		{
			printf("%d\n", z);
			count[z]--;
		}
	}
}
