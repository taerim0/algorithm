#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <map>

#define pii pair<int, int>

using namespace std;

int N, M;
int K;
int h, w;
int a, b;
int arr[1000][1000];
bool isEmpty[1000][1000];
bool check[1000][1000];
int cnt;

queue<pii> q;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> h >> w;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	cin >> K;

	while (K--)
	{
		cin >> a >> b;

		q.push({ a - 1, b - 1 });
		isEmpty[a - 1][b - 1] = true;
	}

	while (q.size())
	{
		auto [y, x] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= N || dm < 0 || dn >= M || dn < 0)
				continue;

			if (arr[dm][dn] < arr[y][x] || isEmpty[dm][dn])
				continue;

			isEmpty[dm][dn] = true;
			q.push({ dm, dn });
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		isEmpty[i][j] ? cout << "1 " : cout << "0 ";
	//	}
	//	cout << "\n";
	//}

	for (int i = h - 1; i < N; i++)
	{
		for (int j = w - 1; j < M; j++)
		{
			if (!isEmpty[i][j])
				continue;

			if (i != 0 && j != 0)
			{
				if (check[i - 1][j] && check[i][j - 1])
				{
					check[i][j] = true;
					cnt++;
					continue;
				}
			}

			bool cant = false;

			for (int y = i - (h - 1); y <= i; y++)
			{
				for (int x = j - (w - 1); x <= j; x++)
				{
					if (!isEmpty[y][x])
					{
						cant = true;
						break;
					}
				}

				if (cant)
					break;
			}

			if (!cant)
			{
				check[i][j] = true;
				cnt++;
			}
		}
	}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		check[i][j] ? cout << "1 " : cout << "0 ";
	//	}
	//	cout << "\n";
	//}

	cout << cnt;
}