#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void count(vector<ll> &v, int j, int &c0, int &c1) {
    c0 = 0;
    c1 = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] & (1LL << j)) c1++;
        else c0++;
    }
    return;
}

void sherlock(int t) {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> v(n), f(51);
    int c0, c1;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int j = 0; j < 51; j++) {
        count(v, j, c0, c1);
        f[j] = min(c0, c1) * (1LL << j);
    }
    for (int j = 1; j < 51; j++) f[j] += f[j-1];
    ll k = 0;
    for (int j = 50; j >= 0; j--) {
        count(v, j, c0, c1);
        ll sum1 = (c0 * (1LL << j)) + (j > 0 ? f[j-1] : 0);
        ll sum0 = (c1 * (1LL << j)) + (j > 0 ? f[j-1] : 0);
        if (sum1 <= m) {
            k = k | (1LL << j);
            m -= (c0 * (1LL << j));
        }
        else if (sum0 <= m) {
            m -= (c1 * (1LL << j));
        }
        else {
            cout << "Case #" << t << ": " << -1 << endl;
            return;
        }
    }
    cout << "Case #" << t << ": " << k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}