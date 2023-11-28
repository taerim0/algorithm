#include <iostream>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int N;
int arr[20][20];
bool team[20];
int teamA[10];
int teamB[10];
int ans = 2e9;

void make(int size, int nowsum, int idx)
{
    if (size == N / 2)
    {
        int anothersum = 0;

        for (int i = 0, k = 0; i < N; i++)
            if (!team[i])
                teamB[k++] = i;

        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                anothersum += arr[teamB[i]][teamB[j]] + arr[teamB[j]][teamB[i]];

        ans = min(ans, abs(nowsum - anothersum));

        return;
    }

    for (int i = idx; i < N; i++)
    {
        int tempsum = 0;

        for (int j = 0; j < size; j++)
        {
            tempsum += arr[teamA[j]][i] + arr[i][teamA[j]];
        }

        teamA[size] = i;
        team[i] = true;
        make(size + 1, nowsum + tempsum, i + 1);
        team[i] = false;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    make(0, 0, 0);

    cout << ans;
}