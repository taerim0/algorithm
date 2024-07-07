#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int n, k;

int main()
{
	cin >> n >> k;

	if (n <= k + 60)
		cout << n * 1500;
	else
		cout << ((n - k - 60) * 3000) + ((k + 60) * 1500);
}