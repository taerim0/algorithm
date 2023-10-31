#include <iostream>
#include <queue>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

int V, E;
int s, e;
ll ans;
ll sum;

vector<pll> edge[100001];
ll dist[100001];
bool check[100001];

void find_mst()
{
	priority_queue<pair<pll, ll>> pq;

	dist[0] = 2e9;
	dist[s] = 0;
	check[s] = true;
	for (int i = 0; i < edge[s].size(); i++)
	{
		auto [to, cost] = edge[s][i];

		pq.push({ { cost, to }, 0 });
	}

	while (pq.size())
	{
		auto [a, prev] = pq.top();
		auto [dis, next] = a;
		pq.pop();

		if (check[next])
			continue;

		check[next] = true;
		dist[next] = min(dist[prev], dis);

		for (int i = 0; i < edge[next].size(); i++)
		{
			auto [to, cost] = edge[next][i];

			pq.push({ { cost, to }, next });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E >> s >> e;

	for (int i = 0, a, b, c; i < E; i++)
	{
		cin >> a >> b >> c;

		edge[a].push_back({ b, c });
		edge[b].push_back({ a, c });
	}

	find_mst();

	cout << dist[e];
}
