#include <iostream>
#include <algorithm>

#define ll long long

using namespace std;

int N, M, K;
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

  cin >> N >> M >> K;

  for (int i = 1; i <= N + M + K; i++) {
    if (i < N + 1) cin >> arr[i];
    else {
      if (i == N + 1) init(1, 1, N);
      ll a, b, c; cin >> a >> b >> c;
      if (a - 1) {
        cout << sum(1, 1, N, b, c) << "\n";
      }
      else {
        update(1, 1, N, b, c);
      }
    }
  }
  
}