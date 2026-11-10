#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score[3];
int maxVal;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> iter;
    iter.push_back({1, 2, 3, 4, 5});
    iter.push_back({2, 1, 2, 3, 2, 4, 2, 5});
    iter.push_back({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < answers.size(); j++)
            if (iter[i][j % iter[i].size()] == answers[j])
                score[i]++;
    for (int i = 0; i < 3; i++)
        maxVal = max(maxVal, score[i]);
    for (int i = 0; i < 3; i++)
        if (score[i] == maxVal) answer.push_back(i + 1);
    
    return answer;
}