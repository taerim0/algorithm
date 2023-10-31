#include <iostream>
#include <queue>
#define pii pair<int, int>

using namespace std;

int N, M;
int map[10][10];
int cnt;
bool check[10][10];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

int dist[7][7];
int md[7];
bool check2[7];
int ans;

queue<pair<pii, pii>> rayfrom;
vector<pii> bridge[7];

void numbering(int m, int n, int num)
{
	queue<pii> q;

	q.push({ m, n });

	while (q.size())
	{
		auto [y, x] = q.front();
		q.pop();
		map[y][x] = num;

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= N || dm < 0 || dn >= M || dn < 0)
				continue;

			if (map[dm][dn] == 1 && !check[dm][dn])
			{
				check[dm][dn] = true;
				q.push({ dm, dn });
			}
			else if (map[dm][dn] == 0)
			{
				rayfrom.push({ { dm, dn }, { num, i } });
			}
		}
	}
}

void raycast(int m, int n, int base, int dir)
{
	int len = 0;

	while (map[m][n] == 0)
	{
		m += dy[dir];
		n += dx[dir];
		len++;

		if (m >= N || m < 0 || n >= M || n < 0)
			break;

		if (map[m][n] != 0)
		{
			if (len == 1)
				break;

			if (dist[base][map[m][n]] == 0)
				dist[base][map[m][n]] = len;
			else
				dist[base][map[m][n]] = min(dist[base][map[m][n]], len);
		}
	}
}

void find_mst()
{
	priority_queue<pii> pq;

	for (int i = 2; i <= cnt; i++)
		md[i] = 2e9;

	check2[1] = true;
	for (int i = 0; i < bridge[1].size(); i++)
	{
		auto [to, cost] = bridge[1][i];

		pq.push({ -cost, to });
	}

	while (pq.size())
	{
		auto [dis, next] = pq.top();
		pq.pop();

		if (check2[next])
			continue;

		check2[next] = true;
		md[next] = -dis;

		for (int i = 0; i < bridge[next].size(); i++)
		{
			auto [to, cost] = bridge[next][i];

			pq.push({ -cost, to });
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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 && !check[i][j])
				check[i][j] = true, numbering(i, j, ++cnt);
		}
	}
	
	//cout << "\n";
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cout << map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	while (rayfrom.size())
	{
		auto [a, b] = rayfrom.front();
		raycast(a.first, a.second, b.first, b.second);
		rayfrom.pop();
	}

	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= cnt; j++)
		{
			if (dist[i][j] != 0)
			{
				bridge[i].push_back({ j, dist[i][j] });
				bridge[j].push_back({ i, dist[i][j] });
			}
		}
	}

	find_mst();

	for (int i = 2; i <= cnt; i++)
	{
		ans += md[i];

		if (md[i] == 2e9)
		{
			cout << -1;
			return 0;
		}
	}

	cout << ans;
}
	