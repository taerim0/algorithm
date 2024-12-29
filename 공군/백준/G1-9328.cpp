#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>

#define pii pair<int, int>

using namespace std;

int T, h, w;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T; while (T--) {
    int keys = 0, ans = 0;
    char map[102][102] = { 0 };
    int check[102][102] = { 0 };
    memset(check, -1, sizeof(check));
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> map[i][j];
      }
    }
    string key; cin >> key;
    if (key[0] != '0')
    for (auto ky : key) {
      keys |= 1 << (ky - 'a');
    }

    deque<pii> dq;
    dq.push_back({ 0, 0 });

    while (dq.size()) {
      auto [y, x] = dq.front();
      dq.pop_front();

      if (map[y][x] >= 'A' && map[y][x] <= 'Z')
        if (!((keys >> (map[y][x] - 'A') & 1)))
          continue;

      for (int i = 0; i < 4; i++) {
        int dn = y + dy[i];
        int dm = x + dx[i];

        if (dn < 0 || dm < 0 || dn > h + 1 || dm > w + 1)
          continue;

        if (map[dn][dm] == '*')
          continue;

        if (check[dn][dm] == keys)
          continue;

        check[dn][dm] = keys;
        if (map[dn][dm] >= 'A' && map[dn][dm] <= 'Z')
          dq.push_back({ dn, dm });
        else { 
          if (map[dn][dm] == '$')
            ans++;
          if (map[dn][dm] >= 'a' && map[dn][dm] <= 'z')
            keys |= 1 << (map[dn][dm] - 'a'), check[dn][dm] = keys;
          map[dn][dm] = '.';
          dq.push_front({ dn, dm });
        }
      }
    }

    cout << ans << '\n';
  }
}