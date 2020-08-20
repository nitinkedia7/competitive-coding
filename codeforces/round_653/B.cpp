#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    int p = 0, q = 0;
    while (n % 2 == 0) {
        p++;
        n /= 2;
    }
    while (n % 3 == 0) {
        q++;
        n /= 3;
    }
    // 2^p, 3^q
    if (n == 1 && p <= q) {
        cout << (q - p + q) << endl;
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
