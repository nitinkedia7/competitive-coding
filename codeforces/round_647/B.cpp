#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N = 1024;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    sort(all(v));
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < n; j++) {
            x[j] = v[j] ^ i;
        }
        sort(all(x));
        if (v == x) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
