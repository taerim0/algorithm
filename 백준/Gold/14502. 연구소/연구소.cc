#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M;

int map[8][8];
int ans, cnt;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

void bfs()
{
	int spread[8][8];
	bool check[8][8];
	cnt = 0;

	queue<pii> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			check[i][j] = false;
			spread[i][j] = map[i][j];

			if (spread[i][j] == 2)
				q.push({ i, j }), check[i][j] = true;
		}
	}
	
	while (q.size())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= N || dm < 0 || dn >= M || dn < 0)
				continue;

			if (check[dm][dn] || spread[dm][dn] == 1)
				continue;

			check[dm][dn] = true;
			spread[dm][dn] = 2;
			q.push({ dm, dn });
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (spread[i][j] == 0)
				cnt++;
		}
	}

	ans = max(ans, cnt);
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
			cin >> map[i][j];
		}
	}

	for (int a1 = 0; a1 < N; a1++)
	{
		for (int a2 = 0; a2 < M; a2++)
		{
			for (int b1 = 0; b1 < N; b1++)
			{
				for (int b2 = 0; b2 < M; b2++)
				{
					for (int c1 = 0; c1 < N; c1++)
					{
						for (int c2 = 0; c2 < M; c2++)
						{
							if (a1 == b1 && a2 == b2)
								continue;

							if (b1 == c1 && b2 == c2)
								continue;

							if (c1 == a1 && c2 == a2)
								continue;

							if (map[a1][a2] != 0 || map[b1][b2] != 0 || map[c1][c2] != 0)
								continue;

							map[a1][a2] = 1;
							map[b1][b2] = 1;
							map[c1][c2] = 1;

							bfs();

							map[a1][a2] = 0;
							map[b1][b2] = 0;
							map[c1][c2] = 0;
						}
					}
				}
			}
		}
	}

	cout << ans;
}