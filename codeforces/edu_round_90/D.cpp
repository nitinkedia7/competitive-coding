#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> v(n);
    ll og_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i % 2 == 0) og_sum += v[i];
    }
    ll cur_sum = og_sum;
    // cout << cur_sum << endl;
    // handle 0,1 2,3 4,5
    ll prev_diff = 0, cur_diff = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        cur_diff += (v[i+1] - v[i]);
        if (cur_diff - prev_diff >= 0) {
            cur_sum = max(cur_sum, og_sum + cur_diff - prev_diff);
        }
        prev_diff = min(prev_diff, cur_diff);
    }
    // cout << cur_sum << endl;
    // handle 1,2 3,4 5,6
    cur_diff = -1 * v[0], prev_diff = -1 * v[0];
    for (int i = 1; i + 1 < n; i += 2) {
        cur_diff += (v[i] - v[i+1]);
        if (cur_diff - prev_diff >= 0) {
            cur_sum = max(cur_sum, og_sum + cur_diff - prev_diff);
        }
        prev_diff = min(prev_diff, cur_diff);
    }
    cout << cur_sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
