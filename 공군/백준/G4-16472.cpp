#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int s, e, apbs, ans;
int apb_check[26];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  string str; cin >> str;

  for (auto c : str) {
    if (apbs < N) {
      if (!apb_check[c - 'a']++) {
        apbs++;
      }
    }
    else {
      if (!apb_check[c - 'a']++) {
        while (1) {
          if (!--apb_check[str[s++] - 'a'])
            break;
        }
      }
    }
    e++;
    ans = max(ans, e - s);
  }

  cout << ans;
}