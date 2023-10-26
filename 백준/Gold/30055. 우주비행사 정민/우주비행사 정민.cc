#include <iostream>
#include <queue>
#include <vector>

#define pos pair<int, int>
#define dpos pair<int, pos>

using namespace std;

int K;
int n1, m1, n2, m2;
int A, B;

pos g1, g2;
int map[2][200][200];
priority_queue<pair<int, pair<bool, dpos>>> q;

int at = 1;

bool hing;

int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };

void bfs()
{
	while (q.size())
	{
		auto [nv, d] = q.top();
		auto [t, p] = d;
		auto [dim, np] = p;
		auto [y, x] = np;
		q.pop();

		if (at != 1 && at != nv)
			break;

		if (t)
		{
			int v = y % 2 ? -1 : 1;

			int dn = x + v;
			int dm = y;

			if (dim)
			{
				if (y == n2 - 1 && x == 0)
				{
					dm = 0; dn = 0;
				}
				else if (dn >= m2 || dn < 0)
				{
					dm += 1; dn = x;
				}
			}
			else
			{
				if (y == n1 - 1 && x == 0)
				{
					dm = 0; dn = 0;
				}
				else if (dn >= m1 || dn < 0)
				{
					dm += 1; dn = x;
				}
			}

			if (map[dim][dm][dn] != -1)
			{
				map[dim][dm][dn] = -1;
				q.push({ nv + -2, { t, { dim, { dm, dn } } } });
			}
		}
		else
		{
			if (map[dim][y][x] == -1)
				continue;

			if (dim == 1 && y == n2 - 1 && x == m2 - 1)
				at = nv;

			for (int i = 0; i < 5; i++)
			{
				int dm = y + dy[i];
				int dn = x + dx[i];

				if (dim)
				{
					if (i == 4)
					{
						if (dm < g2.first || dm >= g2.first + A || dn < g2.second || dn >= g2.second + B)
							break;

						int m = dm - g2.first;
						int n = dn - g2.second;

						if (map[0][g1.first + m][g1.second + n] != 0)
								continue;

						map[0][g1.first + m][g1.second + n] = map[1][y][x] + 3;
						q.push({ nv + -6, { t, { 0, { g1.first + m, g1.second + n } } } });
					}
					else
					{
						if (dm >= n2 || dm < 0 || dn >= m2 || dn < 0)
							continue;

						if (map[1][dm][dn] != 0)
								continue;

						map[1][dm][dn] = map[1][y][x] + 1;
						q.push({ nv + -2, { t, { 1, { dm, dn } } } });
					}
				}
				else
				{
					if (i == 4)
					{
						if (dm < g1.first || dm >= g1.first + A || dn < g1.second || dn >= g1.second + B)
							break;

						int m = dm - g1.first;
						int n = dn - g1.second;

						if (map[1][g2.first + m][g2.second + n] != 0)
								continue;

						map[1][g2.first + m][g2.second + n] = map[0][y][x] + 3;
						q.push({ nv + -6, { t, { 1, { g2.first + m, g2.second + n } } } });
					}
					else
					{
						if (dm >= n1 || dm < 0 || dn >= m1 || dn < 0)
							continue;

						if (map[0][dm][dn] != 0)
								continue;

						map[0][dm][dn] = map[0][y][x] + 1;
						q.push({ nv + -2, { t, { 0, { dm, dn } } } });
					}
				}
					
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> n1 >> m1 >> n2 >> m2;
	cin >> A >> B;
	cin >> g1.first >> g1.second;
	cin >> g2.first >> g2.second;

	map[0][0][0] = 1;
	q.push({ 0, { false, { 0, { 0, 0 } } } });

	for (int i = 0, a, b, c; i < K; i++)
	{
		cin >> a >> b >> c;
		map[a - 1][b][c] = -1;
		q.push({ -1, { true, { a - 1, { b, c } } } });
	}

	bfs();

	/*cout << "map 0 :\n";
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			cout << map[0][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "map 1 :\n";
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			cout << map[1][i][j] << " ";
		}
		cout << "\n";
	}*/

	map[1][n2 - 1][m2 - 1] > 0 ? cout << map[1][n2 - 1][m2 - 1] - 1 : cout << "hing...";
}