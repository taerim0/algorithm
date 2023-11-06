#include <iostream>

using namespace std;

int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char t;
	int T, day;

	cin >> T;

	while (T--)
	{
		cin >> t;
		cin >> t;
		cin >> day;

		if (day <= 90)
			cnt++;
	}
	
	cout << cnt;
}