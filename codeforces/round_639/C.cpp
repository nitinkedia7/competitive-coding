#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

ll find_mod(ll x, ll n) {
    if (n == 1) return 0;
    ll p = n;
    while (x < 0) {
        x += p;
        p *= n;
    }
    // cout << x << endl;
    return x % n;
}

void print(vector<ll> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = find_mod(a[i], n);
    }
    // print(a);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = (i + a[i]) % n;
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        if (v[i] != i) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
