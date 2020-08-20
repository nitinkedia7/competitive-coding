#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ull = unsigned long long;
const ull MOD = 1000000007;

void sherlock(int t) {
    ull n, r;
    cin >> n >> r;
    ull x = min(n - 1, r);
    ull ans = (x * (x + 1)) / 2;
    if (r >= n) ans++;
    cout << ans << endl;   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
