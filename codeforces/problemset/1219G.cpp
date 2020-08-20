#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

ll f04(int n, int m, vector<ll> col_sum) {
    if (m < 4) return 0;
    sort(all(col_sum), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += col_sum[i];
    }
    return ans;
}   

ll f13(int n, int m, vector<ll> &col_sum, vector<vector<ll>> &v) {
    if (m < 3) return 0;
    vector<ll> col_sum_copy;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll rans = 0;
        col_sum_copy = col_sum;
        for (int j = 0; j < m; j++) {
            col_sum_copy[j] -= v[i][j];
            rans += v[i][j];
        }
        sort(all(col_sum_copy), greater<ll>());
        for (int j = 0; j < 3; j++) {
            rans += col_sum_copy[j];
        }
        ans = max(ans, rans);
        col_sum_copy.clear();
    }
    return ans;
}

ll f22(int n, int m, vector<ll> &col_sum, vector<vector<ll>> &v) {
    assert(n <= m);
    if (n < 2 || m < 2) return 0;
    
    vector<ll> col_sum_copy;
    ll ans = 0;
    for (int i1 = 0; i1 < n; i1++) {
        for (int i2 = i1 + 1; i2 < n; i2++) {
            ll rans = 0;
            col_sum_copy = col_sum;
            for (int j = 0; j < m; j++) {
                col_sum_copy[j] -= (v[i1][j] + v[i2][j]);
                rans += (v[i1][j] + v[i2][j]);
            }
            // sort(all(col_sum_copy), greater<ll>());
            // for (int j = 0; j < 2; j++) {
            //     rans += col_sum_copy[j];
            // }
            ll max1 = 0, max2 = 0;
            for (int j = 0; j < m; j++) {
                if (col_sum_copy[j] >= max1) {
                    max2 = max1;
                    max1 = col_sum_copy[j];
                }
                else if (col_sum_copy[j] > max2) {
                    max2 = col_sum_copy[j];
                }
            }
            ans = max(ans, rans + max1 + max2);
            col_sum_copy.clear();
        }
    }
    return ans;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll> (m));
    vector<ll> row_sum(n, 0), col_sum(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            row_sum[i] += v[i][j];
            col_sum[j] += v[i][j];
        }
    }
    vector<vector<ll>> v_t(m, vector<ll> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v_t[i][j] = v[n - j - 1][m - i - 1]; 
        }
    }
    vector<ll> row_sum_t(m, 0), col_sum_t(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            row_sum_t[i] += v_t[i][j];
            col_sum_t[j] += v_t[i][j];
        }
    }

    ll ans = 0;
    ans = max(ans, f04(n, m, col_sum));
    ans = max(ans, f13(n, m, col_sum, v));
    if (n <= m) {
        ans = max(ans, f22(n, m, col_sum, v));
    }
    else {
        ans = max(ans, f22(m, n, col_sum_t, v_t));
    }
    ans = max(ans, f13(m, n, col_sum_t, v_t));
    ans = max(ans, f04(m, n, col_sum_t));
    // handle less than 4 rows. cols
    if (n < 4 || m < 4) {
        ll rans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rans += v[i][j];
            }
        }
        ans = max(ans, rans);
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
