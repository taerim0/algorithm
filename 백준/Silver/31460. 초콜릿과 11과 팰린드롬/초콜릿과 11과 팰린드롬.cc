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

        int N;

        cin >> N;

        if (N == 1)
            cout << "0\n";
        else if (N % 2 == 0) {

            for (int i = 0; i < N; i++)
                cout << 1;
            cout << "\n";
        }
        else {

            for (int i = 0; i < N; i++) {

                if (i == 0 || i == N - 1)
                    cout << 1;
                else
                    cout << 2;
            }

            cout << "\n";
        }
    }
}
