#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;


// typedef

typedef struct
{
	int x, y;
}POS;


// variable

int N;
int min_fatigue = INT_MAX;

int lt, rt;
vector<int> height_level;

POS P;
int K_cnt;
char maps[51][51];
int height[51][51];
bool check[51][51];

int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };


// fuction prototype

void input();
void solution();
int dfs(int y, int x, int t);
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

	return 0;
}


void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> maps[i][j];

			if (maps[i][j] == 'P')
			{
				P.y = i; P.x = j;
			}
			if (maps[i][j] == 'K')
				K_cnt++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> height[i][j];

			height_level.push_back(height[i][j]);
		}
	}

	sort(height_level.begin(), height_level.end());
	height_level.erase(unique(height_level.begin(), height_level.end()), height_level.end());

	return;
}


void solution()
{
	while (height[P.y][P.x] > height_level[rt])
		rt++;

	while (rt < height_level.size() && lt < height_level.size() && height_level[lt] <= height[P.y][P.x])
	{
		bool isWork = false;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				check[i][j] = false;

		if (dfs(P.y, P.x, 0) == K_cnt)
		{
			min_fatigue = min(min_fatigue, height_level[rt] - height_level[lt]);
			isWork = true;
			lt++;
		}
		else
			rt++;

#ifdef DEBUG
		if (isWork)
			cout << "min_height : " << height_level[lt - 1] << ", max_height : " << height_level[rt] << ", min fatigue : " << min_fatigue << "\nisWork? : true\n";
		else
			cout << "min_height : " << height_level[lt] << ", max_height : " << height_level[rt - 1] << ", min fatigue : " << min_fatigue << "\nisWork? : false\n";
#endif
	}

	return;
}


int dfs(int y, int x, int t)
{
	if (check[y][x])
		return t;

	check[y][x] = true;

	if (maps[y][x] == 'K')
		t++;

	for (int i = 0; i < 8; i++)
	{
		int dm = y + dy[i];
		int dn = x + dx[i];

		if (dm < 0 || dn < 0 || dm >= N || dn >= N)
			continue;

		if (height[dm][dn] > height_level[rt] || height[dm][dn] < height_level[lt])
			continue;

		t = dfs(dm, dn, t);
	}

	return t;
}


void debug()
{
	cout << "### height_level elements ###\n";
	for (int i = 0; i < height_level.size(); i++)
		cout << " " << height_level[i];
	cout << "\n";

	return;
}


void output()
{
	cout << min_fatigue;

	return;
}