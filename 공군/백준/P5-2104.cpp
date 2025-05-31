#include <iostream>

#define pii pair<int, int>
#define ll long long

using namespace std;

typedef struct {
  ll sum, minval, idx;
}node;

int N;
int arr[100001];
node tree[400001];

node init(int now, int s, int e) {
  if (s == e) return tree[now] = { arr[s], arr[s], s };
  int m = (s + e) >> 1;
  node ls = init(now * 2, s, m);
  node rs = init(now * 2 + 1, m + 1, e);
  return tree[now] = { ls.sum + rs.sum, min(ls.minval, rs.minval), (ls.minval < rs.minval ? ls.idx : rs.idx) };
}

node query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return { 0, (int)1e9, -1 };
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  node ls = query(now * 2, s, m, l, r);
  node rs = query(now * 2 + 1, m + 1, e, l, r);
  return { ls.sum + rs.sum, min(ls.minval, rs.minval), (ls.minval < rs.minval ? ls.idx : rs.idx) };
}

ll solve(int s, int e) {
  node tempNode = query(1, 1, N, s, e);
  ll area = tempNode.sum * tempNode.minval;
  if (s == e) return area;
  if (s < tempNode.idx) {
    ll tempArea = solve(s, tempNode.idx - 1);
    if (area < tempArea) area = tempArea;
  }
  if (tempNode.idx < e) {
    ll tempArea = solve(tempNode.idx + 1, e);
    if (area < tempArea) area = tempArea;
  }
  return area;
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
  cout << solve(1, N);
}