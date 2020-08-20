#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> w(k), a(n);
    int one = 0;   
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    for (int i = 0; i < k; i++) {
        cin >> w[i];
        if (w[i] == 1) one++; 
    }
    sort(all(w), greater<int>());
    sort(all(a));
    ll ans = 0;
    int i = n - 1;
    for (int j = 0; j < k; j++) {
        ans += a[i];
        if (one > 0) {
            ans += a[i];
            one--;
        }
        i--;
    }
    // cout << i << endl;
    i = 0;
    for (int j = 0; j < k; j++) {
        w[j]--;
        if (w[j] > 0) {
            ans += a[i];
            i += w[j];
        }
    }
    // cout << i << endl;
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
