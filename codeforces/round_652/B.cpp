#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int z = 0, o = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') break;
        z++;
    }    
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') break;
        o++;
    }
    if (z + o == n) {
        cout << s << endl;
    }
    else {
        string ans;
        for (int i = 0; i < z + 1; i++) {
            ans += '0';
        }
        for (int i = 0; i < o; i++) {
            ans += '1';
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
