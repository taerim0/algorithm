#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

#define ll long long

int N, M;

ll arr[1000001];
ll pf_sum[1000001];

ll remains[1001];

ll ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        pf_sum[i] = (pf_sum[i - 1] + arr[i]) % M;

        remains[pf_sum[i]]++;
    }
    
    ans += remains[0];

    for (int i = 0; i < M; i++) {
        ans += (remains[i] * (remains[i] - 1)) / 2;
    }

    cout << ans;
}