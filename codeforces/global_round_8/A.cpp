#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll a, b, n;
    cin >> a >> b >> n;
    int x = 0;
    while (a <= n && b <= n) {
        if (a < b) swap(a, b);
        b += a;
        x++;
    }    
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
