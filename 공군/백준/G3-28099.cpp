#include <iostream>

#define pii pair<int, int>

using namespace std;

int T, N;
int arr[200001];
int cpn[200001];
int tree[800001];
bool isStrange;

int init(int now, int s, int e) {
  if (s == e) return tree[now] = arr[s];
  int m = (s + e) >> 1;
  return tree[now] = max(init(now * 2, s, m), init(now * 2 + 1, m + 1, e));
}

int query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return -1;
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  return max(query(now * 2, s, m, l, r), query(now * 2 + 1, m + 1, e, l, r));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T; while (T--) {
    cin >> N; isStrange = true;
    for (int i = 1; i <= N; i++) {
      cin >> arr[i];
      cpn[i] = -1;
    }
    init(1, 1, N);
    for (int i = 1; i <= N; i++) {
      if (cpn[arr[i]] == -1) {
        cpn[arr[i]] = i;
      }
      else {
        int btwmax = query(1, 1, N, cpn[arr[i]], i);
        cpn[arr[i]] = i;
        if (btwmax > arr[i]) {
          isStrange = false;
        }
      }
    }
    if (isStrange) cout << "Yes\n";
    else cout << "No\n";
  }
}