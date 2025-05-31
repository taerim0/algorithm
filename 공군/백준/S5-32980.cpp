#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

ll N, ans;
map<char, ll> costs;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  vector<string> trash(N);
  vector<char> types(N);

  for (int i = 0; i < N; i++) {
    cin >> trash[i];
  }

  for (int i = 0; i < N; i++) {
    char target = '-';
    for (auto a : trash[i]) {
      if (target == '-') {
        target = a;
        types[i] = a;
      }
      if (a != target) {
        types[i] = 'O';
      }
    }
  }

  ll val; cin >> val;
  costs['P'] = val; cin >> val;
  costs['C'] = val; cin >> val;
  costs['V'] = val; cin >> val;
  costs['S'] = val; cin >> val;
  costs['G'] = val; cin >> val;
  costs['F'] = val; cin >> val;
  costs['O'] = val;

  for (int i = 0; i < N; i++) {
    ans += trash[i].length() * min(costs[types[i]], costs['O']);
  }

  cout << ans;
}