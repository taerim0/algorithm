#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define pii pair<int, int>
#define ll long long

using namespace std;

int a;
string people[500];
bool itsOver;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a;

    for (int i = 0; i < a; i++)
        cin >> people[i];

    for (int i = 0; i < a - 1; i++) {
        
        int ans;

        cout << "? " << people[i] << "\n", cout << flush;;

        cin >> ans;

        if (ans)
            cout << "! " << people[i] << "\n", itsOver = true, cout << flush;
        if (itsOver)
            break;

        cout << "? " << people[i] << "\n", cout << flush;

        cin >> ans;

        if (ans)
            cout << "! " << people[i] << "\n", itsOver = true, cout << flush;
        if (itsOver)
            break;
    }

    if (!itsOver)
        cout << "! " << people[a - 1] << "\n";

    cout << flush;
}
