#include <iostream>
#include <queue>
#define pll pair<int, int>

using namespace std;

int V, E;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> V >> E;

		if (V == 0 && E == 0) break;

		int ans = 0;
		int sum = 0;

		vector<pll> edge[200000];
		int dist[200000] = { 0 };
		bool check[200000] = { 0 };

		for (int i = 0, a, b, c; i < E; i++)
		{
			cin >> a >> b >> c;

			sum += c;

			edge[a].push_back({ b, c });
			edge[b].push_back({ a, c });
		}

		for (int i = 1; i < V; i++)
			dist[i] = 2e9;

		priority_queue<pll> pq;

		check[0] = true;

		for (int i = 0; i < edge[0].size(); i++)
		{
			auto [to, cost] = edge[0][i];

			pq.push({ -cost, to });
		}

		while (pq.size())
		{
			auto [dis, next] = pq.top();
			pq.pop();

			if (check[next])
				continue;

			check[next] = true;
			dist[next] = -dis;

			for (int i = 0; i < edge[next].size(); i++)
			{
				auto [to, cost] = edge[next][i];

				pq.push({ -cost, to });
			}
		}

		for (int i = 1; i < V; i++)
		{
			ans += dist[i];
		}

		cout << sum - ans << "\n";
	}
}
