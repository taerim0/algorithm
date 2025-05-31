#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

ll Q, N, now = 2;
ll dp[(int)1e7];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  dp[0] = 5; dp[1] = 20;

  cin >> Q; while (Q--) {
    cin >> N; while (now < N) {
      dp[now] = (dp[now - 1] * 5) % ((int)1e9 + 7);
      now++;
    }
    cout << dp[N - 1] << "\n";
  }
}