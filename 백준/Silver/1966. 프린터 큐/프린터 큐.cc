#include <iostream>
#include <queue>

using namespace std;

int T;
int N, M;
int num;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N >> M;

		priority_queue<int> pq;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++)
		{
			cin >> num;

			q.push({ num, i });
			pq.push(num);
		}

		for (int t = 1; q.size();)
		{
			if (pq.top() == q.front().first)
			{
				if (q.front().second == M)
				{
					cout << t << "\n";
					break;
				}
				pq.pop();
				q.pop();
				t++;
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
	}
}