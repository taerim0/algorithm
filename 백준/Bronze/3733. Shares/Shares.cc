#include <iostream>

using namespace std;

int N, S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> N >> S)
		cout << S / (N + 1) << "\n";
}