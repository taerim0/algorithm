#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int tree[400001];

int init(int now, int s, int e) {
  if (s == e) return tree[now] = arr[s];
  int m = (s + e) >> 1;
  return tree[now] = min(init(now * 2, s, m), init(now * 2 + 1, m + 1, e));
}

int query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return 1000000001;
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  return min(query(now * 2, s, m, l, r), query(now * 2 + 1, m + 1, e, l, r));
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
      cout << query(1, 1, N, a, b) << "\n";
    }
  }

}