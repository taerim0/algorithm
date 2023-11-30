#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int N;
int nowsum, ans;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    while (N--)
    {
        int a;
        cin >> a;
        pq.push(-a);
    }

    while (pq.size())
    {
        nowsum -= pq.top();
        ans += nowsum;
        pq.pop();
    }

    cout << ans;
}