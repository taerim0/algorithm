#include <iostream>
#include <queue>

using namespace std;

long N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	if (N == M)
		cout << 1;
	else
		cout << 0;
}