#include <iostream>

#define ll long long

using namespace std;

ll a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (1)
    {
        cin >> a >> b;

        if (!a && !b)
            break;

        cout << a + b << "\n";
    }
}
