#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

int A[100][100], B[100][100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int sum = 0;

			for (int k = 0; k < M; k++)
			{
				sum += A[i][k] * B[k][j];
			}

			cout << sum << " ";
		}
		cout << "\n";
	}
}