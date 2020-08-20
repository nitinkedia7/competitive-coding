#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, x;
    cin >> n >> x;
    vector<int> v(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    p[0] = v[0] % x;
    for (int i = 1; i < n; i++) {
        p[i] = (p[i-1] + v[i]) % x;
    }
    int maxl = -1;
    // saare non-zero
    for (int i = 0; i < n; i++) {
        if (p[i] != 0) maxl = i + 1;
    }
    // find first non-zero;
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] != 0) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        cout << maxl << endl;
        return;
    }
    for (int i = j + 1; i < n; i++) {
        if (p[i] == 0) {
            maxl = max(maxl, i - j);
        }
    }
    cout << maxl << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
