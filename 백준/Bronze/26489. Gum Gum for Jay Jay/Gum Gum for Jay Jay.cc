#include <iostream>
#include <string>

using namespace std;

int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;

	while (getline(cin, str))
		cnt++;

	cout << cnt;
}