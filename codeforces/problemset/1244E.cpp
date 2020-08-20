#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    vector<pair<ll,int>> v;
    v.push_back({a[0], 1});
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            v.back().second++;
        }
        else {
            v.push_back({a[i], 1});
        }
    }
    int l = 0, r = v.size() - 1;
    ll cl = v[l].second, cr = v[r].second;
    ll pl = v[l].first, pr = v[r].first;
    while (l < r) {
        // cout << pl << "," << cl << "    " << pr << "," << cr << endl; 
        if (cl <= cr) {
            ll cost = (v[l+1].first - v[l].first) * cl;
            if (cost <= k) {
                k -= cost;
                pl = v[l+1].first;
                cl += v[l+1].second;
                l++;
            }
            else {
                pl += k / cl;
                k -= cl * (k / cl);
                break;
            }
        }
        else {
            ll cost = (v[r].first - v[r-1].first) * cr;
            if (cost <= k) {
                k -= cost;
                pr = v[r-1].first;
                cr += v[r-1].second;
                r--;
            }
            else {
                pr -= k / cr;
                k -= cr * (k / cr);
                break;
            }
        }
    }
    // cout << k << endl;
    cout << pr - pl << endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
