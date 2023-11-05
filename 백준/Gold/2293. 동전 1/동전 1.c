#include <stdio.h>
#include <stdlib.h>

int coin[101];
double dp[10001];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	for (int z = 1; z <= n; z++)
	{
		scanf("%d", &coin[z]);
	}

	dp[0] = 1;

	for (int z = 1; z <= n; z++)
	{
		for (int x = coin[z]; x <= k; x++)
		{
			dp[x] += dp[x - coin[z]];
		}
	}

	printf("%.lf", dp[k]);
}
