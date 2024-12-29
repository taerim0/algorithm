#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define pii pair<int, int>

using namespace std;

int W, H, N;
int dp[601][601];

int solve(int n, int m)
{
  if (dp[n][m] != -1) return dp[n][m];
  dp[n][m] = n * m;
  for (int i = 1; i <= n - i; i++)
    dp[n][m] = min(dp[n][m], solve(i, m) + solve(n - i, m));
  for (int i = 1; i <= m - i; i++)
    dp[n][m] = min(dp[n][m], solve(n, i) + solve(n, m - i));
  return dp[n][m];
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> W >> H >> N;

  for (int i = 0; i <= H; i++)
    for (int j = 0; j <= W; j++)
      dp[i][j] = -1;

  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    dp[b][a] = 0;
  }

  cout << solve(H, W);
}