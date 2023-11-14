#include <iostream>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

using namespace std;

ll S;
ll cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> S;

	ll nownum = 1;
	ll nowsum = 0;
	
	while (S >= nowsum)
	{
		nowsum += nownum;
		nownum++;
		cnt++;
	}

	cnt--;

	cout << cnt;
}