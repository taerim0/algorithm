#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, temp;
int numcnt[1002];
int allcnt;
int prevnum = -2;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    allcnt = N;

    while (N--)
        cin >> temp, numcnt[temp]++;

    while (allcnt)
    {
        if (allcnt == 1)
            for (int i = 0; i < 1001; i++)
            {
                if (numcnt[i])
                {
                    ans.push_back(i);
                    allcnt--;
                    break;
                }
            }
        else
        {
            for (int i = 0; i < 1001; i++)
            {
                if (numcnt[i] && prevnum + 1 != i)
                {
                    if (numcnt[i + 1])
                    {
                        if (allcnt - numcnt[i + 1] - numcnt[i] > 0)
                        {
                            ans.push_back(i);
                            allcnt--;
                            numcnt[i]--;
                            prevnum = i;
                            break;
                        }
                    }
                    else
                    {
                        ans.push_back(i);
                        allcnt--;
                        numcnt[i]--;
                        prevnum = i;
                        break;
                    }
                }
            }
        }
    }

    for (int i : ans)
    {
        cout << i << " ";
    }
}
