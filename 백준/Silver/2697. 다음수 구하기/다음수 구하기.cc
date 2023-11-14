#include <iostream>
#include <queue>

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
		string A;
		priority_queue<int> pq;
		bool biggest = false;
		int pos;
		int num[10] = { 0 };
		int min;

		cin >> A;

		for (pos = A.length() - 1; pos > 0; pos--)
		{
			num[A[pos] - '0']++;

			if (A[pos - 1] - '0' < A[pos] - '0')
			{
				num[A[pos - 1] - '0']++;
				for (int i = A[pos - 1] - '0' + 1; i < 10; i++)
				{
					if (num[i])
					{
						min = i;
						num[i]--;
						break;
					}
				}

				break;
			}
		}

		if (!pos)
		{
			cout << "BIGGEST\n";
			continue;
		}

		for (int i = 0; i < pos - 1; i++)
		{
			cout << A[i];
		}
		cout << min;
		for (int i = 0; i < 10; i++)
		{
			while (num[i])
			{
				cout << i;
				num[i]--;
			}
		}
		cout << "\n";
	}
}