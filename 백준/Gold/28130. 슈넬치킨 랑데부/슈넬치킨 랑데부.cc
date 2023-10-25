#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int ans = 2e9;

pair<int, int> A, B;
pair<int, int> L;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

char map[1000][1000];
int check[1000][1000];
//int check1[1000][1000];

void bfs()
{
	queue<pair<int, pair<int, int>>> q;

	check[A.first][A.second] = -1;
	q.push({ 1, {A.first, A.second} });

	while (q.size())
	{
		pair<int, int> pos = q.front().second;
		int t = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = pos.first + dy[i];
			int dn = pos.second + dx[i];

			if (dm >= N || dm < 0 || dn >= M || dn < 0)
				continue;

			if (check[dm][dn] != 0)
				continue;

			check[dm][dn] = t;
			q.push({ t + 1, {dm, dn} });
		}
	}
}

void run()
{
	int v;

	int y = B.first;
	int x = B.second;

	if (y == 0 && x < M - 1)
		v = 0;
	else if (x == M - 1 && y < N - 1)
		v = 1;
	else if (y == N - 1 && x > 0)
		v = 2;
	else if (x == 0 && y > 0)
		v = 3;
	else
		return;

	int t = 0;
	int r = (N + M) * 2 - 4;

	while (1)
	{
		y += dy[v]; x += dx[v]; t++;

		if (y >= N || y < 0 || x >= M || x < 0)
		{
			y -= dy[v]; x -= dx[v];
			v = (v + 1) % 4;
			y += dy[v]; x += dx[v];
		}

		/*check1[y][x] = t;*/

		if (check[y][x] % r == t % r)
			ans = min(check[y][x], ans);

		if (y == B.first && x == B.second)
			break;
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

			if (map[i][j] == 'A')
				A = { i, j };
			if (map[i][j] == 'B')
				B = { i, j };
			if (map[i][j] == 'G')
				check[i][j] = -1;
		}
	}

	bfs();

	run();

	/*for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << check1[i][j] << " ";
		}
		cout << "\n";
	}*/

	ans != 2e9 ? ans == 0 ? cout << -1 : cout << ans : cout << -1;
}