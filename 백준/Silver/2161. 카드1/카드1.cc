#include <iostream>
#include <queue>

using namespace std;

int N;

queue<int> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
		if (q.empty()) break;
		q.push(q.front());
		q.pop();
	}
}