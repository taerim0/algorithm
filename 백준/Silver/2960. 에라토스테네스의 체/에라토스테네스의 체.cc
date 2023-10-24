#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int N, K;

bool notPrime[1001];

void solve(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!notPrime[i])
		{
			for (int j = i; j <= n; j += i)
			{
				if (!notPrime[j])
					v.push_back(j);
				notPrime[j] = true;
				if (v.size() == K)
					break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	solve(N);

	cout << v[K - 1];
}