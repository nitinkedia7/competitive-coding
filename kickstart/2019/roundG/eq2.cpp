#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void sherlock(int t) {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll k = 0, sum;
    for (int j = 50; j >= 0; j--) {
        ll k1 = k | (1LL << j);
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (v[i] ^ k1);
        }
        if (sum <= m) {
            k = k1;
        }
        else {
            ll sum0 = 0;
            for (int i = 0; i < n; i++) {
                sum0 += (v[i] ^ k);
            }
            if (sum0 <= m) continue;
            int c0 = 0, c1 = 0;
            for (int i = 0; i < n; i++) {
                if (v[i] & (1LL << j)) c1++;
                else c0++;
            }
            if (c0 <= c1) k = k1; 
        }
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (v[i] ^ k);
    }
    if (sum > m) k = -1;
    cout << "Case #" << t << ": " << k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}