#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define pdd pair<double, double>

using namespace std;

int N;

vector<pdd> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(1);

    cin >> N;

    for (double i = 0, a, b; i < N; i++)
    {
        cin >> a >> b;
        v.push_back({ a, b });
    }

    double area = 0;

    for (int i = 1; i < N - 1; i++)
        area += ((v[i].first - v[0].first) * (v[i + 1].second - v[0].second) - (v[i].second - v[0].second) * (v[i + 1].first - v[0].first)) / 2.0;
    
    area < 0 ? cout << area * -1 : cout << area;
}
