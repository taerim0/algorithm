#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define pii pair<int, int>

using namespace std;
int a;
int R, C, N;
char cave[100][100];
int stick;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void cluster_update(pii pos)
{
  // a, b, c, d cluster
  int sy = pos.first, sx = pos.second;
  queue<pii> q;
  int check[100][100] = { 0 };

  for (int n = 0; n < 4; n++) {
    bool is_floating = true;
    int py = sy + dy[n];
    int px = sx + dx[n];
    if (py < 0 || py >= R || px < 0 || px >= C)
      continue;
    if (cave[py][px] == '.' || check[py][px])
      continue;
    q.push({ py, px });
    check[py][px] = n + 1;

    while (q.size()) {
      auto [y, x] = q.front();
      q.pop();

      if (y == R - 1) {
        is_floating = false;
      }

      for (int i = 0; i < 4; i++) {
        int dn = y + dy[i];
        int dm = x + dx[i];

        if (dn < 0 || dm < 0 || dn >= R || dm >= C)
          continue;

        if (cave[dn][dm] == '.')
          continue;

        if (check[dn][dm] == 0) {
          check[dn][dm] = n + 1;
          q.push({ dn, dm });
        }
      }
    }

    if (is_floating) {
      int floating_gap = 999;
      for (int j = 0; j < R - 1; j++) {
        for (int k = 0; k < C; k++) {
          if (check[j][k] == n + 1 && cave[j + 1][k] == '.') {
            for (int l = j + 2; l < R; l++) {
              if (cave[l][k] == 'x') {
                if (check[l][k] != n + 1)
                  floating_gap = min(floating_gap, l - j - 1);
                else
                  break;
              }
            }
            floating_gap = min(floating_gap, R - j - 1);
          }
        }
      }

      for (int j = R - 1; j >= 0; j--) {
        for (int k = C - 1; k >= 0; k--) {
          if (check[j][k] == n + 1) {
            cave[j + floating_gap][k] = 'x';
            cave[j][k] = '.';
          }
        }
      }

      return;
    }
  }
}

void stick_throw(bool is_left)
{
  int s = is_left ? 0 : C - 1;
  int e = is_left ? C - 1 : 0;

  for (int i = s; (is_left ? i <= e : i >= e); is_left ? i++ : i--) {
    if (cave[R - stick][i] == 'x') {
      cave[R - stick][i] = '.';
      cluster_update({ R - stick, i });
      return;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> cave[i][j];
    }
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> stick;
    stick_throw((i + 1) % 2);
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << cave[i][j];
    }
    cout << "\n";
  }
}