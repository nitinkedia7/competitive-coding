#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int digits(ll k) {
    if (k == 0) return 1;
    int c = 0;
    while (k > 0) {
        k /= 10;
        c++;
    }
    return c;
}

ll sum(ll n) {
    return (n * (n+1)) / 2;
}

ll meta(ll k) {
    int d = digits(k);
    vector<ll> count{1};
    for (int i = 0; i < d; i++) {
        count.push_back(10 * count.back());
    }
    ll x = k - count[d-1] + 1;
    ll l = x, r = 0;
    ll ans = (sum(l) - sum(r)) * d;
    // cout << l << " " << r << " " << d << endl; 
    d--;
    while (d > 0) {
        r = l;
        l = r + (count[d] - count[d-1]);
        ans += (sum(l) - sum(r)) * d;
        // cout << l << " " << r << " " << d << endl; 
        d--;
    }
    return ans;
}

ll find_k(ll n) {
    ll l = 1, r = INT_MAX, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (meta(mid) < n) {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return l;
}

void sherlock(int t) {
    ll n;
    cin >> n;
    ll prev_sum = 0, sum = 0;
    ll count = 1;
    int d = 0;
    // int k1 = 0;
    // while (sum < n) {
    //     prev_sum = sum;
    //     k1++;
    //     if (k1 >= count) {
    //         d++;
    //         count *= 10;
    //     }
    //     cur += d;
    //     sum += cur;
    //     // cout << k1 << " " << sum << " " << meta(k1) << endl;
    // }
    ll k = find_k(n);
    // cout << "k1 = " << k1 << endl;
    // cout << "k = " << k << endl;
    n -= meta(k-1);
    // Given seq 1 2 3 ... k find the n'th digit
    // cout << "n = " << n << endl;
    d = 0;
    count = 1;
    ll prev_count = 0;
    prev_sum = 0;
    sum = 0;
    while (sum < n) {
        prev_count = count;
        prev_sum = sum;
        d++;
        count *= 10;
        sum += (count - prev_count) * d;
        // cout << sum << "," << d << endl;
    }
    // cout << "d = " << d << endl;
    // cout << prev_count << endl;
    n -= prev_sum;
    ll z = (n + d - 1) / d;
    ll num = prev_count + z - 1;
    // cout << num << endl;
    string s = to_string(num);
    cout << s[(n-1) % d] << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // for (int i = 1; i <= 100; i++) {
    //     cout << i << "," << meta(i) << endl;
    // }
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
