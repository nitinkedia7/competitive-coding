#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int min_cuts(vector<ll> &a, ll x, ll c, ll d) {
    // target size = x / c;
    ll maxd = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        maxd += (a[i] * c) / x;
    }
    if (maxd < d) return INT_MAX;
    vector<pair<ll,ll>> v;
    for (int i = 0; i < (int) a.size(); i++) {
        if ((a[i] * c) % x == 0) {
            ll cuts = (a[i] * c) / x;
            v.push_back({cuts - 1, cuts});
        } 
    }
    sort(all(v));
    ll done = 0, mc = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        if (done + v[i].second <= d) {
            mc += v[i].first;
            done += v[i].second;
        }
        else break;
    }
    mc += (d - done);
    return mc;
}

void sherlock(int t) {
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Iterate over all target sizes
    int mc = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int c = 1; c <= d; c++) {
            mc = min(mc, min_cuts(a, a[i], c, d));
        }
    }    
    cout << "Case #" << t << ": " << mc << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
