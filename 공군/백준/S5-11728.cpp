// 정렬

#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int, int>

using namespace std;

int N, M;
vector<int> hey;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M; N += M;

  for (int i = 0; i < N; i++) {
    int a; cin >> a;
    hey.push_back(a);
  }

  sort(hey.begin(), hey.end());

  for (auto a : hey) {
    cout << a << " ";
  }
}