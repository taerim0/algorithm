#include <iostream>

using namespace std;

int n;

int dp[16];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	if (n % 2)
	{
		cout << 0; return 0;
	}

	dp[1] = 3;
	dp[2] = 11;

	for (int i = 3; i <= n / 2; i++)
	{
		dp[i] += dp[i - 1] * 3 + 2;
		
		for (int j = i - 2; j >= 1; j--)
		{
			dp[i] += dp[j] * 2;
		}
	}

	cout << dp[n / 2];
}