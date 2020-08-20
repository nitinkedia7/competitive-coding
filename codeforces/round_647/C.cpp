#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n;
    cin >> n;
    ll p = 1, ans = 0;
    for (int i = 0; i < 61; i++) {
        ll q = (n + p) / p;
        ans += (q - 1);
        p *= 2;
    }    
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
