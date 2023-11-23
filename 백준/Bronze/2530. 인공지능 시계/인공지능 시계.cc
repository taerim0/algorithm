#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, c, N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c >> N;

	a += (N / 3600);
	N -= (N / 3600) * 3600;
	b += (N / 60);
	a += (b / 60);
	b -= (b / 60) * 60;
	N -= (N / 60) * 60;
	c += N;
	b += (c / 60);
	a += (b / 60);
	b -= (b / 60) * 60;
	c -= (c / 60) * 60;
	a %= 24;

	cout << a << " " << b << " " << c;
}