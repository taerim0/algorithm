#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M;
int cnt;
int cv;

char map[1000][1000];
int check[1000][1000];
int cell_size[500005];

vector<int> adj;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void bfs(int sy, int sx, int cv)
{
	queue<pii> q;

	q.push({ sy, sx });
	check[sy][sx] = cv;

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

			if (map[dm][dn] == '1' || check[dm][dn] == cv)
				continue;

			cnt++;
			check[dm][dn] = cv;
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

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '0' && !check[i][j])
			{
				cnt = 1;
				bfs(i, j, ++cv);
				cell_size[cv] = cnt;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '1')
			{
				for (int k = 0; k < 4; k++)
				{
					bool exist = false;
					int dm = i + dy[k];
					int dn = j + dx[k];

					if (dm >= N || dm < 0 || dn >= M || dn < 0)
						continue;

					if (map[dm][dn] == '1')
						continue;

					for (int o = 0; o < adj.size(); o++)
					{
						if (adj[o] == check[dm][dn])
						{
							exist = true;
							break;
						}
					}

					if (exist)
						continue;

					adj.push_back(check[dm][dn]);
				}

				int sum = 1;

				for (int o = 0; o < adj.size(); o++)
				{
					sum += cell_size[adj[o]];
				}

				cout << sum % 10;

				adj.clear();
			}
			else
			{
				cout << 0;
			}
		}
		cout << "\n";
	}
}
