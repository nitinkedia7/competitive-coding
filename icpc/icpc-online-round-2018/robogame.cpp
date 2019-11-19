#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    for (;t > 0; t--) {
        string s;
        cin >> s;
        int l = s.length();
        vector<int> v(l, 0);
        for (int i = 0; i < l; i++) {
            if (s[i] != '.') {
                int r = s[i]-'0';
                for (int j = i-r; j <= i+r; j++) {
                    if (j >= 0 && j < l) {
                        v[j]++;
                    } 
                }
            }
        }
        for (int i = 0; i < l; i++) {
            if (v[i] > 1) {
                cout << "unsafe" << endl;
                break;
            }
            if (i == l-1) {
                cout << "safe" << endl;
            }
        }
    }
}