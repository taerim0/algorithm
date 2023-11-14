#include <iostream>
#include <map>

#define ll long long
#define pii pair<int, int>

using namespace std;

ll a, b, c;

map<ll, ll> m;

ll power(ll a, ll n)
{
	if (n == 1)
		return a % c;

	ll temp = power(a, n / 2);

	if (n % 2 == 0)
		return (temp * temp) % c;
	else
		return (((a * temp) % c) * temp) % c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	cout << power(a, b);
}