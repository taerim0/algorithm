#include <string>
#include <vector>

using namespace std;

int gn, cnt;
bool visited[200];

void dfs(const vector<vector<int>>& computers, int now) {
    visited[now] = true;
    for (int i = 0; i < gn; i++) {
        if (computers[now][i] && !visited[i]) {
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    gn = n;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(computers, i);
        }
    }
    return cnt;
}