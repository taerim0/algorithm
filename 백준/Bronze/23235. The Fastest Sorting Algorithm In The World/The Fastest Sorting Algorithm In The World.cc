#include <iostream>

using namespace std;

int t, a, i;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> t;

		if (!t) break;

		while (t--)
			cin >> a;

		cout << "Case " << ++i << ": Sorting... done!\n";
	}
}