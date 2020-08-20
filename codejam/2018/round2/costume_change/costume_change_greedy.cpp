#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int get_index(int c, int i, int j, int n) {
    return c * (n * n) + i * n + j;
}

void print(vector<vector<int>> &v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    // Build conflicts
    int M = n * n * (2 * n), N2 = n * n;
    vector<int> max_conf(M, 0), get_conf(N2, 0);
    int y = M-1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c = 0;
            // ROW
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                if (v[i][j] == v[i][k]) c++;
            }
            // COL
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                if (v[i][j] == v[k][j]) c++;
            }
            get_conf[get_index(0, i, j, n)] = c;
            if (c > 0) max_conf[get_index(c, i, j, n)] = 1;
        }
    }
    // for (int i = 0; i < (2 * n); i++) {
    //     for (int j = 0; j < N2; j++) {
    //         if (max_conf[i * N2 + j] == 1) {
    //             cout << i << " " << j / n << "," << j%n << endl; 
    //         }
    //     }
    // }
    // Eradicate conflicts
    int ans = 0;
    while (y >= 0) {
        if (max_conf[y] == 0) {
            y--;
            continue;
        }
        int x = y % N2;
        int i = x / n, j = x % n;
        // cout << i << "," << j << endl;
        // print(v, n);
        // found most conflicting one, change the costume
        vector<int> cos(2 * n, 0);
        // ROW
        for (int k = 0; k < n; k++) {
            if (k == j) continue;
            int z = v[i][k];
            if (z > 0) {
                cos[z - 1 + n] = 1;
            }
            else {
                cos[z + n] = 1;
            }
        }
        // COL
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            int z = v[k][j];
            if (z > 0) {
                cos[z - 1 + n] = 1;
            }
            else {
                cos[z + n] = 1;
            }
        }
        // remove it from max_conf
        // ROW
        for (int k = 0; k < n; k++) {
            if (k == j) continue;
            if (v[i][j] == v[i][k]) {
                // decr i,k conflict by one
                int c = get_conf[get_index(0, i, k, n)];
                get_conf[get_index(0, i, k, n)]--;
                max_conf[get_index(c, i, k, n)] = 0;
                if (c > 1) max_conf[get_index(c-1, i, k, n)] = 1;
            }
        }
        // COL
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            if (v[i][j] == v[k][j]) {
                int c = get_conf[get_index(0, k, j, n)];
                get_conf[get_index(0, k, j, n)]--;
                max_conf[get_index(c, k, j, n)] = 0;
                if (c > 1) max_conf[get_index(c-1, k, j, n)] = 1;
            }
        }
        for (int z = 0; z < 2 * n; z++) {
            if (cos[z] == 0) {
                if (z >= n) {
                    v[i][j] = z - n + 1;
                }
                else {
                    v[i][j] = z - n;
                }
                break;
            }
        }
        // print(v, n);
        max_conf[y] = 0;
        ans++;
        y--;
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
