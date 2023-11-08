#include <iostream>
#include <algorithm>

using namespace std;

int a, b;
string N1, N2;
string ant;
bool order[100000];
int T, t;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> N1 >> N2;

	reverse(N1.begin(), N1.end());
	
	ant = N1 + N2;

	cin >> t;

	T = t;

	for (int i = 0; i < a; i++)
		order[i] = true;

	while (t--)
	{
		int num = T - t;

		for (int i = ant.length() - 1; i >= 0; i--)
		{
			if (order[i])
			{
				if (i != ant.length() - 1 && !order[i + 1])
				{
					order[i] = false;
					order[i + 1] = true;
					char temp = ant[i + 1];
					ant[i + 1] = ant[i];
					ant[i] = temp;
				}

				num--;
			}

			if (!num)
				break;
		}
	}

	cout << ant;
}