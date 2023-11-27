#include <iostream>
#include <queue>


using namespace std;

int N, K;
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
       
    for (int i = 1; i <= N; i++)
        q.push(i);

    while (q.size() > K)
    {
        q.push(q.front());
        for (int i = 0; i < K; i++)
            q.pop();
    }

    cout << q.front();
}