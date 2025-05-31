#include <iostream>

#define pii pair<int, int>

using namespace std;

int N, M;
int arr[100001];
pii tree[400001];

pii init(int now, int s, int e) {
  if (s == e) return tree[now] = { arr[s], arr[s] };
  int m = (s + e) >> 1;
  pii ls = init(now * 2, s, m);
  pii rs = init(now * 2 + 1, m + 1, e);
  return tree[now] = { min(ls.first, rs.first), max(ls.second, rs.second) };
}

pii query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return { 1000000001, 0 };
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  pii ls = query(now * 2, s, m, l, r);
  pii rs = query(now * 2 + 1, m + 1, e, l, r);
  return { min(ls.first, rs.first), max(ls.second, rs.second) };
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N + M; i++) {
    if (i < N + 1) cin >> arr[i];
    else {
      if (i == N + 1) init(1, 1, N);
      int a, b; cin >> a >> b;
      pii ans = query(1, 1, N, a, b);
      cout << ans.first << " " << ans.second << "\n";
    }
  }

}