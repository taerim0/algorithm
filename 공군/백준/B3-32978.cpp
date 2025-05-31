#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N;
string ans;
map<string, bool> check;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    check[s] = true;
  }

  for (int i = 0; i < N - 1; i++) {
    string s; cin >> s;
    check[s] = false;
  }

  for (auto iter = check.begin(); iter != check.end(); iter++) {
    if (iter->second) {
      cout << iter->first;
      return 0;
    }
  }
}