#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8], now[8];
bool isUsed[10001];

void make(int size)
{
    if (size == M)
    {
        for (int i = 0; i < M; i++)
            cout << now[i] << " ";
        cout << "\n";

        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isUsed[arr[i]])
            continue;

        now[size] = arr[i];
        isUsed[arr[i]] = true;
        make(size + 1);
        isUsed[arr[i]] = false;
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

    make(0);
}