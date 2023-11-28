#include <iostream>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int N, M, K;
int arr[10][10];
pii now[4];
int ans = -2e9;

void make(int size, int nowsum)
{
    if (size == K)
    {
        ans = max(ans, nowsum);

        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bool isOver = false;

            for (int k = 0; k < size; k++)
            {
                if (abs(i - now[k].first) + abs(j - now[k].second) < 2)
                {
                    isOver = true;
                    break;
                }
            }

            if (isOver)
                continue;

            now[size] = { i, j };
            make(size + 1, nowsum + arr[i][j]);
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    make(0, 0);

    cout << ans;
}