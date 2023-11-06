#include <iostream>

using namespace std;

int N, M;
char m[10][11];

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
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = M - 1; j >= 0; j--)
		{
			cout << m[i][j];
		}
		cout << "\n";
	}
}