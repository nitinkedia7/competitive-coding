#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ld PI = 3.1415926535897932384626433832795;

void sherlock(int t) {
    int n;
    cin >> n;
    ld ans = 1;
    ans /= tan(PI / (2 * n));
    cout.precision(10);
    cout << fixed << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
