#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int> (n));
    int c = 0, base = k / n, rem = k % n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < base; j++) {
            v[i][c] = 1;
            c = (c + 1) % n;
        }
        if (i < rem) {
            v[i][c] = 1;
            c = (c + 1) % n;
        }
    }
    cout << (rem == 0 ? 0 : 2) << endl;    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
