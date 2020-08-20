#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 998244353;
const int MAX_DIGITS = 10;

void print(vector<ll> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void digits(int x, vector<int> &v) {
    int p = 10;
    while (x > 0) {
        v.push_back(x % p);
        x /= p;
    }
    return;
}

void sherlock(int t) {
    vector<ll> pow10(21, 1);
    for (int i = 1; i < 21; i++) {
        pow10[i] = pow10[i-1] * 10;
        pow10[i] %= MOD;
    }
    // print(pow10);
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    vector<int> count(MAX_DIGITS + 1, 0);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        digits(x, d[i]);
        count[d[i].size()]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int) d[i].size(); j++) {
            if (d[i][j] == 0) continue;
            int x = j + 1;
            for (int y = 1; y <= MAX_DIGITS; y++) {
                if (count[y] == 0) continue;
                ll c;
                if (y >= x) {
                    c = pow10[2 * x - 1];
                }
                else {
                    c = pow10[x + y - 1];
                }
                c *= d[i][j];
                c %= MOD;
                c *= count[y];
                c %= MOD;
                ans += c;
                ans %= MOD;
                if (y >= x-1) {
                    c = pow10[2 * x - 2];
                }
                else {
                    c = pow10[x + y - 1];
                }
                c *= d[i][j];
                c %= MOD;
                c *= count[y];
                c %= MOD;
                ans += c;
                ans %= MOD;
            }
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
