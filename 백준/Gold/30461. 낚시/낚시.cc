#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int N, M, Q;

int fish;
int power[2001][2001];
int dp[2001][2001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> Q;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> fish;

			power[i][j] = power[i - 1][j] + fish;
			dp[i][j] = power[i][j] + dp[i - 1][j - 1];
		}
	}

	while (Q--)
	{
		cin >> N >> M;

		cout << dp[N][M] << "\n";
	}
}