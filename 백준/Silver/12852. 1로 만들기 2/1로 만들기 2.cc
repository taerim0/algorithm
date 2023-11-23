#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N;
int dp[1000001];
int adj[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		adj[i] = i - 1;

		if (i % 2 == 0)
			if (dp[i / 2] + 1 < dp[i])
				dp[i] = dp[i / 2] + 1, adj[i] = i / 2;
		if (i % 3 == 0)
			if (dp[i / 3] + 1 < dp[i])
				dp[i] = dp[i / 3] + 1, adj[i] = i / 3;
	}

	cout << dp[N] << "\n";

	int temp = N;

	while (temp != 1)
	{
		cout << temp << " ";
		temp = adj[temp];
	}
	cout << 1;
}