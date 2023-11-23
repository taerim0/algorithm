#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N, M;

int matrix[101][101];

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
			matrix[i][j] = i == j ? 0 : 2e9;	
		}
	}

	for (int i = 0, a, b, c; i < M; i++)
	{
		cin >> a >> b >> c;

		matrix[a][b] = min(matrix[a][b], c);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (matrix[j][i] != 2e9 && matrix[i][k] != 2e9)
					matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			matrix[i][j] == 2e9 ? cout << 0 : cout << matrix[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}