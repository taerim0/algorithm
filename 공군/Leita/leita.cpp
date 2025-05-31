#include <iostream>

using namespace std;

int main()
{
    int a; while (cin >> a) {
        if (a >= 3 && a <= 10) {
            for (int i = 0; i < a; i++) {
                for (int j = 1; j < a - i; j++)
                    cout << " ";
                for (int j = 0; j < i * 2 + 1; j++)
                    cout << "*";
                cout << "\n";
            }
            for (int i = 1; i < a; i++)
                cout << " ";
            cout << "*\n";
        }
        else cout << "범위를 벗어났습니다.\n";
    }

    return 0;
}