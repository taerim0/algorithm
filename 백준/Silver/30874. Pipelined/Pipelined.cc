#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0, a; i < N; i++)
    {
        cin >> a;
        ans = max(a, ans);
    }

    cout << ans + N - 1;
}