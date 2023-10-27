#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pi pair<ll, ll>

using namespace std;

int N;

pi land;
priority_queue<pi> lands;
vector<pi> sl;
vector<pair<double, pi>> line;

ll pos;
ll dp[50000];

double cross(pi p, pi n)
{
	return (n.second - p.second) / (p.first - n.first);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> land.first >> land.second, lands.push(land);

	sl.emplace_back(lands.top());
	lands.pop();

	for (int i = 1; i < N; i++)
	{
		if (lands.top().second > sl.back().second)
			sl.emplace_back(lands.top());
		lands.pop();
	}

	dp[0] = sl[0].first * sl[0].second;
	pi l = { sl[0].first, 0 };
	line.emplace_back(0.0, l);

	for (int i = 1; i < sl.size(); i++)
	{
		double s;

		while (line.size())
		{
			s = cross(line.back().second, { sl[i].first, dp[i - 1] });

			if (line.back().first < s)
				break;

			line.pop_back();
			if (line.size() == pos)
				pos--;
		}

		l = { sl[i].first, dp[i - 1] };

		line.emplace_back(s, l);

		ll x = sl[i].second;

		for (; pos + 1 < line.size() && line[pos + 1].first < x; pos++);
		dp[i] = line[pos].second.first * x + line[pos].second.second;
	}

	/*for (auto iter : line)
	{
		cout << iter.first << " :" << iter.second.first << " " << iter.second.second << "\n";
	}
	cout << "\n";

	for (int i = 0; i < sl.size(); i++)
	{
		cout << dp[i] << " ";
	}
	cout << "\n";*/

	cout << dp[sl.size() - 1];
}