#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

int N;

string arr[1001];

bool compare(string a, string b)
{
    char pivot = a[0], ud = NULL;
    for (int i = 0; i < a.size() && i < b.size(); i++)
    {
        if (pivot != NULL && a[i] != pivot)
            pivot = NULL, ud = a[i];
        if (a[i] == b[i])
            continue;
        return a[i] > b[i];
    }

    if (a.size() > b.size())
    {
        for (int i = b.size(); i < a.size(); i++)
        {
            if (a[i] == b[i - b.size()])
            {
                if (i == a.size() - 1)
                {
                    if (ud == NULL)
                        return false;
                    return a[i] > ud;
                }
                continue;
            }

            if (a[b.size()] <= b.back())
                return false;
            return true;
        }
    }
    else if (b.size() > a.size())
    {
        for (int i = a.size(); i < b.size(); i++)
        {

            if (b[i] == a[i - a.size()])
            {
                if (i == b.size() - 1)
                {
                    if (ud == NULL)
                        return false;
                    return b[i] < ud;
                }
                continue;
            }

            if (b[a.size()] <= a.back())
                return true;
            return false;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    bool isZero = true;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];

        if (arr[i][0] != '0')
            isZero = false;
    }

    if (isZero)
    {
        cout << 0;
        return 0;
    }

    sort(arr, arr + N, compare);

    for (int i = 0; i < N; i++)
        cout << arr[i];
}
