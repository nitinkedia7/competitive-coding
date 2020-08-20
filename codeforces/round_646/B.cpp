#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int get_set(vector<int> &v, int l, int r) {
    if (l > r) return 0;
    return v[r] - (l == 0 ? 0 : v[l-1]);
}

int get_unset(vector<int> &v, int l, int r) {
    if (l > r) return 0;
    return (r - l + 1) - get_set(v, l, r);
}

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v(n);
    v[0] = (s[0] == '1' ? 1 : 0);
    for (int i = 1; i < n; i++) {
        v[i] = v[i-1];
        if (s[i] == '1') {
            v[i]++;
        }
    }    
    int ans = min(get_unset(v, 0, n - 1), get_set(v, 0, n-1));
    for (int i = 0; i < n; i++) {
        // cout << v[i] << " ";
        ans = min(ans, get_set(v, 0, i) + get_unset(v, i+1, n-1));
        ans = min(ans, get_unset(v, 0, i) + get_set(v, i+1, n-1));

    }
    // cout << endl;
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
