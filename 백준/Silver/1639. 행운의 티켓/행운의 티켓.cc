#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pll pair<ll, ll>

using namespace std;

string str;

int maxlen;

int main()
{
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		for (int j = i + 1; j < str.length(); j += 2) {
			if (j - i + 1 < maxlen)
				continue;

			int leftsum = 0, rightsum = 0;

			for (int k = 0; k < (j - i + 1) / 2; k++) {
				leftsum += str[i + k] - '0';
				rightsum += str[j - k] - '0';
			}

			if (leftsum == rightsum)
				maxlen = j - i + 1;
		}
	}

	cout << maxlen;
}