#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

char field[12][6];
bool exploded = true;
int cnt, chain = -1;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void count_puyo(pii start, char key) {
  queue<pii> q;
  bool check[12][6] = { 0 };
  check[start.first][start.second] = true;
  q.push(start);
  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int dn = y + dy[i];
      int dm = x + dx[i];

      if (dn < 0 || dn >= 12 || dm < 0 || dm >= 6)
        continue;
      if (check[dn][dm] || field[dn][dm] != key)
        continue;
      cnt++;
      check[dn][dm] = true;
      q.push({ dn, dm });
    }
  }
}

void exploding(pii start, char key) {
  queue<pii> q;
  field[start.first][start.second] = '.';
  q.push(start);
  while (q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int dn = y + dy[i];
      int dm = x + dx[i];

      if (dn < 0 || dn >= 12 || dm < 0 || dm >= 6)
        continue;
      if (field[dn][dm] != key)
        continue;
      field[dn][dm] = '.';
      q.push({ dn, dm });
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> field[i][j];
    }
  }

  while (exploded) {
    chain++;
    exploded = false;
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 6; j++) {
        if (field[i][j] != '.') {
          cnt = 1;
          count_puyo({ i, j }, field[i][j]);
          if (cnt > 3) {
            exploded = true;
            exploding({ i, j }, field[i][j]);
          }
        }
      }
    }

    for (int i = 10; i >= 0; i--) {
      for (int j = 0; j < 6; j++) {
        if (field[i][j] != '.' && field[i + 1][j] == '.') {
          while (i + 1 < 12 && field[i + 1][j] == '.') {
            field[i + 1][j] = field[i][j];
            field[i][j] = '.';
            i++;
          }
        }
      }
    }
  }

  cout << chain;
}