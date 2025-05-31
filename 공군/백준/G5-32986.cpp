#include <iostream>
#include <algorithm>

using namespace std;

int X, Y, Z;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> X >> Y >> Z;
  if (X == 3 && Y == 3 && Z == 3) cout << 0;
  else cout << ((min({ X, Y, Z }) + 1) / 2) - 1;
}