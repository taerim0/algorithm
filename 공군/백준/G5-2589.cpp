// 단순 bfs. 그래프가 좋아

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define pii pair<int, int>

int n, m;
int maxDis;
char map[50][50];
int check[50][50];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void bfs(pii start)
{
    queue<pii> q;
    q.push({ start.first, start.second });
    memset(check, 0, sizeof(check));
    check[start.first][start.second] = -1;

    while (q.size()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dn = y + dy[i];
            int dm = x + dx[i];

            if (dn < 0 || dn >= n || dm < 0 || dm >= m)
                continue;

            if (check[dn][dm] || map[dn][dm] == 'W')
                continue;

            if (check[y][x] == -1)
                check[dn][dm] = 1;
            else
                check[dn][dm] = check[y][x] + 1;

            maxDis = max(maxDis, check[dn][dm]);
            q.push({ dn, dm });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L')
                bfs({ i, j });
        }
    }

    cout << maxDis;

    return 0;
}