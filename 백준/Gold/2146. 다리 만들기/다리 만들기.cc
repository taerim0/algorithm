#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N;
int map[100][100];
bool check[100][100];

int ans = 2e9;
int ctn_cnt;

vector<pii> outer[5001];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void define_ctn(pii s)
{
	queue<pii> q;
	q.push({ s.first, s.second });
	check[s.first][s.second] = true;
	map[s.first][s.second] = ctn_cnt;

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

			if (check[dm][dn])
				continue;

			if (map[dm][dn] == 0)
			{
				outer[ctn_cnt - 1].push_back({ dm, dn });
				check[dm][dn] = true;
				continue;
			}

			map[dm][dn] = ctn_cnt;
			check[dm][dn] = true;
			q.push({ dm, dn });
		}
	}
}

void casting_ray(int from)
{
	queue<pii> q;

	int c[100][100] = { 0 };

	for (int i = 0; i < outer[from - 1].size(); i++)
	{
		auto [y, x] = outer[from - 1][i];
		c[y][x] = 1;
		q.push({ y, x });
	}

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

			if (c[dm][dn])
				continue;

			if (map[dm][dn] != 0 && map[dm][dn] != from)
			{
				ans = min(ans, c[y][x]);
				return;
			}

			c[dm][dn] = c[y][x] + 1;
			q.push({ dm, dn });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && !check[i][j])
				ctn_cnt++, define_ctn({i, j});
		}
	}

	for (int a = 1; a <= ctn_cnt; a++)
	{
		casting_ray(a);
	}

	cout << ans;
}