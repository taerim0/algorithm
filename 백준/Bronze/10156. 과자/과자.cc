#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	cin >> a >> b >> c;

	int ans = a * b - c;

	if (ans > 0)
		cout << ans;
	else
		cout << 0;
}