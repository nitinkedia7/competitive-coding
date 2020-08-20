#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    // l = 1
    vector<int> v(26);
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++;
    }
    ll ans = *max_element(all(v));
    fill(all(v), 0);
    vector<vector<ll>> gv(26, vector<ll> (26));
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            gv[s[i] - 'a'][j] += v[j];
        }
        v[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            ans = max(ans, gv[i][j]);
        }
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
