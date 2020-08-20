#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    if (a >= 2 * b) {
        cout << b << endl;
    }    
    else {
        cout << (a + b) / 3 << endl;
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
