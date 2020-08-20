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
    vector<int> op(n), cl(n), bal(n);
    int o = 0, c = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            o++;
            b++;
        }
        else {
            c++;
            b--;
        }
        op[i] = o;
        cl[i] = c;
        bal[i] = b;
    } 
    if (op[n-1] != cl[n-1]) {
        cout << -1 << endl;
        return;
    }    
    int i = 0, ans = 0;
    while (i < n) {
        int j = i;
        while (j < n && op[j] != cl[j]) {
            j++;
        }
        // now op[j] == cl[j], need to find if it is balanced
        int b = 0, mib = 0;
        for (int k = i; k < min(n, j+1); k++) {
            if (s[k] == '(') b++;
            else b--;
            mib = min(mib, b);
        }
        if (mib != 0) {
            ans += (j - i + 1);
            // cout << i << " " << j << endl;
        }
        i = j+1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
