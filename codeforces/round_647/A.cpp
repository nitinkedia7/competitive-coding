#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool is_pow2(ll x, ll &c) {
    c = 0;
    while (x % 2 == 0) {
        c++;
        x /= 2;
    }
    return x == 1;
}

void sherlock(int t) {
    ll a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    } 
    // a <= b
    if (b % a != 0) {
        cout << -1 << endl;
        return;
    }
    ll q = b / a, c;
    if (is_pow2(q, c)) {
        ll x = c / 3;
        c = c % 3;
        if (c > 0) x++;
        cout << x << endl;
    } 
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
