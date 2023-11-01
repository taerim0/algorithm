#include <iostream>
#include <queue>

using namespace std;

int N;

int ans = 2e9;

int cost[1000][3];
int dp[1000][3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == k)
				dp[0][i] = cost[0][i];
			else
				dp[0][i] = 2e9;
		}

		for (int i = 1; i < N; i++)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int i = 0; i < 3; i++)
		{
			if (i != k)
				ans = min(ans, dp[N - 1][i]);
		}
	}

	cout << ans;
}
