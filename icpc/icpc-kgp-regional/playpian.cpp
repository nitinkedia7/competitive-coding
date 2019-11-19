#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    string s;
    for (; t > 0; t--) {
        cin >> s;
        int l = s.length();
        if (l % 2 == 0) {
            for (int i = 0; i < l; i += 2) {
                if (s[i] == 'A' && s[i+1] == 'A') {
                    cout << "no" << endl;
                    break;
                }
                else if (s[i] == 'B' && s[i+1] == 'B') {
                    cout << "no" << endl;
                    break;
                }
                if (i == l-2) cout << "yes" << endl;
            }
        }
        else cout << "no" << endl;
    }
}