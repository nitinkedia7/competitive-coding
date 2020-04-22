#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> pow10(n+1);
    ll p = 1;
    for (int i = 0; i <= n; i++) {
        pow10[i] = p;
        p *= 10;
        p %= MOD;
    }
    ll f, s;
    for (int i = 1; i < n; i++) {
        f = 0;
        s = 0;
        f = 2 * 10 * 9 * pow10[n-i-1];
        f %= MOD;
        if (n-i-2 >= 0) {
            s = (n-i-1) * 10 * 81;
            s %= MOD;
            s *= pow10[n-i-2];     
        }
        cout << (f+s) % MOD << " ";
    }
    cout << 10 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}