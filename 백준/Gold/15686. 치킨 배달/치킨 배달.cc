#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int N, M;

int ans = 2e9;

vector<pii> c, h, s;

void chicken_dist()
{
	int sum = 0;

	for (int i = 0; i < h.size(); i++)
	{
		int min_dist = 2e9;

		for (int j = 0; j < s.size(); j++)
			min_dist = min(min_dist, abs(s[j].first - h[i].first) + abs(s[j].second - h[i].second));

		sum += min_dist;
	}

	ans = min(ans, sum);
}

void select(int now, int t)
{
	if (t == M)
	{
		chicken_dist();
	}

	for (int i = now; i < c.size(); i++)
	{
		s.push_back(c[i]);
		select(i + 1, t + 1);
		s.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0, a; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a;

			if (a == 1)
				h.push_back({ i, j });
			if (a == 2)
				c.push_back({ i, j });
		}
	}

	select(0, 0);

	cout << ans;
}