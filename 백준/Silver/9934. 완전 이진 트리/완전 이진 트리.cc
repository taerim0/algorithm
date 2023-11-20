#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <map>

#define pcc pair<char, char>

using namespace std;

int K;
int arr[1024];
vector<int> level[10];

void divide(int l, int r, int h)
{
	level[h].push_back(arr[(r + l) / 2]);

	if (h + 1 == K)
		return;
	divide(l, (r + l) / 2 - 1, h + 1);
	divide((r + l) / 2 + 1, r, h + 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K;

	int len = pow(2, K) - 1;

	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}

	divide(0, len, 0);

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < level[i].size(); j++)
		{
			cout << level[i][j] << " ";
		}
		cout << "\n";
	}
}