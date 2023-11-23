#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N;
int dp[1000001];

void bfs()
{
	deque<pair<pair<int, int>, vector<int>>> q;
	bool end = false;
	q.push_front({ { N, 0 }, { N } });

	while (q.size())
	{
		auto [a, v] = q.front();
		auto [n, t] = a;
		q.pop_front();

		if (n == 1)
		{
			if (t == dp[N])
			{
				for (int i = 0; i < v.size(); i++)
					cout << v[i] << " ";
				end = true;
			}
			if (end)
				break;
			continue;
		}

		v.push_back(n - 1);
		q.push_back({ { n - 1, t + 1 }, v });
		v.pop_back();

		if (n % 2 == 0)
		{
			v.push_back(n / 2);
			q.push_front({ { n / 2, t + 1 }, v });
			v.pop_back();
		}

		if (n % 3 == 0)
		{
			v.push_back(n / 3);
			q.push_front({ { n / 3, t + 1 }, v });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	cout << dp[N] << "\n";

	bfs();
}