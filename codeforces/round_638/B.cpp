#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[x] = 1;
    }    
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 1) sum++;
    }
    if (sum > k) {
        cout << -1 << endl;
        return;
    }
    int r = k - sum;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0 && r > 0) {
            r--;
            v[i] = 1;
        }
    }
    cout << k * n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[j] == 1) cout << j << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
