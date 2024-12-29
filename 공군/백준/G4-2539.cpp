// 간단한 이분탐색. ez

#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int N, M, a, b;
vector<pii> wrong_tiles;

bool solve(int p)
{
  int last_paper = -1e7;
  int paper_use = 0;

  for (int i = 0; i < b; i++) {
    if (wrong_tiles[i].second > p)
      return false;
    
    if (last_paper + p - 1 >= wrong_tiles[i].first) {
      continue;
    }
    else {
      last_paper = wrong_tiles[i].first;
      paper_use++;
      if (paper_use > a)
        return false;
    }
  }

  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> a >> b;

  wrong_tiles.resize(b);

  for (int i = 0; i < b; i++) {
    int y, x; cin >> y >> x;
    wrong_tiles[i] = { x, y };
  }

  sort(wrong_tiles.begin(), wrong_tiles.end());

  int s = 0, e = 1e6;
  int m;
  while (s <= e) {
    m = (s + e) / 2;
    if (solve(m))
      e = m - 1;
    else
      s = m + 1;
  }

  cout << e + 1;
}