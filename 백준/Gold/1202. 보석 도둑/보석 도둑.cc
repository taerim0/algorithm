#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long
#define pii pair<int, int>

using namespace std;

int N, K;
int t;

ll ans;
pii jewel[300000];
int bag[300000];

priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> jewel[i].first >> jewel[i].second;
	}

	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}

	sort(jewel, jewel + N);
	sort(bag, bag + K);

	for (int i = 0; i < K; i++)
	{
		while (t < N && bag[i] >= jewel[t].first)
		{
			pq.push(jewel[t].second);
			t++;
		}

		if (pq.size())
		{
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;
}