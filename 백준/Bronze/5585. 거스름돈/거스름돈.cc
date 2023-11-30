#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int N;
int cnt[6];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    N = 1000 - N;
    cnt[0] = N / 500;
    N -= cnt[0] * 500;
    cnt[1] = N / 100;
    N -= cnt[1] * 100;
    cnt[2] = N / 50;
    N -= cnt[2] * 50;
    cnt[3] = N / 10;
    N -= cnt[3] * 10;
    cnt[4] = N / 5;
    N -= cnt[4] * 5;
    cnt[5] = N / 1;
    N -= cnt[5] * 1;

    cout << cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5];
}