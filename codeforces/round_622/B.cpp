#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, x, y;
    cin >> n >> x >> y;
    if (x > y) swap(x, y);
    // Best rank
    ll z = max(1LL, x + y - n + 1);
    z = min(z, n);
    ll g = n - z + 1;
    if (x >= z || y >= z) {
        g--;
    }
    cout << n-g << " ";
    // Worst rank
    z = min(n, x + y - 1);
    cout << z << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
