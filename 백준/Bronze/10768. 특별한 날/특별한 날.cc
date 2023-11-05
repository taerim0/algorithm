#include <iostream>

using namespace std;

int M, D;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> D;

	if (M == 2 && D == 18)
		cout << "Special";
	else if (M == 2 && D > 18 || M >= 3)
		cout << "After";
	else
		cout << "Before";
}