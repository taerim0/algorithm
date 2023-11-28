#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8], now[8];
bool isused[8];

void make(int size, int idx)
{
    if (size == M)
    {
        for (int i = 0; i < M; i++)
            cout << now[i] << " ";
        cout << "\n";

        return;
    }

    bool isUsed[10001] = { 0 };

    for (int i = idx; i < N; i++)
    {
        if (isUsed[arr[i]] || isused[i])
            continue;

        isUsed[arr[i]] = true;
        isused[i] = true;
        now[size] = arr[i];
        make(size + 1, i);
        isused[i] = false;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    make(0, 0);
}