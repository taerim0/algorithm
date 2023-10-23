#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;


int m, n;

char matrix[500][500];
queue<pair<int, int>> covid;
int dis[500][500];
int curdis[500][500];

pair<int, int> s;
pair<int, int> e;

int sy[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int sx[] = { 1, -1, -1, 0, 1, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void spread_cororong()
{
	while (!covid.empty())
	{
		int y = covid.front().first;
		int x = covid.front().second;
		covid.pop();

		for (int i = 0; i < 8; i++)
		{
			int dm = y + sy[i];
			int dn = x + sx[i];

			if (dm < 0 || dn < 0 || dm >= m || dn >= n)
				continue;

			if (!dis[dm][dn])
			{
				covid.push(make_pair(dm, dn));
				dis[dm][dn] = dis[y][x] + 1;
			}
		}
	}
}

void bfs(int sY, int sX)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sY, sX));
	curdis[sY][sX] = dis[sY][sX] + 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= m || dm < 0 || dn >= n || dn < 0)
				continue;

			if (matrix[dm][dn] == '*' || matrix[dm][dn] == '#')
				continue;

			if (curdis[dm][dn] != 0 && curdis[dm][dn] >= curdis[y][x])
				continue;

			curdis[dm][dn] = min(dis[dm][dn] + 1, curdis[y][x]);
			q.push(make_pair(dm, dn));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;

	int cnt = 0;

	if (m == 1 && n == 1)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];

			if (matrix[i][j] == 'S')
				s = make_pair(i, j);

			if (matrix[i][j] == 'E')
				e = make_pair(i, j);

			if (matrix[i][j] == '*')
			{
				covid.push(make_pair(i, j));
				dis[i][j] = 1;
				cnt++;
			}
		}
	}

	spread_cororong();

	bfs(s.first, s.second);

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << setw(4) << dis[i][j];
	//	}
	//	cout << "\n";
	//}

	//cout << "\n";

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << setw(4) << curdis[i][j];
	//	}
	//	cout << "\n";
	//}

	//cout << "\n";

	if (curdis[e.first][e.second] - 1 == -1)
		cout << -1;
	else if (cnt == 0)
		cout << "safe";
	else
		cout << curdis[e.first][e.second] - 2;
}