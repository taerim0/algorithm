#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int L, C;
char now[15];
char alpha[15];

void solve(int n, int x, int mcnt, int jcnt)
{
    if (n == L)
    {
        if (mcnt < 1 || jcnt < 2)
            return;

        for (int i = 0; i < n; i++)
        {
            cout << now[i];
        }
        cout << "\n";
        
        return;
    }

    for (int i = x; i < C; i++)
    {
        if (C - i - (L - n) < 0)
            break;

        now[n] = alpha[i];
        if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
            solve(n + 1, i + 1, mcnt + 1, jcnt);
        else
            solve(n + 1, i + 1, mcnt, jcnt + 1);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> alpha[i];
    }

    sort(alpha, alpha + C);

    solve(0, 0, 0, 0);
}