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

ll x, y, s, d;

vector<ll> k;

ll gcd(ll a, ll b)
{
	ll c;

	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> y;

	s = x;
	d = y;

	x -= y;

	for (int i = 1; i <= sqrt(s); i++)
		if (s % i == 0)
		{
			k.push_back(i);
			if (i != s / i)
				k.push_back(s / i);
		}

	sort(k.begin(), k.end());

	if (x == 0)
		cout << 0;
	else
	{
		if (x < 0)
		{
			ll q = gcd(s, d - s);

			if (q != 1)
			{
				cout << "1\n" << d - s;
			}
			else
			{
				ll i = 1;
				ll o = 1;

				while (1)
				{
					if (o < k.size())
					{
						if (x + k[o] > 0)
						{
							if (gcd(s + k[o], s + k[o] - d) != 1)
							{
								cout << "2\n" << k[o] << "\n" << -(s + k[o] - d);
								break;
							}
						}
						else
						{
							if (gcd(s + k[o], d - (s + k[o])) != 1)
							{
								cout << "2\n" << k[o] << "\n" << d - (s + k[o]);
								break;
							}
						}
						o++;
					}
					else
					{
						if (x + s * i > 0)
						{
							if (gcd(s + s * i, s + s * i - d) != 1)
							{
								cout << "2\n" << s * i << "\n" << -(s + s * i - d);
								break;
							}
						}
						else
						{
							if (gcd(s + s * i, d - (s + s * i)) != 1)
							{
								cout << "2\n" << s * i << "\n" << d - (s + s * i);
								break;
							}
						}
						i++;
					}
				}
			}
		}
		else
		{
			ll q = gcd(s, s - d);

			if (q != 1)
			{
				cout << "1\n" << d - s;
			}
			else
			{
				ll i = 1;
				ll o = 1;

				while (1)
				{
					if (o < k.size())
					{
						if (gcd(s + k[o], s + k[o] - d) != 1)
						{
							cout << "2\n" << k[o] << "\n" << -(s + k[o] - d);
							break;
						}
						o++;
					}
					else
					{
						if (gcd(s + s * i, s + s * i - d) != 1)
						{
							cout << "2\n" << s * i << "\n" << -(s + s * i - d);
							break;
						}
						i++;
					}
				}
			}
		}
	}
}