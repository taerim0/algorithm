#include <iostream>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int N;
ll arr[5000];

ll ans = 3e9 + 1;
ll result[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N - 2; i++)
	{
		int l = i + 1;
		int r = N - 1;

		while (l < r)
		{
			if (abs(arr[i] + arr[l] + arr[r]) < ans)
			{
				ans = abs(arr[i] + arr[l] + arr[r]);

				result[0] = arr[i];
				result[1] = arr[l];
				result[2] = arr[r];
			}

			if (arr[i] + arr[l] + arr[r] < 0)
				l++;
			else
				r--;
		}
	}

	for (int i = 0; i < 3; i++)
		cout << result[i] << " ";
}
