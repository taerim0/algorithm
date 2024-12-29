#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define pii pair<int, int>

using namespace std;

int w, h, ps;

int dist[11][10];
int answer;
int Pcheck[10];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void make_P(int cur)
{
  bool isDone = true;
  for (int i = 1; i < ps; i++) {
    if (Pcheck[i - 1] != -1) continue;
    isDone = false;
    Pcheck[i - 1] = cur;
    make_P(i);
    Pcheck[i - 1] = -1;
  }
  if (isDone) {
    int temp = cur;
    int ans = dist[Pcheck[temp - 1]][temp - 1];
    for (int i = 1; i < ps; i++) {
      temp = Pcheck[temp - 1];
      ans += dist[Pcheck[temp - 1]][temp - 1];
    }
    answer = min(answer, ans);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (1) {
    char room[20][20] = { 0 };
    pii points[11];
    answer = 2e9;
    ps = 1;
    memset(dist, -1, sizeof(dist));
    memset(Pcheck, -1, sizeof(Pcheck));
    
    cin >> w >> h;

    if (!w && !h) break;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> room[i][j];

        if (room[i][j] == 'o')
          points[0] = { i, j };
        if (room[i][j] == '*')
          points[ps++] = { i, j };
      }
    }

    bool visit[10] = { 0 };
    
    for (int i = 0; i < ps; i++) {
      int check[20][20];
      memset(check, -1, sizeof(check));
      queue<pii> q;
      q.push(points[i]);
      check[points[i].first][points[i].second] = 0;

      while (q.size()) {
        auto [y, x] = q.front();
        q.pop();

        for (int j = 0; j < 4; j++) {
          int dn = y + dy[j];
          int dm = x + dx[j];

          if (dn < 0 || dn >= h || dm < 0 || dm >= w)
            continue;
          if (check[dn][dm] != -1)
            continue;
          if (room[dn][dm] == 'x')
            continue;
          check[dn][dm] = check[y][x] + 1;
          
          if (room[dn][dm] == '*')
            for (int k = 1; k < ps; k++)
              if (points[k].first == dn && points[k].second == dm)
                visit[k - 1] = true, dist[i][k - 1] = check[dn][dm];

          q.push({ dn, dm });
        }
      }
    }

    for (int i = 0; i < ps - 1; i++)
      if (!visit[i]) {
        answer = -1;
        break;
      }
      else if (i == ps - 2)
        make_P(0);

    cout << answer << "\n";
  }
}