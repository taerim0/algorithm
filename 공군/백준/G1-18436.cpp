#include <iostream>

#define pii pair<int, int>

using namespace std;

int N, M = 1;
int arr[100001];
pii tree[400001];

pii init(int now, int s, int e) {
  if (s == e) {
    if (arr[s] % 2) return tree[now] = { 0, 1 };
    return tree[now] = { 1, 0 };
  }
  int m = (s + e) >> 1;
  pii ls = init(now * 2, s, m);
  pii rs = init(now * 2 + 1, m + 1, e);
  return tree[now] = { ls.first + rs.first, ls.second + rs.second };
}

pii query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return { 0, 0 };
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  pii ls = query(now * 2, s, m, l, r);
  pii rs = query(now * 2 + 1, m + 1, e, l, r);
  return { ls.first + rs.first, ls.second + rs.second };
}

pii update(int now, int s, int e, int idx, int val) {
  if (idx < s || idx > e) return tree[now];
  if (s == e) {
    if (val % 2) return tree[now] = { 0, 1 };
    return tree[now] = { 1, 0 };
  }
  int m = (s + e) >> 1;
  pii ls = update(now * 2, s, m, idx, val);
  pii rs = update(now * 2 + 1, m + 1, e, idx, val);
  return tree[now] = { ls.first + rs.first, ls.second + rs.second };
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 1; i <= N + M; i++) {
    if (i < N + 1) cin >> arr[i];
    else {
      if (i == N + 1) {
        cin >> M;
        init(1, 1, N);
      }
      int a, b, c; cin >> a >> b >> c;
      if (a == 1) {
        update(1, 1, N, b, c);
      }
      else if (a == 2) {
        cout << query(1, 1, N, b, c).first << "\n";
      }
      else {
        cout << query(1, 1, N, b, c).second << "\n";
      }
    }
  }

}