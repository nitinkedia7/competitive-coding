#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

// bool feasible(ll a, ll b, ll n, ll m) {
//     if (a + b < n + m) return;

// }

void sherlock(int t) {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;   
    if (a + b < n + m) {
        cout << "No" << endl;
        return;
    }
    ll min_ab = min(a, b);
    if (m <= min_ab) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
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
