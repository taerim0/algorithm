#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string m, temp;
int ans;
int ADDorSUB;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> m;

    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] == '+')
        {
            int num = stoi(temp);

            ans += num * pow(-1, ADDorSUB);

            temp = "";
        }
        else if (m[i] == '-')
        {
            int num = stoi(temp);

            ans += num * pow(-1, ADDorSUB);
            
            ADDorSUB = 1;

            temp = "";
        }
        else
        {
            temp += m[i];
        }
    }

    int num = stoi(temp);

    ans += num * pow(-1, ADDorSUB++);

    cout << ans;
}
