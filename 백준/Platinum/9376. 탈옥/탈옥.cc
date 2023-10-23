#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int T;
int h, w;
int ans;
char map[102][102];
int check[3][102][102];

vector<pair<int, int>> p;



int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void define_door(int m, pair<int, int> p)
{
	priority_queue<pair<int, pair<int, int>>> pq;

	pq.push(make_pair(-0, p));
	check[m][p.first][p.second] = 0;

	while (!pq.empty())
	{
		int t = -pq.top().first;
		pair<int, int> pos = pq.top().second;

		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int dm = pos.first + dy[i];
			int dn = pos.second + dx[i];

			if (dm >= h + 2 || dm < 0 || dn >= w + 2 || dn < 0)
				continue;

			if (map[dm][dn] == '*')
				continue;

			if (check[m][dm][dn] == -1)
			{
				if (map[dm][dn] == '.' || map[dm][dn] == '$')
				{
					check[m][dm][dn] = t;
					pq.push(make_pair(-t, make_pair(dm, dn)));
				}
				else if (map[dm][dn] == '#')
				{
					check[m][dm][dn] = t + 1;
					pq.push(make_pair(-(t + 1), make_pair(dm, dn)));
				}
			}
		}
	}
}

void print_check()
{
	for (int l = 0; l < 3; l++)
	{
		for (int i = 0; i < h + 2; i++)
		{
			for (int j = 0; j < w + 2; j++)
			{
				cout << setw(2) << check[l][i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	for (int i = 0; i < h + 2; i++)
	{
		for (int j = 0; j < w + 2; j++)
		{
			cout << setw(2) << check[0][i][j] + check[1][i][j] + check[2][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> h >> w;

		ans = 2100000000;

		p.push_back(make_pair(0, 0));

		for (int i = 0; i < h + 2; i++)
		{
			for (int j = 0; j < w + 2; j++)
			{
				if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
					map[i][j] = '.';
				else
					cin >> map[i][j];

				if (map[i][j] == '$')
					p.push_back(make_pair(i, j));

				check[0][i][j] = -1;
				check[1][i][j] = -1;
				check[2][i][j] = -1;
			}
		}
		
		for (int i = 0; i < 3; i++)
		{
			define_door(i, p.back());
			p.pop_back();
		}

		for (int i = 1; i < h + 1; i++)
		{
			for (int j = 1; j < w + 1; j++)
			{
				int sum = check[0][i][j] + check[1][i][j] + check[2][i][j];

				if (sum == -3)
					continue;

				if (map[i][j] == '#')
					sum -= 2;

				ans = min(ans, sum);
			}
		}

		//print_check();

		cout << ans << "\n";
	}
}