#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
char video[64][64];

void divide(int n, int sy, int sx)
{
	bool needDivide = false;
	char pivot = video[sy][sx];

	for (int i = sy; i < sy + n; i++)
	{
		for (int j = sx; j < sx + n; j++)
		{
			if (video[i][j] != pivot)
			{
				needDivide = true;
				break;
			}
		}

		if (needDivide)
			break;
	}

	if (!needDivide)
	{
		cout << pivot;
		return;
	}

	cout << "(";
	divide(n / 2, sy, sx);
	divide(n / 2, sy, sx + n / 2);
	divide(n / 2, sy + n / 2, sx);
	divide(n / 2, sy + n / 2, sx + n / 2);
	cout << ")";

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> video[i][j];
		}
	}

	divide(N, 0, 0);
}