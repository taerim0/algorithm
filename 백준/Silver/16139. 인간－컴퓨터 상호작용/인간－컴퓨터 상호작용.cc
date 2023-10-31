#include <iostream>
#include <queue>

using namespace std;

string S;
int q;
char a;
int l, r;

int apbsum[26][200000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> S >> q;

	for (int i = 1; i <= S.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			apbsum[j][i] = apbsum[j][i - 1];

			if (S[i - 1] - 'a' == j)
				apbsum[j][i]++;
		}
	}

	/*for (int i = 0; i <= S.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			cout << apbsum[j][i] << " ";
		}
		cout << "\n";
	}*/

	while (q--)
	{
		cin >> a >> l >> r;

		cout << apbsum[a - 'a'][r + 1] - apbsum[a - 'a'][l] << "\n";
	}
}
	