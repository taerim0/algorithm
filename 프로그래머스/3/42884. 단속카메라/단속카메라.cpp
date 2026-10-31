#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), compare);

    int end = -30001;
    for (auto r : routes)
        if (end < r[0])
            end = r[1], answer++;
    
    return answer;
}