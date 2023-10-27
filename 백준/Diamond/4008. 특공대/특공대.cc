#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pl pair<ll, ll>

using namespace std;

int n;
int pos;
ll a, b, c;

ll sd[1000000];
ll as[1000000];
ll dp[1000000];

inline ll f1(int v)
{
    return -2 * a * as[v] + b;
}

inline ll f2(int v)
{
    return a * as[v] * as[v] - b * as[v] + dp[v];
}

struct cht
{
    int s = 0, e = 0;
    int idx[1000000];

    pl line[1000000];

    double cross(int a, int b)
    {
        return 1.0 * (line[a].second - line[b].second) / (line[b].first - line[a].first);
    }

    void insert(pl v, int i)
    {
        line[e] = v;
        idx[e] = i;
        while (s + 1 < e && cross(e - 2, e - 1) > cross(e - 1, e))
        {
            line[e - 1] = line[e];
            idx[e - 1] = idx[e];
            e--;
        }
        e++;
    }

    pl query2(ll x)
    {
        int l = 0, r = e - 1;
        while (l != r)
        {
            int m = (l + r) / 2;
            if (cross(m, m + 1) <= x)
                l = m + 1;
            else r = m;
        }
        return pl(line[l].first * x + line[l].second, idx[l]);
    }
}cht;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> c >> sd[0];
    as[0] = sd[0];

    for (int i = 1; i < n; i++)
        cin >> sd[i], as[i] = as[i - 1] + sd[i];

    cht.insert({ b, 0 }, 0);

    for (int i = 0; i < n; i++)
    {
        dp[i] = a * as[i] * as[i] + cht.query2(as[i]).first + c;
        cht.insert({ f1(i), f2(i) }, i);
    }

    /*for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
    cout << "\n";*/

    cout << dp[n - 1];
}