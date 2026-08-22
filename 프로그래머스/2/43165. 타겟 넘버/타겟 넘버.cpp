#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[21];
int cnt;
vector<int> nbs;
int tg;

void dfs(int now, int val) {
    int pval = val + nbs[now];
    int mval = val - nbs[now];
    now++;
    if (now == nbs.size()) {
        if (pval == tg)
            cnt++;
        if (mval == tg)
            cnt++;
        return;
    }
    dfs(now, pval); dfs(now, mval);
}

int solution(vector<int> numbers, int target) {
    nbs = numbers;
    tg = target;
    dfs(0, 0);
    return cnt;
}