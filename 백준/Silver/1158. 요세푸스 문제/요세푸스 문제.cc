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

    cout << "<";

    while (q.size())
    {
        int k = K - 1;

        while (q.size() && k--)
        {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        if (q.size() > 1)
            cout << ", ";

        q.pop();
    }

    cout << ">";
}
