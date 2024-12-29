#include <iostream>

#define pii pair<int, int>

using namespace std;

int T, n;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T; while (T--) {
    cin >> n;

    int ans = 0;

    if (!(n % 3)) ans++;

    while (n > 0) {
      ans += ((int)(n / 2) + 1);
      n -= 3;
    }

    cout << ans << "\n";
  }
}