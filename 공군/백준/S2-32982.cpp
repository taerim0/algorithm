#include <iostream>
#include <queue>
#include <map>
#include <cstring>
#include <vector>

#define pii pair<int, int>
#define ll long long

using namespace std;

int N, K;
int drug_time[6];

bool ans = true;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;

  for (int i = 0; i < 6; i++) {
    cin >> drug_time[i];
  }

  int now = drug_time[1], n = N;

  while (n--) {
    if (n != N - 1) {
      if (now + K < drug_time[0] + 1440 * (N - n - 1)) {
        ans = false;
        break;
      }
      now = min(now + K, drug_time[1] + 1440 * (N - n - 1));
    }

    if (now + K < drug_time[2] + 1440 * (N - n - 1)) {
      ans = false;
      break;
    }
    now = min(now + K, drug_time[3] + 1440 * (N - n - 1));

    if (now + K < drug_time[4] + 1440 * (N - n - 1)) {
      ans = false;
      break;
    }
    now = min(now + K, drug_time[5] + 1440 * (N - n - 1)); 
  }

  cout << (ans ? "YES" : "NO");
}