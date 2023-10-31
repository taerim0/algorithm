#include <iostream>
#include <queue>
#define pii pair<int, int>

using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		int N, M;
		int K;
		vector<int> fren;
		vector<pii> path[101];
		int dist[101][101];
		int sum_dist[101] = { 0 };
		pii ans = { 2e9, 0 };

		cin >> N >> M;

		for (int i = 0, a, b, c; i < M; i++)
		{
			cin >> a >> b >> c;

			path[a].push_back({ b, c });
			path[b].push_back({ a, c });
		}

		cin >> K;

		for (int i = 0, v; i < K; i++)
		{
			cin >> v;

			fren.push_back(v);

			for (int j = 1; j <= N; j++)
			{
				dist[v][j] = 2e9;
			}
		}

		for (int i = 0; i < K; i++)
		{
			priority_queue<pii> pq;

			int nf = fren[i];

			pq.push({ 0, nf });
			dist[nf][nf] = 0;

			while (pq.size())
			{
				auto [cost, now] = pq.top();
				pq.pop();

				for (int j = 0; j < path[now].size(); j++)
				{
					auto [next, next_cost] = path[now][j];

					if (dist[nf][next] > -cost + next_cost)
					{
						dist[nf][next] = -cost + next_cost;
						pq.push({ cost - next_cost, next });
					}
				}
			}

			for (int j = 1; j <= N; j++)
			{
				sum_dist[j] += dist[nf][j];
			}
		}

		for (int i = 1; i <= N; i++)
		{
			if (sum_dist[i] < ans.first)
			{
				ans = { sum_dist[i], i };
			}
		}

		cout << ans.second << "\n";
	}
}
	