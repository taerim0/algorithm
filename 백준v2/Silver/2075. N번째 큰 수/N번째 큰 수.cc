#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N * N; i++) {
        int n; cin >> n;
        if (i < N) pq.push(n);
        else if (n > pq.top()) {
            pq.pop(); pq.push(n);
        }
    }

    cout << pq.top();
}