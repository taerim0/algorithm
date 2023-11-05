#include <iostream>

using namespace std;

int N, A, B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> A >> B;

	int a = max(N, B);

	if (A < a)
		cout << "Bus";
	else if (A == a)
		cout << "Anything";
	else
		cout << "Subway";
}