#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

int N, M, C;
pii S;

int ans, nowLight = -1, nowVal;

int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> C >> S.first >> S.second;

  vector<vector<int>> cave(N, vector<int>(M));
  vector<vector<int>> check(N, vector<int>(M, -1));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> cave[i][j];
    }
  }
  
  queue<pii> q;
  nowVal = C;
  check[S.first - 1][S.second - 1] = 0;
  q.push({ S.first - 1, S.second - 1 });

  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();

    if (check[y][x] != nowLight) {
      nowLight = check[y][x];
      nowVal -= C;
    }
    nowVal += cave[y][x];
    ans = max(nowVal, ans);

    for (int i = 0; i < 4; i++) {
      int dn = y + dy[i];
      int dm = x + dx[i];

      if (dn < 0 || dn >= N || dm < 0 || dm >= M)
        continue;
      if (cave[dn][dm] == -1)
        continue;
      if (check[dn][dm] != -1)
        continue;

      check[dn][dm] = check[y][x] + 1;
      q.push({ dn, dm });
    }
  }

  cout << ans;
}