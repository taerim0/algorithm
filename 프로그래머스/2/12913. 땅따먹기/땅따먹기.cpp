#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001][5];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for (int i = 1; i <= 4; i++)
        dp[1][i] = land[0][i - 1];

    for (int i = 2; i <= land.size(); i++)
        for (int j = 1; j <= 4; j++) {
            int best = 0;
            for (int k = 1; k <= 4; k++) {
                if (j == k) continue;
                best = max(best, dp[i - 1][k]);
            }
            dp[i][j] = land[i - 1][j - 1] + best;
        }
    
    for (int i = 1; i <= 4; i++)
        answer = max(answer, dp[land.size()][i]);

    return answer;
}