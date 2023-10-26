#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define pos pair<int, int>

int N, S;

using namespace std;

char map[800][800];
int bee[800][800];
bool check[800][800];

int l, r;
int ans = -1;

pos s;
pos home;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

queue<pos> b;

void spread_bee()
{
	while (b.size())
	{
		auto [y, x] = b.front();
		b.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= N || dm < 0 || dn >= N || dn < 0)
				continue;

			if (bee[dm][dn] != -1 || map[dm][dn] != 'G')
				continue;

			bee[dm][dn] = bee[y][x] + S;
			b.push({ dm, dn });
		}
	}
}

bool move_bear(int t)
{
	memset(check, 0, sizeof(check));

	queue<pair<int, pos>> q;
	q.push({ t * S, s });
	check[s.first][s.second] = true;

	if (t * S >= bee[s.first][s.second])
		return false;

	while (q.size())
	{
		auto [y, x] = q.front().second;
		int cost = q.front().first;

		if (map[y][x] == 'D')
			return true;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= N || dm < 0 || dn >= N || dn < 0)
				continue;

			if (map[dm][dn] == 'T' || check[dm][dn] || bee[dm][dn] <= cost + 1)
				continue;

			check[dm][dn] = true;
			q.push({ cost + 1, { dm, dn } });
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bee[i][j] = -1;

			cin >> map[i][j];

			if (map[i][j] == 'M')
				s = { i, j }, map[i][j] = 'G';
			if (map[i][j] == 'D')
				bee[i][j] = 2e9;
			if (map[i][j] == 'H')
				b.push({ i, j }), bee[i][j] = 0;
		}
	}

	spread_bee();

	/*cout << "bee\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << bee[i][j] << " ";
		}
		cout << "\n";
	}*/

	l = 0, r = N * N * 2;

	while (l < r)
	{
		int mid = (l + r) / 2;

		if (move_bear(mid))
			ans = max(ans, mid), l = mid + 1;
		else
			r = mid;
	}

	cout << ans;
}