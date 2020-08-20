#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) x++;
        if (b[i]) y++;
        if (a[i] && b[i]) z++;
    }
    // cout << x << " " << y << " " << z << endl;
    if (z >= x) {
        cout << -1 << endl;
    }
    else if (x > y) {
        cout << 1 << endl;
    }
    else {
        y -= z;
        x -= z;
        if (y % x == 0) {
            cout << (y/x + 1) << endl;
        }
        else {
            cout << (y + x - 1) / x << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
