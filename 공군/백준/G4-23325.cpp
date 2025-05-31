#include <iostream>
#include <cstring>

using namespace std;

string s;
int dp[4][200000];
bool check[4][200000];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> s;

  if (s[0] == '+')
    dp[1][0] = 10;
  else dp[1][0] = 1;
  check[1][0] = true;
  
  for (int i = 1; i < s.size(); i++) {
    int now[4] = { (int)-1e8, (int)-1e8, (int)-1e8, (int)-1e8 };
    if (s[i] == '+') {
      if (check[1][i - 1]) {
        now[0] = max(now[0], dp[1][i - 1]);
        check[0][i] = true;
      }
      if (check[2][i - 1]) {
        now[0] = max(now[0], dp[2][i - 1]);
        check[0][i] = true;
      }
      if (check[3][i - 1]) {
        now[0] = max(now[0], dp[3][i - 1]);
        check[0][i] = true;
      }

      if (check[0][i - 1]) {
        dp[(s[i - 1] == '+') ? 1 : 2][i] = dp[0][i - 1] + ((s[i - 1] == '+') ? 10 : -10);
        check[(s[i - 1] == '+') ? 1 : 2][i] = true;
      }

      if (check[0][i]) dp[0][i] = now[0];
    }
    else {
      if (check[1][i - 1]) {
        if (s[i - 1] == '+') {
          now[3] = max(now[3], dp[1][i - 1] + 1);
          check[3][i] = true;
        }
        now[0] = max(now[0], dp[1][i - 1]);
        check[0][i] = true;
      }

      if (check[2][i - 1]) {
        if (s[i - 1] == '+') {
          now[3] = max(now[3], dp[2][i - 1] - 1);
          check[3][i] = true;
        }
        now[0] = max(now[0], dp[2][i - 1]);
        check[0][i] = true;
      }

      if (check[3][i - 1]) {
        now[0] = max(now[0], dp[3][i - 1]);
        check[0][i] = true;
      }

      if (check[0][i - 1]) {
        dp[(s[i - 1] == '+') ? 1 : 2][i] = dp[0][i - 1] + ((s[i - 1] == '+') ? 1 : -1);
        check[(s[i - 1] == '+') ? 1 : 2][i] = true;
      }

      if (check[0][i]) dp[0][i] = now[0];
      if (check[3][i]) dp[3][i] = now[3];
    }
  }

  int ans = -1e9;

  for (int i = 1; i < 4; i++) {
    if (check[i][s.size() - 1]) {
      ans = max(ans, dp[i][s.size() - 1]);
    }
  }

  cout << ans;
}