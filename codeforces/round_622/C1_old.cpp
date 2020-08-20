#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    vector<int> done(n);
    // lowest to tallest building
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < n; j++) {
            if (done[j]) continue;
            if (p == -1 || v[j] < v[p]) {
                p = j;
            }
        }
        done[p] = 1;
        ll l = 0, r = 0;
        for (int j = 0; j < p; j++) {
            if (v[j] > v[p]) {
                l += (v[j] - v[p]);
            }
        }
        for (int j = p+1; j < n; j++) {
            if (v[j] > v[p]) {
                r += (v[j] - v[p]);
            }
        }
        if (l <= r) {
            for (int j = 0; j < p; j++) {
                if (v[j] > v[p]) {
                    v[j] = v[p];
                }
            }
        }
        else {
            for (int j = p+1; j < n; j++) {
                if (v[j] > v[p]) {
                    v[j] = v[p];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
