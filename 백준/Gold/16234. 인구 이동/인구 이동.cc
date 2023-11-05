#include <iostream>
#include <queue>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int N;
int L, R;

bool isOver;
int map[50][50];
int unit_val[2501];
int unit, day;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void unite(int check[][50])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = unit_val[check[i][j]];
		}
	}
}

void define_unit(pii pos, int check[][50])
{
	queue<pii> q;
	int sum = map[pos.first][pos.second];
	int cnt = 1;

	q.push(pos);

	while (q.size())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= N || dm < 0 || dn >= N || dn < 0)
				continue;

			if (check[dm][dn] || abs(map[dm][dn] - map[y][x]) < L || abs(map[dm][dn] - map[y][x]) > R)
				continue;

			check[dm][dn] = unit;
			sum += map[dm][dn];
			cnt++;
			q.push({ dm, dn });
		}
	}

	unit_val[unit] = sum / cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	while (!isOver)
	{
		unit = 0;
		int check[50][50] = { 0 };

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!check[i][j])
					check[i][j] = ++unit, define_unit({ i, j }, check);
			}
		}

		unite(check);

		if (unit == N * N)
			isOver = true;
		else
			day++;
	}

	cout << day;
}