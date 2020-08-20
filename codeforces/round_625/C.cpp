#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    int m = n;
    string s;
    cin >> s;
    for (int j = 25; j >= 0; j--) {
        bool c = true;
        while (c) {
            c = false;
            for (int i = n-1; i >= 0; i--) {
                if (s[i] != ('a' + j)) continue;
                bool r = false;
                if (i + 1 < n && s[i] == s[i+1] + 1) r = true;
                if (i - 1 >= 0 && s[i] == s[i-1] + 1) r = true;
                if (r) {
                    s.erase(i, 1);
                    n--;
                    c = true;
                    break;
                }
            }
        }
    }
    // cout << s << endl;
    cout << m - n << endl;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
