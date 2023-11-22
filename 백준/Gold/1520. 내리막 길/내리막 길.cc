#include <iostream>

using namespace std;


// Dynamic Programming

int dp[501][501];


// variable

int M, N; // 지도 사이즈
int map[501][501]; // 지도
int x[] = { 0, 0, -1, 1 };
int y[] = { -1, 1, 0, 0 };

int answer;


// function prototype

void input();
void solution();
void DEBUG();
int dfs(int m, int n);
void output();


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
	output();
}


void input() // 입력 함수
{
	cin >> M >> N;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	return;
}


void solution() // 풀이
{
	answer = dfs(0, 0);

	return;
}

int dfs(int m, int n)
{
	if (m == M - 1 && n == N - 1)
		return 1;

	if (dp[m][n] != -1) // 이미 탐색한 부분이면 탐색 종료
		return dp[m][n];

	dp[m][n] = 0;

	for (int i = 0; i < 4; i++)
	{
		int dm = m + x[i];
		int dn = n + y[i];

		if (dm < 0 || dm >= M || dn < 0 || dn >= N) continue; // 지도 범위 초과 시 skip

		if (map[m][n] > map[dm][dn])
		{
			dp[m][n] += dfs(dm, dn);
		}
	}

	return dp[m][n];
}

void DEBUG() // 디버그 함수 (2차원 배열 dp 출력)
{
	cout << "\n";
	cout << "dp :\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << " " << dp[i][j];
		}
		cout << "\n";
	}
}


void output() // 출력 함수
{
	cout << answer;
}