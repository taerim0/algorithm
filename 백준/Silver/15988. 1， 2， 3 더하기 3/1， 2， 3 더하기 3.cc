#include <iostream>

#define ll long long

using namespace std;

int T;
int n, i = 4;

ll dp[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	while (T--)
	{
		cin >> n;

		for (; i <= n; i++)
			dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

		cout << dp[n] << "\n";
	}
}