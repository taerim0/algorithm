#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N, M;
int water;
char pool[50][50];
bool is_water_exist[50][50];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

bool bfs(int height, pii pos)
{
  queue<pii> q;
  bool chk[50][50];
  memset(chk, false, sizeof(chk));
  
  q.push(pos);
  chk[pos.first][pos.second] = true;

  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int dn = y + dy[i];
      int dm = x + dx[i];

      if (dn < 0 || dm < 0 || dn >= N || dm >= M)
        return false;

      if (chk[dn][dm] || pool[dn][dm] - '0' >= height)
        continue;

      chk[dn][dm] = true;
      q.push({ dn, dm });
    }
  }

  return true;
}

void water_fill(int height, pii pos)
{
  bool chk[50][50];
  memset(chk, false, sizeof(chk));
  queue<pii> q;
  
  q.push(pos);
  chk[pos.first][pos.second] = true;

  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();

    water += height - (pool[y][x] - '0');
    is_water_exist[y][x] = true;

    for (int i = 0; i < 4; i++) {
      int dn = y + dy[i];
      int dm = x + dx[i];

      if (dn < 0 || dm < 0 || dn >= N || dm >= M)
        continue;

      if (chk[dn][dm] || pool[dn][dm] - '0' >= height)
        continue;

      chk[dn][dm] = true;
      q.push({ dn, dm });
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> pool[i][j];
    }
  }

  for (int i = 9; i > 1; i--) {
    for (int j = 1; j < N - 1; j++) {
      for (int k = 1; k < M - 1; k++) {
        if (pool[j][k] - '0' >= i || is_water_exist[j][k])
          continue;

        if (bfs(i, { j, k })) {
          water_fill(i, { j, k });
        }
      }
    }
  }

  cout << water;
}