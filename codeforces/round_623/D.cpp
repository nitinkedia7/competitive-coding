#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int tc) {
    int n;
    cin >> n;
    vector<pair<ll,int>> v(n);
    vector<ll> t(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }    
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(all(v));
    int i = 0;
    ll x, tsum = 0, ans = 0;
    multiset<ll, greater<ll>> ms;
    while (i < n || !ms.empty()) {
        if (ms.empty()) {
            x = v[i].first;
        }
        while (i < n && v[i].first == x) {
            ms.insert(t[v[i].second]);
            tsum += t[v[i].second];
            i++;
        } 
        // Now eject minimum t and move forward
        tsum -= *ms.begin();
        ans += tsum;
        ms.erase(ms.begin());
        // cout << x << endl;
        x++;
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
