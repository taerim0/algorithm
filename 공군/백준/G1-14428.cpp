#include <iostream>

#define pii pair<int, int>

using namespace std;

int N, M = 1;
int arr[100001];
pii tree[400001];

pii init(int now, int s, int e) {
  if (s == e) return tree[now] = { arr[s], s };
  int m = (s + e) >> 1;
  return tree[now] = min(init(now * 2, s, m), init(now * 2 + 1, m + 1, e));
}

pii query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return { 1e9 + 1, 0 };
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  return min(query(now * 2, s, m, l, r), query(now * 2 + 1, m + 1, e, l, r));
}

pii update(int now, int s, int e, int idx, int val) {
  if (idx < s || idx > e) return tree[now];
  if (s == e) return tree[now] = { val, s };
  int m = (s + e) >> 1;
  return tree[now] = min(update(now * 2, s, m, idx, val), update(now * 2 + 1, m + 1, e, idx, val));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for (int i = 1; i <= N + M; i++) {
    if (i <= N) cin >> arr[i];
    else {
      if (i == N + 1) {
        cin >> M; init(1, 1, N);
      }
      int a, b, c; cin >> a >> b >> c;
      if (a - 1) cout << query(1, 1, N, b, c).second << '\n';
      else update(1, 1, N, b, c);
    }
  }

}