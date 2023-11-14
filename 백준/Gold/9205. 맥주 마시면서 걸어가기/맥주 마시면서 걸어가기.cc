#include <iostream>
#include <queue>
#include <cmath>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

using namespace std;

int T;
int n; 
bool check[105];


vector<int> adj[105];


void bfs()
{
	queue<int> q;

	q.push(0);
	check[0] = true;

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < adj[now].size(); i++)
		{
			if (check[adj[now][i]])
				continue;

			check[adj[now][i]] = true;
			q.push(adj[now][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		vector<pii> conv;
		

		cin >> n;

		for (int i = 0, a, b; i < n + 2; i++)
		{
			cin >> a >> b;

			adj[i].clear();
			check[i] = false;

			conv.push_back({ a, b });
		}

		for (int i = 0; i < n + 2; i++)
		{
			for (int j = i + 1; j < n + 2; j++)
			{
				if (abs(conv[i].first - conv[j].first) + abs(conv[i].second - conv[j].second) <= 1000)
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		bfs();

		if (check[n + 1])
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}