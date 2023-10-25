#include <iostream>
#include <vector>
#include <queue>

const int INF = (int)2e9;

using namespace std;

int N, M, K;
int S, T;

int from, to, c;

int dist[10001][51];
vector<pair<int, int>> node[10001];

void dijkstra()
{
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, S });
	dist[S][0] = 0;

	while (pq.size())
	{
		int pos = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (dist[pos][cost % K] < cost)
			continue;

		for (int i = 0; i < node[pos].size(); i++)
		{
			int next_cost = cost + node[pos][i].second;

			if (next_cost < dist[node[pos][i].first][next_cost % K])
			{
				dist[node[pos][i].first][next_cost % K] = next_cost;
				pq.push({ -next_cost, node[pos][i].first });
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	cin >> S >> T;

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < K; j++)
			dist[i][j] = INF;

	while (M--)
	{
		cin >> from >> to >> c;

		node[from].emplace_back(to, c);
	}

	dijkstra();

	if (dist[T][0] == INF)
		cout << "IMPOSSIBLE";
	else
		cout << dist[T][0];
}