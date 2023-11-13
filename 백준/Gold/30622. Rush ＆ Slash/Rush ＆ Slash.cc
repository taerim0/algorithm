#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

using namespace std;

int N;
int cnt;

ll dist;

int dy[] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dx[] = { 1, -1, -1, 0, 1, -1, 0, 1 };

vector<pair<ll, pll>> v;
map<pll, bool> uncheck;

bool comp(const pair<ll, pll>& a, const pair<ll, pll>& b)
{
	if (a.first == b.first)
		return a.second.first < b.second.first;
	return a.first < b.first;
}

void bfs(pll a)
{
	queue<pll> q;

	q.push(a);

	while (q.size())
	{
		auto [y, x] = q.front();
		q.pop();

		/*cout << "check : " << y << " " << x << "\n";*/

		for (int i = 0; i < 8; i++)
		{
			ll dm = y + dy[i];
			ll dn = x + dx[i];

			if (uncheck[{ dm, dn }] == true)
			{
				uncheck[{ dm, dn }] = false;
				q.push({ dm, dn });
				cnt--;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cnt = N;

	for (ll i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;

		uncheck[{ a, b }] = true;
		v.push_back({ abs(a) + abs(b), { a , b } });
	}

	sort(v.begin(), v.end(), comp);

	for (auto iter : v)
	{
		if (uncheck[iter.second] == true)
		{
			uncheck[iter.second] = false;
			bfs(iter.second);
			cnt--;

			if (cnt == 0)
				dist += iter.first;
			else
				dist += iter.first * 2;
		}
	}

	cout << dist;
}