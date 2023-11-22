#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int paper[2200][2200];
int cnt[3];

void divide(int n, int sy, int sx)
{
	bool needDivide = false;
	int pivot = paper[sy][sx];

	for (int i = sy; i < sy + n; i++)
	{
		for (int j = sx; j < sx + n; j++)
		{
			if (paper[i][j] != pivot)
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
		cnt[pivot + 1]++;
		return;
	}

	divide(n / 3, sy, sx);
	divide(n / 3, sy, sx + n / 3);
	divide(n / 3, sy, sx + n * 2 / 3);
	divide(n / 3, sy + n / 3, sx);
	divide(n / 3, sy + n / 3, sx + n / 3);
	divide(n / 3, sy + n / 3, sx + n * 2 / 3);
	divide(n / 3, sy + n * 2 / 3, sx);
	divide(n / 3, sy + n * 2 / 3, sx + n / 3);
	divide(n / 3, sy + n * 2 / 3, sx + n * 2 / 3);
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
			cin >> paper[i][j];
		}
	}

	divide(N, 0, 0);

	cout << cnt[0] << "\n";
	cout << cnt[1] << "\n";
	cout << cnt[2];
}