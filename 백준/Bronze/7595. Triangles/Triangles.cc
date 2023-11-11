#include <iostream>

using namespace std;

int num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> num;

		if (!num) break;

		for (int i = 1; i <= num; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cout << '*';
			}
			cout << "\n";
		}
	}
}