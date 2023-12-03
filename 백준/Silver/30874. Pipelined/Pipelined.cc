#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int check[200001];
vector<int> arr;
int ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0, a; i < N; i++)
    {
        cin >> a;

        if (!check[a])
            arr.push_back(a);

        check[a]++;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        ans += check[arr[i]];
    }

    cout << ans + arr.back() - 1;
}