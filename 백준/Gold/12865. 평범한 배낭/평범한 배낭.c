#include <stdio.h>

int w[101], v[101], dp[101][100001], N, K;

int main()
{
	scanf("%d %d", &N, &K);

	for (int z = 1; z <= N; z++)
	{
		scanf("%d %d", &w[z], &v[z]);
	}

	for (int z = 1; z <= N; z++)
	{
		for (int x = 1; x <= K; x++)
		{
			if (x - w[z] >= 0)
			{
				if (dp[z - 1][x] >= dp[z - 1][x - w[z]] + v[z]) dp[z][x] = dp[z - 1][x];
				else dp[z][x] = dp[z - 1][x - w[z]] + v[z];
			}
			else dp[z][x] = dp[z - 1][x];
		}
	}

	printf("%d", dp[N][K]);
}