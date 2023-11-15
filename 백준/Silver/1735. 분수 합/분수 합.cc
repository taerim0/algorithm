#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int c;

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a1, b1, a2, b2;

	cin >> a1 >> b1 >> a2 >> b2;

	int lcd = gcd(b1, b2);
	int r2 = (b1 * b2) / lcd;
	int r1 = a1 * (r2 / b1) + a2 * (r2 / b2);

	lcd = gcd(r1, r2);
	r2 /= lcd;
	r1 /= lcd;

	cout << r1 << " " << r2;
}