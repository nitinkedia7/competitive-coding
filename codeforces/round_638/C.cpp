#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(all(s));
    int x = 0;
    while (x < n && s[x] == s[0]) {
        x++;
    }
    if (x < k) {
        cout << s[k-1] << endl;
        return;
    }
    else {
        bool same = true;
        for (int i = k; i < n; i++) {
            same = same && (s[i] == s[k]);
        }
        if (!same) {
            cout << s[0] + s.substr(k, n-k) << endl; 
        }
        else {
            string ans;
            int l = (n - k + k - 1) / k;
            for (int i = 0; i < l; i++) {
                ans += s[k];
            }
            cout << s[0] + ans << endl;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
