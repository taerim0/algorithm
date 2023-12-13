#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int card[10];
int nowcard;
int prevcard = -1;
string ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < 10; i++)
        cin >> card[i], nowcard += card[i];

    while (nowcard)
    {
        int maxcard = -1, maxidx = -1;

        for (int i = 0; i < 10; i++)
            if (card[i] > maxcard)
                maxcard = card[i], maxidx = i;

        if (maxcard > nowcard - maxcard + 1)
        {
            nowcard--;
            card[maxidx]--;
        }
        else if (maxcard == nowcard - maxcard + 1)
        {
            if (maxidx == prevcard)
            {
                cout << 0;
                return 0;
            }

            prevcard = maxidx;

            if (ans.size() || maxidx != 0)
                ans += '0' + maxidx;
            card[maxidx]--;
            nowcard--;
        }
        else
        {
            for (int i = 9; i > -1; i--)
                if (card[i] && prevcard != i)
                {
                    card[i]--, nowcard--;
                    prevcard = i;
                    ans += '0' + i;
                    break;
                }
        }
    }

    ans.size() > 0 ? cout << ans : cout << 0;
}
