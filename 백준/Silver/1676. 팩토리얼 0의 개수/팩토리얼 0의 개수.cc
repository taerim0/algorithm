#include <iostream>

using namespace std;

int N, m;
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		m = i;
		while (m % 5 == 0)
		{
			cnt++;
			m /= 5;
		}
	}

	cout << cnt;
}