#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long

using namespace std;

int T;

int N, A, B;
int pos;
int same;
ll Asum, Bsum;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    while (T--) {

        Asum = 0, Bsum = 0, same = 0;

        cin >> N >> A >> B;

        for (int i = 0; i < N; i++) {
            
            cin >> pos;

            int which = abs(pos - B) - abs(pos - A);
 
            if (which > 0) {

                Asum += abs(pos - A) * 2;
            }
            else if (which < 0) {

                Bsum += abs(pos - B) * 2;
            }
            else {

                same++;
            }
        }

        for (int i = 0; i < same; i++) {

            if (Asum > Bsum)
                Bsum += abs(A - B);
            else
                Asum += abs(A - B);
        }

        cout << Asum + Bsum << " " << abs(Asum - Bsum) << "\n";
    }
}
