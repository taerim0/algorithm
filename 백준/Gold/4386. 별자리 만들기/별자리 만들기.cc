#include <iostream>
#include <cmath>
#include <queue>
#define pid pair<int, double>
#define pdi pair<double, int>
#define pdd pair<double, double>

using namespace std;

int n;
double ans;

pdd star[101];
vector<pid> edge[101];
double dist[101];
bool check[101];

void find_mst()
{
	for (int i = 2; i <= n; i++)
		dist[i] = 2e9;

	priority_queue<pdi> pq;

	check[1] = true;
	for (int i = 0; i < edge[1].size(); i++)
	{
		auto [to, cost] = edge[1][i];

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
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		double a, b;

		cin >> a >> b;

		star[i] = { a, b };

		for (int j = 1; j < i; j++)
		{
			double distance = sqrt(pow(star[j].first - star[i].first, 2) + pow(star[j].second - star[i].second, 2));

			edge[i].push_back({ j, distance });
			edge[j].push_back({ i, distance });
		}
	}

	find_mst();

	for (int i = 2; i <= n; i++)
	{
		ans += dist[i];
	}

	cout << ans;
}
	