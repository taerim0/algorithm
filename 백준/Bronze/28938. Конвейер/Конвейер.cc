#include <iostream>

using namespace std;

int n;
int sum;
int a;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (n--)
	{
		cin >> a;

		sum += a;
	}

	if (sum > 0)
		cout << "Right";
	else if (sum < 0)
		cout << "Left";
	else
		cout << "Stay";
}