#include <iostream>
#include <queue>
#define pii pair<int, int>

using namespace std;

int n, m, r;

int item[101];
int dist[101];

int maxitem = 0;

vector<pii> road[101];

void dtra(int s)
{
	priority_queue<pii> pq;

	dist[s] = 0;
	pq.push({ 0, s });

	while (pq.size())
	{
		auto [cost, pos] = pq.top();
		pq.pop();

		for (int i = 0; i < road[pos].size(); i++)
		{
			auto [to, dis] = road[pos][i];

			if (dist[to] > -cost + dis)
			{
				dist[to] = -cost + dis;
				pq.push({ cost - dis, to });
			}
		}
	}
}

void drop(int s)
{
	for (int i = 1; i <= n; i++)
		dist[i] = 2e9;

	int nowitem = 0;

	dtra(s);

	for (int i = 1; i <= n; i++)
		if (dist[i] <= m)
			nowitem += item[i];

	maxitem = max(maxitem, nowitem);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	for (int i = 0, a, b, c; i < r; i++)
	{
		cin >> a >> b >> c;

		road[a].push_back({ b, c });
		road[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; i++)
		drop(i);

	cout << maxitem;
}