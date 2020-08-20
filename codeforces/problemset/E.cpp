#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 998244353;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    map<int,int> mp;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]] = -1;
    }    
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) != mp.end()) {
            mp[a[i]] = i;
        }
    }
    vector<int> v;
    for (auto e : mp) {
        v.push_back(e.second);
    }
    print(v);
    ll ans = 1;
    for (int i = 1; i < m; i++) {
        if (v[i] <= v[i-1]) {
            cout << 0 << endl;
            return;
        }
        ans *= (v[i] - v[i-1]) % MOD;
        ans %= MOD;
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
