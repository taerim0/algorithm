#include <iostream>

#define ll long long

using namespace std;

int N, M;
ll arr[1000001];
ll tree[4000001];

ll init(int now, int s, int e) {
  if (s == e) return tree[now] = arr[s];
  int m = (s + e) >> 1;
  return tree[now] = init(now * 2, s, m) + init(now * 2 + 1, m + 1, e);
}

ll sum(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return 0;
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  return sum(now * 2, s, m, l, r) + sum(now * 2 + 1, m + 1, e, l, r);
}

ll update(int now, int s, int e, int idx, ll val) {
  if (idx < s || idx > e) return tree[now];
  if (s == e) return tree[now] = val;
  int m = (s + e) >> 1;
  return tree[now] = update(now * 2, s, m, idx, val) + update(now * 2 + 1, m + 1, e, idx, val);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  
  init(1, 1, N);

  while (M--) {
    int a, b, c; cin >> a >> b >> c;
    if (a) update(1, 1, N, b, c);
    else cout << sum(1, 1, N, min(b, c), max(b, c)) << "\n";
  }

}