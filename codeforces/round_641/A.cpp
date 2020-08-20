#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, k;
    cin >> n >> k;
    ll a = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            a = i;
            break;
        }
    }
    if (a == 2) {
        cout << n + k * a << endl;
    }
    else {
        cout << n + a + (k - 1) * 2 << endl;
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
