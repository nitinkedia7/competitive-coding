#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

vector<vector<int>> b{{8, 9 , 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[i][j] = b[i % 4][j % 4];
        }
    }
    int x = n / 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p = i / 4, q = j / 4;
            int r = p * x + q;
            v[i][j] += r * 16;            
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    v.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
