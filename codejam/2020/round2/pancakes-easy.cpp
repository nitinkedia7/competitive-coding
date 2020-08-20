#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll l, r;
    cin >> l >> r;
    int k = 1;
    bool b = true;
    while (b) {
        b = false;
        if (l >= r) {
            if (k <= l) {
                l -= k;
                k++;
                b = true;
            }
        }
        else {
            if (k <= r) {
                r -= k;
                k++;
                b = true;
            }
        }
    }
    cout << "Case #" << t << ": " << k-1 << " " << l << " " << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
