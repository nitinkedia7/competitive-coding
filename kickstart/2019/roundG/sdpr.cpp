#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void good(int n, int h, vector<int> &v1) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m = 1 << n;
    ll x;
    for (int s = 0; s < m; s++) {
        x = 0;
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                x += v[i];
            }
        }
        if (x >= h) v1[s] = 1;
    }
    return;
}

ll dp(int i, int j, vector<vector<ll>> &opt) {
    if (opt[i][j] != -1) return opt[i][j];
    // i'th bit is 1
    if (j & (1 << i)) {
        opt[i][j] = dp(i+1, j, opt);
    }
    else {
        opt[i][j] = dp(i+1, j, opt) + dp(i+1, j | (1 << i), opt);
    }
    return opt[i][j];
}

void print2d(vector<vector<ll>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void sherlock(int t) {
    int n, h;
    cin >> n >> h;
    int m = (1 << n);
    vector<int> v1(m), v2(m);
    good(n, h, v1);
    good(n, h, v2);
    // for (int i = 0; i < m; i++) {
    //     cout << v2[i] << " ";
    // }
    // cout << endl;
    vector<vector<ll>> opt(n + 1, vector<ll> (m, -1));
    for (int j = 0; j < m; j++) {
        opt[n][j] = v1[j];
    }
    for (int j = 0; j < m; j++) {
        dp(0, j, opt);
    }
    // print2d(opt);
    ll ans = 0;
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] == 0) continue;
        int x = m - 1 - i;
        ans += opt[0][x];
    }
    cout << "Case #" << t << ": " << ans << endl;
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