#include <iostream>

using namespace std;

double W, H;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed;
	cout.precision(1);

	cin >> W >> H;

	cout << W * H * 0.5;
}