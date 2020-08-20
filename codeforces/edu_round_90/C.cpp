#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    ll res = 0, i = 0, p = 0;
    for (int cur = 0; cur <= n; cur++) {
        while (i < n && cur + p >= 0) {
            if (s[i] == '+') p++;
            else p--;
            i++;
        }
        if (cur + p >= 0) {
            res += n;
            break;
        }
        else {
            res += i;
        }
        // cout << cur << " " << res << endl;
    }    
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
