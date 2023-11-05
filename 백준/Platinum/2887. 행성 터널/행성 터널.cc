#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define ppp pair<point, point>
#define find_distance min(min(abs(p[i + 1].x - p[i].x), abs(p[i + 1].y - p[i].y)), abs(p[i + 1].z - p[i].z))

using namespace std;

struct point
{
	int idx;
	int x, y, z;

	point() {}
	point(int t, int a, int b, int c)
	{
		idx = t, x = a, y = b, z = c;
	}
};

int N;
int ans, cnt;
int parent[100001];
int dist[100001];
bool check[100001];

vector<point> p;
vector<pair<int, ppp>> edge;

bool compareE(pair<int, ppp> a, pair<int, ppp > b)
{
	return a.first < b.first;
}

bool compareX(point a, point b)
{
	return a.x < b.x;
}

bool compareY(point a, point b)
{
	return a.y < b.y;
}

bool compareZ(point a, point b)
{
	return a.z < b.z;
}

int find_parent(int cur)
{
	if (parent[cur] == cur)
		return cur;
	else
		return parent[cur] = find_parent(parent[cur]);
}

void unite(pair<int, ppp> pm)
{
	auto [w, pos] = pm;
	int n1 = find_parent(pos.first.idx);
	int n2 = find_parent(pos.second.idx);

	if (n1 != n2)
	{
		parent[n1] = n2;
		ans += w;
		cnt++;
 	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0, a, b, c; i < N; i++)
	{
		cin >> a >> b >> c;
		parent[i] = i;
		p.push_back(point(i, a, b, c));
	}

	sort(p.begin(), p.end(), compareX);

	for (int i = 0; i < p.size() - 1; i++)
		edge.push_back({ find_distance, { p[i], p[i + 1] } });

	sort(p.begin(), p.end(), compareY);

	for (int i = 0; i < p.size() - 1; i++)
		edge.push_back({ find_distance, { p[i], p[i + 1] } });

	sort(p.begin(), p.end(), compareZ);

	for (int i = 0; i < p.size() - 1; i++)
		edge.push_back({ find_distance, { p[i], p[i + 1] } });

	sort(edge.begin(), edge.end(), compareE);

	for (int i = 0; i < edge.size(); i++)
	{
		unite(edge[i]);

		if (cnt == N) break;
	}

	cout << ans;
}