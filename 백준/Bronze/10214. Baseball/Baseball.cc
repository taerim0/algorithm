#include <iostream>

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		int suma = 0, sumb = 0;
		int a, b;

		for (int i = 0; i < 9; i++)
		{
			cin >> a >> b;

			suma += a;
			sumb += b;
		}

		if (suma > sumb)
		{
			cout << "Yonsei\n";
		}
		else if (suma < sumb)
		{
			cout << "Korea\n";
		}
		else
		{
			cout << "Draw\n";
		}
	}
}