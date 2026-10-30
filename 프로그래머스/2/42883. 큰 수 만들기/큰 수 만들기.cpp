#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> w(number.length() - k, '0' - 1);
    int wp = 0;
    for (int i = 0; i < number.length(); i++) {
        for (int j = wp; j >= 0; j--) {
            // cout << "test : ij (" << i << ", " << j << "), " << (number.length() - 1 - i) << ", " << w.size() - j - 1 << ", wp = " << wp << "\n";
            if (number[i] > w[j]) {
                if (number.length() - 1 - i > w.size() - j - 1) {
                    if (j != 0) {
                        w[j] = '0' - 1;
                        continue;
                    }
                    w[j] = number[i];
                    if (j == wp && wp + 1 != w.size()) 
                        wp++;
                }
                else if (number.length() - 1 - i == w.size() - j - 1) {
                    w[j] = number[i];
                    if (j == wp && wp + 1 != w.size()) 
                        wp++;
                }
                else {
                    w[j + 1] = number[i];
                    if (j + 1 == wp && wp + 1 != w.size()) 
                        wp++;
                }
                break;
            }
            if (j == wp) break;
            w[j + 1] = number[i];
            if (j + 1 == wp && wp + 1 != w.size()) 
                wp++;
            break;
        }
    }
    for (char c : w)
        answer += c;
    
    return answer;
}