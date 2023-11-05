#include <iostream>

using namespace std;

int N;
int map[10][10];

int ans, cnt;

bool ld[20];
bool rd[20];

void place_bishop(int cur_cnt, int col, int row, bool c)
{
	if (col >= N)
		row++, col % 2 ? col = 0 : col = 1;

	if (row >= N)
	{
		cnt = max(cnt, cur_cnt);
		return;
	}

	if (map[row][col] && !ld[col - row + N - 1] && !rd[row + col])
	{
		ld[col - row + N - 1] = rd[row + col] = 1;
		place_bishop(cur_cnt + 1, col + 2, row, c);
		rd[row + col] = ld[col - row + N - 1] = 0;
	}
	place_bishop(cur_cnt, col + 2, row, c);
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
			cin >> map[i][j];
		}
	}

	place_bishop(0, 0, 0, 0);
	ans += cnt;
	cnt = 0;
	place_bishop(0, 1, 0, 1);
	ans += cnt;

	cout << ans;
}