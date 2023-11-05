#include <iostream>

using namespace std;

int T, A, B, X;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> A >> B >> X;

		cout << A * (X - 1) + B << "\n";
	}
}