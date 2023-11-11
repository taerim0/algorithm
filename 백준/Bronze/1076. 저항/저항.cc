#include <iostream>
#include <map>

#define ll long long

using namespace std;

map<string, pair<ll, ll>> m;

string a, b, c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	m["black"] = { 0, 1e0 };
	m["brown"] = { 1, 1e1 };
	m["red"] = { 2, 1e2 };
	m["orange"] = { 3, 1e3 };
	m["yellow"] = { 4, 1e4 };
	m["green"] = { 5, 1e5 };
	m["blue"] = { 6, 1e6 };
	m["violet"] = { 7, 1e7 };
	m["grey"] = { 8, 1e8 };
	m["white"] = { 9, 1e9 };

	cin >> a >> b >> c;

	cout << m[a].first * m[c].second * 10 + m[b].first * m[c].second;
}