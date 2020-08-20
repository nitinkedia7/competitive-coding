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

void sherlock(int t) {
    ll n;
    cin >> n;
    int k = 0;
    ll prev_sum = 0, sum = 0, cur = 0;
    ll count = 1;
    int d = 0;
    while (sum < n) {
        prev_sum = sum;
        k++;
        if (k >= count) {
            d++;
            count *= 10;
        }
        cur += d;
        sum += cur;
        // cout << sum << "," << k << endl;
    }
    // cout << "k = " << k << endl;
    n -= prev_sum;
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
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
