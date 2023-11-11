#include <iostream>

using namespace std;

int N;

int a, b, c;
bool isUnordered, higher, lower;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	cout << "Gnomes:\n";

	while (N--)
	{
		isUnordered = higher = lower = false;

		cin >> a >> b;

		if (b > a)
			higher = true;
		else if (b < a)
			lower = true;

		cin >> c;

		if (higher && c < b)
			isUnordered = true;
		else if (lower && c > b)
			isUnordered = true;

		isUnordered == true ? cout << "Unordered\n" : cout << "Ordered\n";
	}
}