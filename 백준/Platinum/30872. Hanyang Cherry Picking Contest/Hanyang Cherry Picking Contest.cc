#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int N;
ll point[200002];
bool check[200002];
vector<int> tree[200002];

pair<pll, int> cherry(int now)
{
    ll P[2] = { 0 };
    int who = 0;
    ll rest[2] = { 0 };
    P[who] += point[now];
    priority_queue<pair<pair<ll, int>, pll>> pq;
    who = ++who % 2;

    for (int i = 0; i < tree[now].size(); i++)
    {
        if (!check[tree[now][i]])
        {
            check[tree[now][i]] = true;
            auto [data, chg] = cherry(tree[now][i]);
            auto [a, b] = data;

            if (a - b >= 0 && !chg)
                P[1] += a, P[0] += b;
            else if (!chg)
                rest[0] += a, rest[1] += b;
            else
                pq.push({ { a - b, -chg }, { a, b } });
        }
    }

    while (pq.size())
    {
        auto [data, elem] = pq.top();
        auto [val, chg] = data;
        auto [a, b] = elem;

        pq.pop();

        P[who] += a;
        P[(who + 1) % 2] += b;

        if (chg)
            who = ++who % 2;
    }

    P[who] += rest[0]; P[(who + 1) % 2] += rest[1];

    /*cout << "## " << now << " ## : " << P[0] << " and " << P[1] << ", chg is " << who << "\n";*/

    return { { P[0], P[1] }, who };
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0, a, b; i < N - 1; i++)
    {
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> point[i];
    }

    check[1] = true;
    auto [data, chg] = cherry(1);
    auto [a, b] = data;

    /*cout << a << " : " << b << "\n";*/

    a == b ? cout << "Draw" : a > b ? cout << "Sehun" : cout << "Cheolmin";
}
