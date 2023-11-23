#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	while (N--)
	{
		vector<char> v;
		string s;

		cin >> s;

		for (int i = 0; i < s.size(); i++)
		{
			if (!v.size())
			{
				v.push_back(s[i]);
			}
			else
			{
				if (v.back() == s[i])
					v.pop_back();
				else
					v.push_back(s[i]);
			}
		}

		if (!v.size())
			cnt++;
	}

	cout << cnt;
}