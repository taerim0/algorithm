#include <iostream>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

int N;

ll num, pre;
ll PrevMax;
ll ans;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    N--;
    cin >> pre;
    PrevMax = pre;

    while (N--)
    {
        cin >> num;

        if (num == pre)
            continue;

        if (num > pre)
        {
            if (num > PrevMax)
                ans += num - PrevMax, PrevMax = num;
        }
        else
            ans += pre - num;
        pre = num;
    }

    cout << ans;
}
