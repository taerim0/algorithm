#include <iostream>
#include <cmath>

using namespace std;

double a, b, c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	cout << fixed;
	cout.precision(0);

	cout << floor((a + 1) * (b + 1) / (c + 1) - 1);
}