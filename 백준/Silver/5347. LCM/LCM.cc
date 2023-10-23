#include <iostream>
#include <numeric>

using namespace std;

long long N, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	while (N--)
	{
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}
}