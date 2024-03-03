#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long

using namespace std;

int T;
int cnt;
int X, Y, x, y;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    while (T--) {

        int choco[50][50] = { 0 };
        cnt = 0;

        cin >> X >> Y >> x >> y;

        for (int i = 0; i < Y; i++) {

            for (int j = 0; j < X; j++) {

                if (i - y < 0 || j - x < 0) {

                    choco[i][j] = 1; cnt++; continue;
                }

                if (choco[i - y][j - x])
                    continue;

                choco[i][j] = 1;
                cnt++;
            }
        }

        cout << cnt << "\n";
    }
}
