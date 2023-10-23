#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

string str;
int cnt = 1;

bool dp[2500][2500];
int ans[2500];
bool isdup;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		dp[i][i] = true;

		if (i && str[i - 1] == str[i])
		{
			dp[i - 1][i] = true;
		}
	}

	for (int i = 3; i <= str.length(); i++)
	{
		for (int j = i - 1; j < str.length(); j++)
		{
			if (dp[j - (i - 2)][j - 1] && str[j - (i - 1)] == str[j])
			{
				dp[j - (i - 1)][j] = true;
			}
		}
	}

	//for (int i = 0; i < str.length(); i++)
	//{
	//	for (int j = 0; j < str.length(); j++)
	//	{
	//		if (dp[i][j])
	//			cout << "1 ";
	//		else
	//			cout << "0 ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < str.length(); i++)
	{
		if (dp[0][i])
			ans[i] = 1;
		else
		{
			ans[i] = ans[i - 1] + 1;
			for (int j = 1; j < i; j++)
				if (dp[j][i])
					ans[i] = min(ans[i], ans[j - 1] + 1);
		}
	}

	//cout << "\n";

	//for (int i = 0; i < str.length(); i++)
	//	cout << ans[i] << " ";

	//cout << "\n";

	cout << ans[str.length() - 1];
}