#include <iostream>
#include <vector>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int n;

int a[100000];
int b[100000];

int pos;

ll dp[100000];
vector<pair<double, pll>> line(100000);

double cross(pll p, pll n)
{
	return (n.second - p.second) / (p.first - n.first);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 1; i < n; i++)
	{
		double s;

		while (line.size() > 0)
		{
			s = cross(line.back().second, { b[i - 1], dp[i - 1] });

			if (line.back().first < s)
				break;

			line.pop_back();
			if (line.size() == pos)
				pos--;
		}

		pll l = { b[i - 1], dp[i - 1] };

		line.emplace_back(s, l);

		ll x = a[i];

		for (; pos + 1 < line.size() && line[pos + 1].first < x; pos++);
		dp[i] = line[pos].second.first * x + line[pos].second.second;
	}
	
	/*for (int i = 0; i < n; i++)
		cout << dp[i] << " ";
	cout << "\n";*/

	cout << dp[n - 1];
}