#include <iostream>

#define pii pair<int, int>

using namespace std;

int N, M;
int arr[500001];
int tree[2000001];
pii data_tree[2000001];

int init(int now, int s, int e) {
  if (s == e) {
    data_tree[now] = { -1, -1 };
    return tree[now] = arr[s];
  }
  int m = (s + e) >> 1;
  data_tree[now] = { init(now * 2, s, m), init(now * 2 + 1, m + 1, e) };
  return tree[now] = data_tree[now].first + data_tree[now].second;
}

int query(int now, int s, int e, int target, int base) {
  if (s == e)
    return s;
  int m = (s + e) >> 1;   
  if (data_tree[now].first + base < target) {
    return query(now * 2 + 1, m + 1, e, target, base + data_tree[now].first);
  }
  else {
    return query(now * 2, s, m, target, base);
  }
}

int update(int now, int s, int e, int idx, int val) {
  if (idx < s || idx > e) return tree[now];
  if (s == e) return tree[now] += val;
  int m = (s + e) >> 1;
  data_tree[now] = { update(now * 2, s, m, idx, val), update(now * 2 + 1, m + 1, e, idx, val) };
  return tree[now] = data_tree[now].first + data_tree[now].second;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  init(1, 1, N);

  cin >> M;

  while (M--) {
    int a; cin >> a;
    if (a - 1) {
      int b; cin >> b;
      cout << query(1, 1, N, b, 0) << "\n";
    }
    else {
      int b, c; cin >> b >> c;
      update(1, 1, N, b, c);
    }
  }
}