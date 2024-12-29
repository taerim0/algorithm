// 모르겟다

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define INF 1e9
#define pii pair<int, int>

using namespace std;

int X, Y, D;
int N, t;
pii ans = { INF, 0 };
int dp[101][100001];
int item_cnt, item[101];

void calcul()
{
  for (int j = D / Y; j >= 1; j--) {
    for (int i = item_cnt; i >= 1; i--) {
      if (dp[i][j] / X <= D && dp[i][j] / X > 0) {
        if (dp[i][j] / X > ans.second) {
          ans = { dp[i][j], dp[i][j] / X };
        }
        else if (dp[i][j] / X == ans.second && dp[i][j] < ans.first) {
          ans = { dp[i][j], dp[i][j] / X };
        }
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> X >> Y >> D;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    item_cnt += a;
    while (a--) {
      item[++t] = b;
    }
  }

  for (int i = 1; i <= item_cnt; i++) {
    for (int j = 1; j <= D / Y; j++) {
      if (j >= item[i] / X) {
        if ((dp[i - 1][j - item[i] / X] + item[i]) / X > j) {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i] / X - 1] + item[i]);
        }
        else {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i] / X] + item[i]);
        }
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  for (int i = 1; i <= item_cnt; i++) {
    for (int j = 1; j <= D / Y; j++) {
      cout << dp[i][j] << ' ';
    }
    cout << "\n";
  }

  calcul();

  cout << ans.first;
}