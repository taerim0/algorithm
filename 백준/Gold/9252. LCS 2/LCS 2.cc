#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string A, B;

vector<char> v;

int dp[1001][1001];
int maxcnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	int col = A.length();
	int row = B.length();

	for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++)
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	cout << dp[col][row] << "\n";

	while (dp[col][row])
		if (dp[col][row] == dp[col - 1][row])
			col--;
		else if (dp[col][row] == dp[col][row - 1])
			row--;
		else
			v.push_back(A[col - 1]), col--, row--;

	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
}