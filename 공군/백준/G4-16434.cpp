// 이분탐색으로 풀었지만 이분탐색 안 써도 다양하게 풀이 가능할 듯

#include <iostream>
#include <vector>

#define ll long long
#define INF 1e18

using namespace std;

typedef struct {
  int t, a, h;
}room;

int N;
ll ATK;
vector<room> rooms;

bool simul(ll HP) {
  ll atk = ATK, hp = HP;

  for (int i = 0; i < N; i++) {
    if (rooms[i].t) {
      atk += rooms[i].a;
      hp += rooms[i].h;

      if (hp > HP) hp = HP;
    }
    else {
      if (rooms[i].h % atk) hp -= rooms[i].a * ((ll)rooms[i].h / atk);
      else hp -= rooms[i].a * ((ll)rooms[i].h / atk - 1); 
      if (hp <= 0)
        return false;
    }
  }

  return true;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> N >> ATK;

  for (int i = 0; i < N; i++) {
    int t, a, h; cin >> t >> a >> h;
    rooms.push_back({ t - 1, a, h });
  }

  ll s = 0, e = INF;
  ll m;

  while (s <= e) {
    m = (s + e) / 2;
    if (simul(m)) e = m - 1;
    else s = m + 1;
  }

  cout << e + 1;
}