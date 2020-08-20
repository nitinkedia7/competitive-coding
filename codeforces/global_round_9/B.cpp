#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    bool ans = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
            // corners -> sides -> interior
            bool corner = (i == 0 || i == n - 1) && (j == 0 || j == m - 1);
            bool side = (i == 0 || i == n -1 || j == 0 || j == m - 1);
            if (corner) {
                if (v[i][j] > 2) {
                    ans = false;
                }
                v[i][j] = 2;
            }
            else if (side) {
                if (v[i][j] > 3) {
                    ans = false;
                }
                v[i][j] = 3;
            }
            else {
                if (v[i][j] > 4) {
                    ans = false;
                }
                v[i][j] = 4;
            }
        }
    }  
    if (ans == false) {
        cout << "NO" << endl;
        return;
    }  
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
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
