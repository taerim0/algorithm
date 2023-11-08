#include <iostream>

using namespace std;

int N, M;
int a, b;

int arr[100001];
int sum[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];

		sum[i] = sum[i - 1] + arr[i];
	}

	cin >> M;

	while (M--)
	{
		cin >> a >> b;

		cout << sum[b] - sum[a - 1] << "\n";
	}
}