#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M;
int cheese[100][100], check[100][100];
int remain = 1, ans, cnt;
bool isOver;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void define_air()
{
    queue<pii> q;

    q.push({ 0, 0 });
    check[0][0] = cnt + 1;

    while (q.size())
    {
        auto [n, m] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int dn = n + dy[i];
            int dm = m + dx[i];

            if (dn >= N || dn < 0 || dm >= M || dm < 0)
                continue;

            if (check[dn][dm] == cnt + 1)
                continue;

            if (cheese[dn][dm] == 1)
                continue;

            check[dn][dm] = cnt + 1;
            cheese[dn][dm] = cnt + 2;

            q.push({ dn, dm });
        }
    }
}

void bfs(int y, int x)
{
    queue<pii> q;

    q.push({ y, x });
    check[y][x] = -cnt - 1;

    while (q.size())
    {
        auto [m, n] = q.front();
        q.pop();
        remain++;

        for (int i = 0; i < 4; i++)
        {
            int dm = m + dy[i];
            int dn = n + dx[i];

            if (dm >= N || dm < 0 || dn >= M || dn < 0)
                continue;

            if (check[dm][dn] == -cnt - 1 || !cheese[dm][dn])
                continue;

            if (cheese[dm][dn] == cnt + 2)
            {
                cheese[m][n] = cnt + 3;
                continue;
            }

            check[dm][dn] = -cnt - 1;
            q.push({ dm, dn });
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cheese[i][j];
        }
    }

    while (remain)
    {
        ans = remain;
        remain = 0;

        define_air();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (check[i][j] != -cnt - 1 && cheese[i][j] == 1)
                    bfs(i, j);
            }
        }

        if (remain)
            cnt++;
    }

    cout << cnt << "\n" << ans;
}