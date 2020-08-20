#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

#define all(x) (x).begin(), (x).end()

void sherlock(int t) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    while (1) {
        if (*max_element(all(a)) == 0) break;
        ll x = 0;
        for (int i = 0; i < n; i++) {
            x += (a[i] % k); 
            a[i] /= k;
        }
        if (x > 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}