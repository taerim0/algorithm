#include <iostream>
#include <vector>
#include <queue>
#define INF 2e9

using namespace std;

int N, M;

int ans = INF;
int o = 1;

pair<int, int> S[21];

char map[1000][1000];
int check[21][1000][1000];
bool visit[21];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void bfs(pair<int, int> s, int t)
{
	queue<pair<int, int>> q;

	check[t][s.first][s.second] = 0;
	q.push({ s.first, s.second });

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

			if (check[t][dm][dn] != -1 || map[dm][dn] == 'X')
				continue;

			check[t][dm][dn] = check[t][y][x] + 1;
			q.push({ dm, dn });
		}
	}
}

void dfs(int s, int value, int t)
{
	if (t == 5)
	{
		ans = min(ans, value);
		return;
	}

	for (int i = 1; i < o; i++)
	{
		if (i == s || check[s][S[i].first][S[i].second] < 1 || visit[i])
			continue;

		visit[i] = true;
		dfs(i, value + check[s][S[i].first][S[i].second], t + 1);
		visit[i] = false;
	}
}


int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			for (int k = 0; k < 21; k++)
				check[k][i][j] = -1;

			if (map[i][j] == 'S')
				S[0] = { i, j };
			if (map[i][j] == 'K')
				S[o++] = { i, j };
		}
	}
	
	for (int i = 0; i < o; i++)
		bfs(S[i], i);
	
	dfs(0, 0, 0);

	ans == INF ? cout << -1 : cout << ans;
}