#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int N, endt;
int cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<pii> v(N);

    for (pii& a : v)
    {
        cin >> a.second >> a.first;
    }

    sort(v.begin(), v.end());

    for (pii& a : v)
    {
        if (a.second >= endt)
        {
            endt = a.first;
            cnt++;
        }
    }

    cout << cnt;
}