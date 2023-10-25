#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define f11 for (int i11 = 0; i11 < 11; i11++)
#define FOR(i) for (fd[i] = 0; fd[i] < d[i]; fd[i]++)
#define F FOR(10) FOR(9) FOR(8) FOR(7) FOR(6) FOR(5) FOR(4) FOR(3) FOR(2) FOR(1) FOR(0)
#define a(i, arr) arr[i]*md[i]
#define SUMofArr(arr) a(0, arr)+a(1, arr)+a(2, arr)+a(3, arr)+a(4, arr)+a(5, arr)+a(6, arr)+a(7, arr)+a(8, arr)+a(9, arr)+a(10, arr)
#define TupleofArr(arr) {arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9],arr[10]}
#define tuple11 tuple<int, int, int, int, int, int, int, int, int, int, int>

using namespace std;

int d[11];
int md[11];
int fd[11];

bool isAlreadyDone = true;
int ans = -1;
int cnt0;

int box[1000000];
int check[1000000];

int dd[22][11] =
{
{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

queue<tuple11> q;

void bfs()
{
	while (q.size())
	{
		tuple11 now = q.front();
		q.pop();

		for (int i = 0; i < 22; i++)
		{
			int next[11];

			next[0] = get<0>(now);
			next[1] = get<1>(now);
			next[2] = get<2>(now);
			next[3] = get<3>(now);
			next[4] = get<4>(now);
			next[5] = get<5>(now);
			next[6] = get<6>(now);
			next[7] = get<7>(now);
			next[8] = get<8>(now);
			next[9] = get<9>(now);
			next[10] = get<10>(now);

			int prev = SUMofArr(next);

			f11 next[i11] += dd[i][i11];

			bool con = false;
			
			f11	if (next[i11] >= d[i11] || next[i11] < 0)
			{
				con = true;
				break;
			}

			if (con) continue;

			if (check[SUMofArr(next)] != 0 || box[SUMofArr(next)] != 0)
				continue;

			cnt0--;
			check[SUMofArr(next)] = check[prev] + 1;
			ans = max(ans, check[SUMofArr(next)]);
			q.push(TupleofArr(next));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	f11
	{
		cin >> d[i11];

		if (i11 == 0)
			md[i11] = 1;
		else
			md[i11] = d[i11 - 1] * md[i11 - 1];
		
	}

	F
	{
		cin >> box[SUMofArr(fd)];

		if (box[SUMofArr(fd)] == 0)
		{
			isAlreadyDone = false;
			cnt0++;
		}

		if (box[SUMofArr(fd)] == 1)
			q.push(TupleofArr(fd));
	}
	
	if (isAlreadyDone)
	{
		cout << 0;
		return 0;
	}

	bfs();

	cnt0 ? cout << -1 : cout << ans;
}
