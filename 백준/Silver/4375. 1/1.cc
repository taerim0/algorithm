#include <iostream>

#define ll long long

using namespace std;

ll n, one, cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n)
    {
        one = 1; cnt = 1;

        while (one %= n)
        {
            one = one * 10 + 1;
            cnt++;
        }

        cout << cnt << "\n";
    }
}