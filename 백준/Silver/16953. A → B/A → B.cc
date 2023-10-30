#include <iostream>
#include <queue>

#define ll long long
#define pii pair<ll, ll>

using namespace std;

ll A, B;
int ans = -1;

void bfs()
{
	queue<pii> q;

	q.push({ A, 1 });

	while (q.size())
	{
		auto [now, cost] = q.front();
		q.pop();

		if (now == B)
		{
			ans = cost;
			break;
		}
		if (now > B)
			continue;

		q.push({ now * 2, cost + 1 });
		
		q.push({ now * 10 + 1, cost + 1 });
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	bfs();

	cout << ans;
}