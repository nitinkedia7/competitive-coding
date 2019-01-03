#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    char prev = s[0], preprev = 'a';
    bool isMaximal = true;
    if (s.length() == 1 && s[0] == '0') isMaximal = false;
    for (int i = 1; i < s.length(); i++) {
        if (prev == '1' && s[i] == '1') {
            isMaximal = false;
            break;
        }
        if (s[i] == '0' && prev == '0' && preprev == '0') {
            isMaximal = false;
            break;
        }
        if (i == s.length()-1 && prev == '0' && s[i] == '0') {
            isMaximal = false;
            break;
        }
        if (i == 1 && prev == '0' && s[i] == '0') {
            isMaximal = false;
            break;
        } 
        preprev = prev;
        prev = s[i];
    }
    if (isMaximal) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0; 
}