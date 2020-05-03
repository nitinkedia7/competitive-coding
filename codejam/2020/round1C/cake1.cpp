#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void d2(int t, int n, vector<ll> &a) {
    sort(all(a));
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            cout << "Case #" << t << ": " << 0 << endl;
            return;
        }
    }
    cout << "Case #" << t << ": " << 1 << endl;
}

void d3(int t, int n, vector<ll> &a) {
    sort(all(a));
    for (int i = 2; i < n; i++) {
        if (a[i] == a[i-1] && a[i-1] == a[i-2]) {
            cout << "Case #" << t << ": " << 0 << endl;
            return;
        }
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1] && i < n-1) {
            cout << "Case #" << t << ": " << 1 << endl;
            return;
        }
    }
    set<ll> s;
    for (int i = n-1; i >= 0; i--) {
        if (s.find(2 * a[i]) != s.end()) {
            cout << "Case #" << t << ": " << 1 << endl;
            return;
        }
        s.insert(a[i]);
    }

    cout << "Case #" << t << ": " << 2 << endl;
}

void sherlock(int t) {
    int n, d;
    cin >> n >> d;
    if (d > 3) exit(0);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    if (d == 2) d2(t, n, a);
    if (d == 3) d3(t, n, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
