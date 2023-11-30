#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int R, C, ans;
char mine[752][752];
int uld[752][752], urd[752][752], lld[752][752], lrd[752][752];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> mine[i][j];

            if (mine[i][j] == '1')
            {
                uld[i][j] = uld[i - 1][j + 1] + 1;
                urd[i][j] = urd[i - 1][j - 1] + 1;
            }
        }
    }

    for (int i = R; i > 0; i--)
    {
        for (int j = C; j > 0; j--)
        {
            if (mine[i][j] == '1')
            {
                lld[i][j] = lld[i + 1][j + 1] + 1;
                lrd[i][j] = lrd[i + 1][j - 1] + 1;
            }
        }
    }

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            for (int k = 1; k <= min(uld[i][j], lld[i][j]); k++)
            {
                if (min(urd[i][j + (k - 1) * 2], lrd[i][j + (k - 1) * 2]) >= k)
                    ans = max(ans, k);
            }
        }
    }

    cout << ans;
}