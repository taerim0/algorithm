#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M;
char board[11][11];
int ans = -1;

pii red, blue;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void solve()
{
	queue<pair<pair<pii, pii>, int>> q;

	q.push({ { blue, red }, 1 });

	while (q.size())
	{
		auto [marble, cost] = q.front();
		auto [b, r] = marble;
		auto [by, bx] = b;
		auto [ry, rx] = r;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			bool isOver = false;
			bool isCrashed = false;

			int dby = by;
			int dbx = bx;
			int dry = ry;
			int drx = rx;

			while (board[dby][dbx] != '#' && (dby != dry || dbx != drx))
			{
				dby += dy[i];
				dbx += dx[i];

				if (board[dby][dbx] == 'O')
					isOver = true;

				if (dby == ry && dbx == rx)
				{
					isCrashed = true;

					while (board[dry][drx] != '#')
					{
						dry += dy[i];
						drx += dx[i];

						if (board[dry][drx] == 'O')
						{
							isOver = true;
							break;
						}
					}

					dry -= dy[i];
					drx -= dx[i];
				}

				if (isOver)
					break;
			}

			if (isOver)
				continue;

			dby -= dy[i];
			dbx -= dx[i];

			if (!isCrashed)
			{
				while (board[dry][drx] != '#' && (dry != dby || drx != dbx))
				{
					dry += dy[i];
					drx += dx[i];

					if (board[dry][drx] == 'O')
					{
						isOver = true;
						break;
					}
				}

				if (isOver)
				{
					ans = cost;
					return;
				}

				dry -= dy[i];
				drx -= dx[i];
			}

			if (cost < 10)
				q.push({ { { dby, dbx }, { dry, drx } }, cost + 1 });
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
			cin >> board[i][j];

			if (board[i][j] == 'R')
				red = { i, j };
			if (board[i][j] == 'B')
				blue = { i, j };
		}
	}

	solve();

	cout << ans;
}