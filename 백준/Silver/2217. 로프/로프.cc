#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int N;
int nowmin = 2e9;
int ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<int> v(N);

    for (int& a : v)
        cin >> a;

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < N; i++)
    {
        nowmin = min(nowmin, v[i]);
        ans = max(ans, nowmin * (i + 1));
    }

    cout << ans;
}