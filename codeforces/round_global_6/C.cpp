#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

void sherlock(int t) {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int> (c));
    if (c == 1) {
        if (r == 1) {
            cout << 0 << endl;
            return;
        }
        for (int i = 0; i < r; i++) {
            v[i][0] = i + 2;
        }
        for (int i = 0; i < r; i++) {
            cout << v[i][0] << endl;
        }
        return;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            v[i][j] = i + 1;
        }
    }
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            v[i][j] = (v[i][j] / gcd(v[i][j], r + j + 1)) * (r + j + 1); 
        }
    }
    for (int i = 0; i < r; i++) {
        int g = v[i][0];
        for (int j = 1; j < c; j++) {
            g = gcd(g, v[i][j]);
        }
        if (g != (i + 1)) {
            cout << 0 << endl;
            return;
        }
    }
    for (int j = 0; j < c; j++) {
        int g = v[0][j];
        for (int i = 0; i < r; i++) {
            g = gcd(g, v[i][j]);
        }
        if (g != (r + j + 1)) {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}