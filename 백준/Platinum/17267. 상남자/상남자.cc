#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;


typedef struct
{
	int y, x;
	int left, right;
}pos;

// variable

int N, M;
int L, R;
int cnt;
pos start;
char map[1001][1001];

int dx[2] = { -1, 1 };


// fuction prototype

void input();
void solution();
void bfs(pos start);
void debug();
void output();


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
#ifdef DEBUG
	debug();
#endif
	output();
}


void input()
{
	cin >> N >> M;

	cin >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '2')
			{
				start.y = i;
				start.x = j;
				start.left = L;
				start.right = R;
			}
		}
	}
}


void solution()
{
	bfs(start);
}


void bfs(pos s)
{
	queue<pos> q;

	map[s.y][s.x] = '3';

	q.push(s);

	while (!q.empty())
	{
		pos temp = q.front();
		q.pop();
		cnt++;

#ifdef DEBUG
		cout << "process" << temp.y << " " << temp.x << "\n";
#endif 

		int tempY = temp.y;

		temp.y++;

		while (temp.y < N && map[temp.y][temp.x] == '0')
		{
			q.push(temp);
			map[temp.y][temp.x] = '3';

			temp.y++;
		}

		temp.y = tempY;
		temp.y--;

		while (temp.y >= 0 && map[temp.y][temp.x] == '0')
		{
			q.push(temp);
			map[temp.y][temp.x] = '3';

			temp.y--;
		}

		temp.y = tempY;

		for (int i = 0; i < 2; i++)
		{
			int dn = temp.x + dx[i];

			if (dn < 0 || dn >= M)
				continue;

			if (map[temp.y][dn] == '1' || map[temp.y][dn] == '3')
				continue;

			if (i == 0)
			{
				if (temp.left == 0)
					continue;

				map[temp.y][dn] = '3';

				temp.x--;
				temp.left--;
				q.push(temp);
				temp.x++;
				temp.left++;
			}
			else if (i == 1)
			{
				if (temp.right == 0)
					continue;

				map[temp.y][dn] = '3';

				temp.x++;
				temp.right--;
				q.push(temp);
				temp.x--;
				temp.right++;
			}
		}
	}
}


void debug()
{
	cout << "\n##debug##\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}


void output()
{
	cout << cnt;
}