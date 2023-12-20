#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<int, int>

using namespace std;

int N;
vector<pii> x;
vector<int> ans, idx, pos;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for (int i = 0, a, b; i < N; i++)
    {
        cin >> a >> b;
        x.push_back({ a, b });
    }

    sort(x.begin(), x.end());

    ans.push_back(x.front().second);
    idx.push_back(0);

    for (int i = 1; i < N; i++)
    {
        int next = x[i].second;

        if (ans.back() < next)
        {
            ans.push_back(next);
            idx.push_back(ans.size() - 1);
        }
        else
        {
            int left = 0, right = ans.size() - 1;

            while (left < right)
            {
                int mid = (left + right) / 2;

                if (ans[mid] < next)
                    left = mid + 1;
                else
                    right = mid;
            }

            ans[left] = next;
            idx.push_back(left);
        }
    }

    cout << x.size() - ans.size() << "\n";

    int now = ans.size() - 1;

    for (int i = idx.size() - 1; i >= 0; i--)
    {
        if (now == idx[i])
            now--;
        else
            pos.push_back(x[i].first);
    }

    sort(pos.begin(), pos.end());

    for (int i : pos)
        cout << i << "\n";
}
