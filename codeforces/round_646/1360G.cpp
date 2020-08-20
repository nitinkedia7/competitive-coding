#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
        cout << "NO" << endl;
        return;
    }        
    vector<vector<int>> v(n, vector<int> (m, 0));
    int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a; j++) {
            v[i][x % m] = 1;
            x++;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
