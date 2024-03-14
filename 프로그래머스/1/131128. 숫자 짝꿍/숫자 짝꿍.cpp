#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int x[10];
int y[10];

string solution(string X, string Y)
{
    
    string answer = "";
    
    for (int i=0;i<X.size();i++)
    {
        x[X[i] - '0']++;
    }
    for (int i=0;i<Y.size();i++)
    {
        y[Y[i] - '0']++;
    }
    for (int i=9;i>=0;i--)
    {
        if (x[i] == 0 || y[i] == 0)
            continue;
        
        int num = min(x[i], y[i]);
        
        for (int j=0;j<num;j++)
        {
            answer += '0' + i;
        }
    }
    
    if (answer.size() == 0)
        return "-1";
    if (answer[0] == '0')
        return "0";
    return answer;
}