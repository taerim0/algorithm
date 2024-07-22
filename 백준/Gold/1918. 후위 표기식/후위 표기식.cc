#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

string sick;

vector<char> Operand;

void pop_all()
{
    while (!Operand.empty()) {
        char c = Operand.back();
        Operand.pop_back();
        cout << c;
    }
}

void pop_group()
{
    while (!Operand.empty() && Operand.back() != '+' && Operand.back() != '-' && Operand.back() != '(') {
        char c = Operand.back();
        Operand.pop_back();
        cout << c;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> sick;

    for (int i = 0; i < sick.length(); i++) {
        if (sick[i] >= 'A' && sick[i] <= 'Z') {
            cout << sick[i];
            if (i == sick.length() - 1)
                pop_all();
        }
        
        if (sick[i] == '+' || sick[i] == '-') {
            while (!Operand.empty() && Operand.back() != '(') {
                char c = Operand.back();
                Operand.pop_back();
                cout << c;
            }
            Operand.push_back(sick[i]);
        }

        if (sick[i] == '*' || sick[i] == '/') {
            Operand.push_back(sick[i]);
            if (sick[i + 1] != '(') {
                i++;
                cout << sick[i];
                if (i == sick.length() - 1)
                    pop_all();
                else
                    pop_group();
            }
        }

        if (sick[i] == '(') {
            Operand.push_back(sick[i]);
        }

        if (sick[i] == ')') {
            while (Operand.back() != '(') {
                char c = Operand.back();
                Operand.pop_back();
                cout << c;
            }
            Operand.pop_back();

            if (i == sick.length() - 1)
                pop_all();
            else
                pop_group();
        }
    }
}