#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll u, v;
    cin >> u >> v;
    if (u > v) {
        cout << -1 << endl;
        return;
    } 
    if (u % 2 != v % 2) {
        cout << -1 << endl;
        return;
    }
    if (u == v) {
        if (u == 0) cout << 0 << endl;
        else cout << 1 << endl << u << endl;
        return;
    }
    ll x = (v - u) / 2;
    if ((x & u) == 0) {
        cout << 2 << endl;
        cout << u+x << " " << x << endl;
    }
    else {
        cout << 3 << endl;
        cout << u << " " << x << " " << x << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}