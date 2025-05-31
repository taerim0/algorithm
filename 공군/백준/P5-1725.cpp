#include <iostream>

using namespace std;

int N;
int arr[100001];
int tree[400001];

int init(int now, int s, int e) {
  if (s == e) return tree[now] = s;
  int m = (s + e) >> 1;
  int ls = init(now * 2, s, m);
  int rs = init(now * 2 + 1, m + 1, e);
  if (arr[ls] < arr[rs]) return tree[now] = ls;
  return tree[now] = rs;
}

int query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return -1;
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  int ls = query(now * 2, s, m, l, r);
  int rs = query(now * 2 + 1, m + 1, e, l, r);
  if (ls == -1) return rs;
  if (rs == -1) return ls;
  if (arr[ls] < arr[rs]) return ls;
  return rs;
}

int getMax(int l, int r)
{ 
  int m = query(1, 1, N, l, r);
  int now = arr[m] * (r - l + 1);
  if (l <= m - 1) now = max(now, getMax(l, m - 1));
  if (m + 1 <= r) now = max(now, getMax(m + 1, r));
  return now;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  init(1, 1, N);
  cout << getMax(1, N);
}