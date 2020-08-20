#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    int ls = -1;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = ls;
        if (s[i] == '1') ls = i;
    }
    int b = 20;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll x = 0;
        ll p = 1;
        for (int j = i; j >= 0; j--) {
            if (i - j + 1 > b) break;
            x += p * (s[j] - '0');
            p *= 2;
            if (s[j] == '0') continue;
            int sl = i - j + 1, bl = i - v[j];
            if (x >= sl && x <= bl) {
                // cout << j << "," << i << endl;
                ans++;
            }
        }        
    }
    cout << ans << endl;    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
