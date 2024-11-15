#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int n, m;
int cnt, ans;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

vector<vector<int>> pic(500, vector<int>(500, 0));
vector<vector<bool>> chk(500, vector<bool>(500, 0));

queue<pii> q;

void bfs()
{
    int size = 1;

    while (q.size())
    {
        auto [y, x] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int dn = y + dy[i];
            int dm = x + dx[i];

            if (dn >= n || dm >= m || dn < 0 || dm < 0)
                continue;
            if (!pic[dn][dm] || chk[dn][dm])
                continue;

            chk[dn][dm] = true;
            size++;

            q.push({ dn, dm });
        }
    }

    ans = max(ans, size);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> pic[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pic[i][j] && !chk[i][j]) {
                chk[i][j] = true, cnt++;
                q.push({ i, j });
                bfs();
            }
        }
    }

    cout << cnt << '\n' << ans;
}