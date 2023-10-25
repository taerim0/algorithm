#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int M, N, H;
int ans = -1;
int cnt0;

bool isAlreadyDone = true;

int box[100][100][100];
int check[100][100][100];

int dz[] = { 0, 0, 0, 0, 1, -1 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dx[] = { 1, -1, 0, 0, 0, 0 };

queue<tuple<int, int, int>> q;

void bfs()
{
	while (q.size())
	{
		tuple<int, int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int dh = get<0>(now) + dz[i];
			int dm = get<1>(now) + dy[i];
			int dn = get<2>(now) + dx[i];

			if (dh >= H || dm >= N || dn >= M || dh < 0 || dm < 0 || dn < 0)
				continue;

			if (check[dh][dm][dn] != 0 || box[dh][dm][dn] != 0)
				continue;

			cnt0--;
			check[dh][dm][dn] = check[get<0>(now)][get<1>(now)][get<2>(now)] + 1;
			ans = max(ans, check[dh][dm][dn]);
			q.push({ dh, dm, dn });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> box[i][j][k];

				if (box[i][j][k] == 0)
				{
					isAlreadyDone = false;
					cnt0++;
				}

				if (box[i][j][k] == 1)
					q.push({ i, j, k });
			}
		}
	}

	if (isAlreadyDone)
	{
		cout << 0;
		return 0;
	}

	bfs();

	cnt0 ? cout << -1 : cout << ans;
}