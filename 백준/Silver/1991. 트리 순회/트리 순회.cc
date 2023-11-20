#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <map>

#define pcc pair<char, char>

using namespace std;

int N;
pcc tree[26];

void preorder(char now)
{
	if (now == '.')
		return;

	cout << now;
	preorder(tree[now - 'A'].first);
	preorder(tree[now - 'A'].second);
}

void inorder(char now)
{
	if (now == '.')
		return;

	inorder(tree[now - 'A'].first);
	cout << now;
	inorder(tree[now - 'A'].second);
}

void postorder(char now)
{
	if (now == '.')
		return;

	postorder(tree[now - 'A'].first);
	postorder(tree[now - 'A'].second);
	cout << now;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		char a, b, c;

		cin >> a >> b >> c;

		tree[a - 'A'] = { b, c };
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}