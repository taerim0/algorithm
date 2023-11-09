#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int a, b, c, d;

int arr[1025][1025];
int sum[1025][1025];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];

			sum[i][j] = arr[i][j] + sum[i][j - 1];
		}
	}

	while (M--)
	{
		cin >> a >> b >> c >> d;

		int ans = 0;

		for (int i = a; i <= c; i++)
			ans += sum[i][d] - sum[i][b - 1];

		cout << ans << "\n";
	}
}