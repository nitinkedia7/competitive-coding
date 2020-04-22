#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const ll MOD = 1000000007;

void print2d(vector<vector<ll>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void sherlock(int t) {
    int d;
    ll mod;
    cin >> d >> mod;
    int n;
    for (n = 31; n >= 0; n--) {
        if (d & (1 << n)) break;
    }
    n++;
    int m = n;
    vector<ll> pow2;
    ll x = 1;
    for (int i = 0; i <= m; i++) {
        pow2.push_back(x);
        x = x * 2;
        x %= mod;
    }
    // cout << n << " " << m << endl << endl;
    vector<vector<ll>> v(n+1, vector<ll> (m+1, 0));
    v[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        ll sum = v[i-1][0];
        for (int j = 1; j <= m; j++) {
            ll mul = 0;
            if (j < m) {
                mul = pow2[j-1];
            } 
            else if (j == m) {
                mul = d - (1 << (j-1)) + 1;
            }
            mul %= mod;
            // cout << i << " " << j << " " << sum << " " << mul << endl;
            v[i][j] = (sum * mul) % mod;
            sum = (sum + v[i-1][j]) % mod;
        }
    }
    // cout << endl;
    // print2d(v);
    // cout << endl;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ans = (ans + v[i][j]) % mod;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}