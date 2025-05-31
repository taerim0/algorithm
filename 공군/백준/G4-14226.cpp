#include <iostream>
#include <queue>

using namespace std;

typedef struct {
  int now, clipboard, time;
}node;

int S, ans;
bool check[10000][10000];

void bfs() {
  queue<node> q;
  q.push({ 1, 0, 0 });
  while (q.size()) {
    node n = q.front();
    q.pop();

    if (n.now == S) {
      cout << n.time;
      return;
    }

    q.push({ n.now, n.now, n.time + 1 });
    if (n.now != 0) {
      if (!check[n.now - 1][n.clipboard]) {
        check[n.now - 1][n.clipboard] = true;
        q.push({ n.now - 1, n.clipboard, n.time + 1 });
      }
      if (n.clipboard != 0) {
        if (!check[n.now + n.clipboard][n.clipboard]) {
          check[n.now + n.clipboard][n.clipboard] = true;
          q.push({ n.now + n.clipboard, n.clipboard, n.time + 1 });
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> S;
  bfs();
}