#include <iostream>

using namespace std;

int n;
int a, cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a % 2 == 0)
			cnt++;
	}

	if (cnt > n / 2)
		cout << "Happy";
	else
		cout << "Sad";
}