#include <iostream>

#define pii pair<int, int>
#define ll long long

int N, K;

using namespace std;

int arr[100001];
int tree[400001];

int init(int now, int s, int e) {
  if (s == e) return tree[now] = arr[s];
  int m = (s + e) >> 1;
  return tree[now] = init(now * 2, s, m) * init(now * 2 + 1, m + 1, e);
}

int query(int now, int s, int e, int l, int r) {
  if (l > e || r < s) return 1;
  if (l <= s && e <= r) return tree[now];
  int m = (s + e) >> 1;
  return query(now * 2, s, m, l, r) * query(now * 2 + 1, m + 1, e, l, r);
}

int update(int now, int s, int e, int i, int v) {
  if (i < s || i > e) return tree[now];
  if (s == e) return tree[now] = v;
  int m = (s + e) >> 1;
  return tree[now] = update(now * 2, s, m, i, v) * update(now * 2 + 1, m + 1, e, i, v);
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  while (cin >> N >> K) {
    for (int i = 1; i <= N + K; i++) {
      if (i <= N) { 
        cin >> arr[i];
        if (arr[i] > 0) arr[i] = 1;
        if (arr[i] < 0) arr[i] = -1;
      }
      else {
        if (i == N + 1) init(1, 1, N);
        char a; int b, c; cin >> a >> b >> c;
        if (a - 'C') {
          int result = query(1, 1, N, b, c);
          if (result > 0) cout << "+";
          if (result < 0) cout << "-";
          if (!result) cout << "0";
        }
        else {
          if (c > 0) c = 1;
          if (c < 0) c = -1;
          update(1, 1, N, b, c);
        }
      }
    }
    cout << "\n";
  }
}