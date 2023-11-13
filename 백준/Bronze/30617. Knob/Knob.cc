#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

using namespace std;

int N;

int a, b, c, d;
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;

		if (i != 0)
		{
			if (a != 0 && a == c)
				cnt++;
			if (b != 0 && b == d)
				cnt++;
		}

		if (a != 0 && b != 0 && a == b)
			cnt++;

		c = a;
		d = b;
	}

	cout << cnt;
}