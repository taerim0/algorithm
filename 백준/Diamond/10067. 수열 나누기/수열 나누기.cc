#include <iostream>
#include <vector>
#include <queue>

#define ll long long
#define pl pair<ll, ll>

using namespace std;

int n, k;

ll sq[100001];
ll ss[100001];
ll dp[2][100001];

int endc[201][100001];
int ans[201];

struct cht
{
    int s = 0, e = 0;
    int idx[100001];

    pl line[100001];

    double cross(int a, int b)
    {
        return 1.0 * (line[a].second - line[b].second) / (line[b].first - line[a].first);
    }

    void insert(pl v, ll i)
    {
        line[e] = v;
        idx[e] = i;
        while (s < e && (line[e].first == line[e - 1].first) && line[e - 1].second <= line[e - 1].second)
        {
            line[e - 1] = line[e];
            idx[e - 1] = idx[e];
            e--;
        }
        while (s + 1 < e && cross(e - 2, e - 1) > cross(e - 1, e))
        {
            line[e - 1] = line[e];
            idx[e - 1] = idx[e];
            e--;
        }
        e++;
    }

    pl query(ll x)
    {
        while (s + 1 < e && line[s + 1].second - line[s].second >= x * (line[s].first - line[s + 1].first))
            s++;
        return { line[s].first * x + line[s].second, idx[s] };
    }

    void clear() { s = e = 0; }

}cht;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> sq[i], ss[i] = ss[i - 1] + sq[i];

    for (int i = 1; i <= k; i++)
    {
        cht.clear();

        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[1][j];

        for (int j = 1; j <= n; j++)
        {
            dp[1][j] = cht.query(ss[j]).first;

            endc[i][j] = (int)cht.query(ss[j]).second;

            cht.insert({ ss[j], -ss[j] * ss[j] + dp[0][j] }, j);
        }
    }
    
    cout << dp[1][n] << "\n";

    for (int i = k; i >= 1; i--)
    {
        ans[i] = endc[i][n];
        n = endc[i][n];
    }

    for (int i = 1; i <= k; i++)
        cout << ans[i] << " ";
}