#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N, T;
int shft;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> T;

  vector<int> apart(N * 2);
  for (int i = 0; i < N * 2; i++) {
    cin >> apart[i];
  }

  while (T--) {
    int a; cin >> a;
    cout << apart[(a + shft - 1) % (N * 2)] << " ";
    shft = (a + shft - 1) % (N * 2);
  }
}