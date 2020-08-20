#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int Y_MAX = 1e5;

ll nc2(ll x) {
    return (x * (x - 1)) / 2;
}

ll find_max_y(ll n) {
    ll l = 2, r = Y_MAX, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nc2(mid) <= n) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    } 
    return l - 1;
}

void sherlock(int t) {
    ll n;
    cin >> n; 
    ll n_copy = n;
    vector<int> y;
    while (n_copy > 0) {
        ll y1 = find_max_y(n_copy);
        y.push_back(y1);
        n_copy -= nc2(y1);
        // cout << y1 << " " << nc2(y1) << endl;
    }   
    ll suffix = 0;
    for (int i = (int) y.size() - 1; i >= 0; i--) {
        y[i] -= suffix;
        suffix += y[i];
    }
    for (int i = 0; i < (int) y.size(); i++) {
        cout << 1;
        for (int j = 0; j < y[i]; j++) {
            cout << 3;
        }
    }
    cout << 7 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
