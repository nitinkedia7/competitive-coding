#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

struct Node {
    ll x;
    Node *left, *right;
};

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> v(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
    }
    if (n == 1) {
        cout << v[0] << endl;
        return;
    } 
    ll cur_sum = 0, next_sum = 0;
    int s = 3, l = n - (n == 3 ? 3 : 4);
    for (int i = 0; i < l; i++) {
        if (i % 2 == 0) cur_sum += v[i + s];
        else next_sum += v[i + s];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, v[i] + v[i + 1] + cur_sum);
        ll prev_cur_sum = cur_sum, prev_next_sum = next_sum;
        cur_sum = prev_next_sum + v[s + l];
        next_sum = prev_cur_sum - v[s];
        s++;
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
