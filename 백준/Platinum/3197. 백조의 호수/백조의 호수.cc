#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R, C;

int e = 1;

vector<pair<int, int>> L;
queue<pair<int, pair<int, int>>> q;
priority_queue<pair<int, pair<int, int>>> pq;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int melt_cnt;

char lake[1500][1500];
int check[1500][1500];
int melt[1500][1500];
int way[1500][1500];

void find_water(int y, int x);
void start_melting();
void find_way();
void print_way();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> lake[i][j];

			if (lake[i][j] == 'X')
			{
				check[i][j] = 1;
				melt[i][j] = 2100000000;
			}

			if (lake[i][j] == 'L')
				L.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (!check[i][j])
				find_water(i, j);
		}
	}

	start_melting();

	//print_way();

	find_way();

	//print_way();

	cout << way[L.front().first][L.front().second];
}


void find_water(int y, int x)
{
	bool isEdge = false;

	check[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int dm = y + dy[i];
		int dn = x + dx[i];

		if (dm >= R || dm < 0 || dn >= C || dn < 0)
			continue;

		if (lake[dm][dn] == 'X')
			isEdge = true;

		if (!check[dm][dn])
			find_water(dm, dn);
	}

	if (isEdge)
		q.push(make_pair(1, make_pair(y, x)));

	return;
}


void start_melting()
{
	while (!q.empty())
	{
		int day = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= R || dm < 0 || dn >= C || dn < 0)
				continue;

			if (lake[dm][dn] == 'X')
				if (melt[dm][dn] > day)
				{
					melt[dm][dn] = day;
					way[dm][dn] = day;
					q.push(make_pair(day + 1, make_pair(dm, dn)));
				}
		}
	}
}


void find_way()
{
	pq.push(make_pair(-0, L.back()));
	
	while (!pq.empty())
	{
		int day = -pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = y + dy[i];
			int dn = x + dx[i];

			if (dm >= R || dm < 0 || dn >= C || dn < 0)
				continue;

			if (check[dm][dn] < 2)
			{
				check[dm][dn] = 2;
				way[dm][dn] = max(day, way[dm][dn]);
				pq.push(make_pair(-way[dm][dn], make_pair(dm, dn)));
			}
		}
	}
}


void print_way()
{
	cout << "\nabout way:\n";
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << way[i][j] << " ";
		}
		cout << "\n";
	}
}