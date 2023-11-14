#include <iostream>
#include <vector>

#define ll long long
#define vl vector<ll>
#define vll vector<vector<ll>>

using namespace std;

ll n;

vll matrix;

vll power(vll& a, ll n)
{
	if (n == 1)
		return a;

	vll temp = power(a, n / 2);

	vll rst1;

	vll rst2;

	for (int i = 0; i < 2; i++)
	{
		vl tmp;

		for (int j = 0; j < 2; j++)
		{
			ll sum = 0;

			for (int k = 0; k < 2; k++)
			{
				sum = (sum + (temp[i][k] * temp[k][j]) % 1000000007) % 1000000007;
			}

			tmp.push_back(sum);
		}

		rst1.push_back(tmp);
	}

	if (n % 2)
	{
		for (int i = 0; i < 2; i++)
		{
			vl tmp;

			for (int j = 0; j < 2; j++)
			{
				ll sum = 0;

				for (int k = 0; k < 2; k++)
				{
					sum = (sum + (rst1[i][k] * a[k][j]) % 1000000007) % 1000000007;
				}

				tmp.push_back(sum);
			}

			rst2.push_back(tmp);
		}

		return rst2;
	}

	return rst1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vl temp;

	temp.push_back(1);
	temp.push_back(1);
	matrix.push_back(temp);
	temp.pop_back();
	temp.push_back(0);
	matrix.push_back(temp);

	vll ans = power(matrix, n);

	cout << ans[0][1] % 1000000007;
}