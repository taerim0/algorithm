#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

#define ll long long
#define pii pair<int, int>

using namespace std;

int N, M;

ll dist[501];
vector<pii> edge[501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		dist[i] = 2e9;

	for (int i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b >> c;

		edge[a].push_back({ b, c });
	}

	dist[1] = 0;

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < edge[j].size(); k++)
			{
				auto [to, cost] = edge[j][k];

				if (dist[j] == 2e9)
					break;

				if (dist[to] > dist[j] + cost)
					dist[to] = dist[j] + cost;
			}
		}
	}

	for (int j = 1; j <= N; j++)
	{
		for (int k = 0; k < edge[j].size(); k++)
		{
			auto [to, cost] = edge[j][k];

			if (dist[j] == 2e9)
				break;

			if (dist[to] > dist[j] + cost)
			{
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		dist[i] == 2e9 ? cout << "-1\n" : cout << dist[i] << "\n";
	}
}