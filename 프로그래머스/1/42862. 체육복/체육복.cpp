#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int findCnt = 0;
    bool isDone = false;
    vector<bool> isRsv(n, false);
    vector<bool> isSteal(n, false);
    for (auto l : lost)
        isSteal[l - 1] = true;
    for (auto r : reserve)
        if (isSteal[r - 1]) isSteal[r - 1] = false, findCnt++;
        else isRsv[r - 1] = true;
    
    for (int i = 0; i < n; i++) {
        if (isSteal[i]) {
            for (int j = -1; j <= 1; j += 2) {
                if (i + j < 0 || i + j >= n)
                    continue;
                if (!isRsv[i + j])
                    continue;
                isRsv[i + j] = false;
                findCnt++;
                if (findCnt == lost.size())
                    isDone = true;
                break;
            }
        }
        if (isDone) break;
    }
    return n - lost.size() + findCnt;
}