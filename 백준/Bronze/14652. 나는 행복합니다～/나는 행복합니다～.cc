#include <iostream>

using namespace std;

int N, M, K, cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cnt == K)
			{
				cout << i << " " << j;
				return 0;
			}
			cnt++;
		}
	}
}