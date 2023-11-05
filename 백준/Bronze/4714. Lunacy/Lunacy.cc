#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed;
	cout.precision(2);

	while (1)
	{
		double val;

		cin >> val;

		if (val < 0)
			break;

		cout << "Objects weighing " << val << " on Earth will weigh " << val * 0.167 << " on the moon.\n";
	}
}