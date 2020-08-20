#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int watson(int x, int n, vector<pair<int,int>> &e) {
    vector<int> mp(n);
    for (int i = 0; i < n; i++) {
        mp[i] = (x % 6) + 1;
        x /= 6;
    }
    int ans = 0;
    set<pair<int,int>> s;
    for (int i = 0; i < (int) e.size(); i++) {
        pair<int,int> p = {mp[e[i].first], mp[e[i].second]};
        if (p.first > p.second) {
            swap(p.first, p.second);
        }
        if (s.find(p) == s.end()) {
            ans++;
            s.insert(p);
        }
    }
    return ans;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        e[i] = {u - 1, v - 1};
    }    
    int p = pow(6, n);
    int ans = 0;
    for (int i = 0; i < p; i++) {
        ans = max(ans, watson(i, n, e));
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
