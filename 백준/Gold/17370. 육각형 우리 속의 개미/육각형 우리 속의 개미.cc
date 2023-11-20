#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N;
int cnt;

bool check[100][100];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void dfs(int y, int x, int n, int before)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 2 && y % 2 == x % 2)
			continue;
		if (i == 3 && y % 2 != x % 2)
			continue;
		if (i == before)
			continue;

		int dm = y + dy[i];
		int dn = x + dx[i];

		if (n == N)
		{
			if (check[dm][dn])
				cnt++;

			continue;
		}

		if (check[dm][dn])
			continue;

		check[dm][dn] = true;
		dfs(dm, dn, n + 1, (i + 1) % 2 + (i / 2) * 2);
		check[dm][dn] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	if (N < 5)
		cout << 0;
	else
	{
		check[50][50] = true;
		check[49][50] = true;
		dfs(49, 50, 1, 3);

		cout << cnt;
	}
}