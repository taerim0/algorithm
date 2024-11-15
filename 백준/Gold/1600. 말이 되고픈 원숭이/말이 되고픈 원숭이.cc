#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

struct node
{
    pii pos;
    pii data;
};

int K, W, H;
int ans = -1;

int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1, /* 8~ */ 0, 0, 1, -1 };
int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2, /* 8~ */ 1, -1, 0, 0 };

int map[200][200];
int chk[200][200];

queue<node> q;

void bfs()
{
    q.push({ { 0, 0 }, { 0, K } });
    chk[0][0] = K + 1;

    while (q.size()) {
        auto [y, x] = q.front().pos;
        auto [cost, k] = q.front().data;
        q.pop();

		if (k)
		{
			for (int i = 0; i < 8; i++)
			{
				int dm = y + dy[i];
				int dn = x + dx[i];

				if (dm >= H || dm < 0 || dn >= W || dn < 0)
					continue;

				if (map[dm][dn] == 1)
					continue;

				if (chk[dm][dn] >= k)
					continue;

				chk[dm][dn] = k;
				q.push({ { dm, dn }, { cost - 1, k - 1 } });

				if (dm == H - 1 && dn == W - 1)
				{
					ans = -cost + 1;
					return;
				}
			}
		}

		for (int i = 8; i < 12; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= H || dm < 0 || dn >= W || dn < 0)
				continue;

			if (map[dm][dn] == 1)
				continue;

			if (chk[dm][dn] >= k + 1)
				continue;

			chk[dm][dn] = k + 1;
			q.push({ { dm, dn }, { cost - 1, k } });

			if (dm == H - 1 && dn == W - 1)
			{
				ans = -cost + 1;
				return;
			}
		}
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> map[i][j];

    if (H == 1 && W == 1) {
        cout << 0;
        return 0;
    }

    bfs();

    cout << ans;
}