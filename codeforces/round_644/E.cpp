#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> v(n+1, vector<int> (n+1, 1));
    char x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            v[i][j] = x - '0';
        }
    }    
    for (int j = n-1; j >= 0; j--) {
        for (int i = n-1; i >= 0; i--) {
            if (v[i][j] == 1) {
                if (v[i+1][j] == 1) {
                    continue;
                }
                else if (v[i][j+1] == 1) {
                    continue;
                }
                else {
                    cout << "NO" << endl;
                    return;
                }
            } 
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
