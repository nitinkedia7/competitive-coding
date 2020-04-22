#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<ll> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

ll sum(int l, int r, vector<ll> &prefix) {
    if (l > r) return 0;
    return prefix[r] - (l == 0 ? 0 : prefix[l-1]);
}

void sherlock(int t) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + v[i];
    }
    vector<ll> best(n);
    for (int i = 0; i < n; i++) {
        best[i] = 0;
        if (i - m + 1 >= 0) {
            best[i] = max(best[i], sum(i-m+1, i, prefix) - k + (i-m >= 0 ? best[i-m] : 0));
        }
    }
    // print(best);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, best[i]);
        for (int len = 1; len <= m; len++) {
            if (i + len < n) {
                ans = max(ans, best[i] + sum(i+1, i+len, prefix) - k);
            }
        }
    }
    for (int len = 1; len <= m && len <= n; len++) {
        ans = max(ans, sum(0, len - 1, prefix) - k);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}