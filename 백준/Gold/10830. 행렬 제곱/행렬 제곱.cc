#include <iostream>
#include <vector>

#define ll long long
#define vl vector<ll>
#define vll vector<vector<ll>>

using namespace std;

ll N, B, num;

vll matrix;

vll power(vll& a, ll n)
{
	if (n == 1)
		return a;

	vll temp = power(a, n / 2);

	vll rst1;

	vll rst2;

	for (int i = 0; i < N; i++)
	{
		vl tmp;

		for (int j = 0; j < N; j++)
		{
			ll sum = 0;

			for (int k = 0; k < N; k++)
			{
				sum = (sum + (temp[i][k] * temp[k][j]) % 1000) % 1000;
			}

			tmp.push_back(sum);
		}

		rst1.push_back(tmp);
	}

	if (n % 2)
	{
		for (int i = 0; i < N; i++)
		{
			vl tmp;

			for (int j = 0; j < N; j++)
			{
				ll sum = 0;

				for (int k = 0; k < N; k++)
				{
					sum = (sum + (rst1[i][k] * a[k][j]) % 1000) % 1000;
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

	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		vl temp;

		for (int j = 0; j < N; j++)
		{
			cin >> num;

			temp.push_back(num);
		}

		matrix.push_back(temp);
	}

	vll ans = power(matrix, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ans[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
}