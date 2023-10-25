#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;

	while (N--)
	{
		string str;

		cin >> str;

		if (str.size() >= 6 && str.size() <= 9)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}