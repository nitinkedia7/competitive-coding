#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const ll MOD = 1000000007;

ll findCount(ll n, ll m, ll k) {
    ll ans = 0;
    for (ll l = 1; l <= n; l++) {
        if (k % l != 0) continue;
        ll b = k / l;
        if (b > m) continue;
        ans += (n - l + 1) * (m - b + 1); 
    }
    return ans;
}

void subarray(vector<int> &a, map<int,int> &ans) {
    int i = 0, n = a.size();
    while (i < n) {
        if (a[i] == 0) {
            i++;
            continue;
        }
        int j = i+1;
        while (j < n && a[j] == 1) {
            j++;
        }
        ans[j-i]++;
        i = j+1;
    }
}

void sherlock(int t) {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    map<int,int> a1, b1;
    subarray(a, a1);
    subarray(b, b1);
    ll ans = 0;
    for (auto &[l, c1] : a1) {
        for (auto &[b, c2] : b1) {
            ans += c1 * c2 * findCount(l, b, k);
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