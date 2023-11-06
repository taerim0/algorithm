#include <iostream>

using namespace std;

int min1 = 2e9, min2 = 2e9;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d, e, f;

	cin >> a;
	min1 = min(min1, a);
	cin >> b;
	min1 = min(min1, b);
	cin >> c;
	min1 = min(min1, c);
	cin >> d;
	min1 = min(min1, d);
	cin >> e;
	min2 = min(min2, e);
	cin >> f;
	min2 = min(min2, f);

	cout << a + b + c + d + e + f - min1 - min2;
}