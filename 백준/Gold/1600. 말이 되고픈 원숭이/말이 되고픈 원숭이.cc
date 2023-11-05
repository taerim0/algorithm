#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

int K, W, H;

int ans = -1;

int map[200][200];
int check[200][200];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int jy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int jx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void bfs()
{
	queue<pair<pii, pii>> q;

	q.push({ { 0, K }, { 0, 0 } });
	check[0][0] = K + 1;

	if (H == 1 && W == 1)
	{
		ans = 0;
		return;
	}
	
	while (q.size())
	{
		auto [data, pos] = q.front();
		auto [cost, k] = data;
		auto [y, x] = pos;
		q.pop();

		if (k)
		{
			for (int i = 0; i < 8; i++)
			{
				int dm = y + jy[i];
				int dn = x + jx[i];

				if (dm >= H || dm < 0 || dn >= W || dn < 0)
					continue;

				if (map[dm][dn] == 1)
					continue;

				if (check[dm][dn] >= k)
					continue;

				check[dm][dn] = k;
				q.push({ { cost - 1, k - 1 }, { dm, dn } });

				if (dm == H - 1 && dn == W - 1)
				{
					ans = -cost + 1;
					return;
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= H || dm < 0 || dn >= W || dn < 0)
				continue;

			if (map[dm][dn] == 1)
				continue;

			if (check[dm][dn] >= k + 1)
				continue;

			check[dm][dn] = k + 1;
			q.push({ { cost - 1, k }, { dm, dn } });

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
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	}

	bfs();

	cout << ans;
}