// 이분탐색 + bfs. 이분탐색 쓸 생각을 못했다..

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 2e9
#define pii pair<int, int>

int n;
int ans = INF;
int arr[100][100];
bool num_check[201];
bool check[100][100];
vector<int> nums;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool bfs(int dif) {
  for (auto target : nums) {
    if (target > arr[0][0] || arr[0][0] > target + dif)
      continue;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (target <= arr[i][j] && arr[i][j] <= target + dif)
          check[i][j] = false;
        else
          check[i][j] = true;
      }
    }

    queue<pii> q;
    q.push({0, 0});
    check[0][0] = true;

    while (q.size()) {
      auto [y, x] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int dn = y + dy[i];
        int dm = x + dx[i];

        if (dn < 0 || dn >= n || dm < 0 || dm >= n)
          continue;

        if (check[dn][dm])
          continue;

        if (dn == n - 1 && dm == n - 1)
          return true;

        check[dn][dm] = true;
        q.push({dn, dm});
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];

      if (!num_check[arr[i][j]]) {
        num_check[arr[i][j]] = true;
        nums.push_back(arr[i][j]);
      }
    }
  }

  sort(nums.begin(), nums.end());

  int start = 0, end = nums.back() - nums.front();
  int mid;

  while (start <= end) {
    mid = (start + end) / 2;
    if (bfs(mid)) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  cout << end + 1;

  return 0;
}