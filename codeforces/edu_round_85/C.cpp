#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    ll bu = 0, ad = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int p = (i - 1 + n) % n;
        if (a[i] > b[p]) {
            bu += a[i] - b[p];
            ad = min(ad, b[p]);
        }
        else {
            ad = min(ad, a[i]);
        }
    }
    cout << bu + ad << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}