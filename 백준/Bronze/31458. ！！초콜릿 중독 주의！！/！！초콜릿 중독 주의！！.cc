#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<int, int>

using namespace std;

int T;

int nowlen;
int nowcnt;
string order;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    while (T--) {

        nowcnt = 0, nowlen = 0;

        cin >> order;

        for (char a : order) {
            
            nowlen++;

            if (a == '!')
                nowcnt++;
            else if (a == '0') {
                
                if (nowlen == order.length()) {

                    if (nowcnt % 2 == 0)
                        cout << "0\n";
                    else
                        cout << "1\n";
                }
                else {

                    if (nowcnt % 2 == 0)
                        cout << "1\n";
                    else
                        cout << "0\n";
                }
            }
            else if (a == '1') {

                if (nowcnt % 2 == 0)
                    cout << "1\n";
                else
                    cout << "0\n";
            }
        }
    }
}
