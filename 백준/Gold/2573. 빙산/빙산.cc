#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M;
int map[300][300];

int year, unit;
int ans;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void melt(pii s, int temp[][300], bool check[][300])
{
	queue<pii> q;
	q.push({ s.first, s.second });
	check[s.first][s.second] = true;
	
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

			if (check[dm][dn])
				continue;

			if (map[dm][dn] > 0)
			{
				temp[dm][dn]--;
				continue;
			}

			check[dm][dn] = true;
			q.push({ dm, dn });
		}
	}
}

void define_iceberg(pii s, bool check[][300])
{
	queue<pii> q;
	q.push({ s.first, s.second });

	check[s.first][s.second];

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

			if (check[dm][dn] || map[dm][dn] < 1)
				continue;

			check[dm][dn] = true;
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
			cin >> map[i][j];
		}
	}

	while (!ans)
	{
		year++;
		unit = 0;
		bool check[300][300] = { 0 };
		int temp[300][300] = { 0 };

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] < 1 && !check[i][j])
					melt({ i, j }, temp, check);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] += temp[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] > 0 && !check[i][j])
					unit++, define_iceberg({ i, j }, check);
			}
		}

		if (unit > 1)
			ans = year;

		if (unit == 0)
			break;
	}

	cout << ans;
}