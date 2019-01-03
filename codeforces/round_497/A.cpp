#include <bits/stdc++.h>
typedef long long ll;
using namespace std;



int main() {
    string s;
    cin >> s;
    int l = s.length();
    for (int i = 0; i < l; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            continue;
        }
        else if (s[i] == 'n') {
            continue;
        }
        else {
            if (i == l-1) {
                cout << "NO" << endl;
                return 0;
            }
            else if (!(s[i+1] == 'a' || s[i+1] == 'e' || s[i+1] == 'i' || s[i+1] == 'o' || s[i+1] == 'u')) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}