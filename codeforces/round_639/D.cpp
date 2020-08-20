#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

vector<pair<int,int>> off4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int ux, int uy, int n, int m, vector<vector<char>> &v, vector<vector<int>> &vis) {
    vis[ux][uy] = 1;
    int vx, vy;
    for (int i = 0; i < 4; i++) {
        vx = ux + off4[i].first;
        vy = uy + off4[i].second;
        if (!valid(vx, vy, n, m)) continue;
        if (vis[vx][vy] == 0 && v[vx][vy] == '#') {
            dfs(vx, vy, n, m, v, vis);
        }
    }
    vis[ux][uy] = 2;
    return;
} 

bool row(int n, int m, vector<vector<char>> &v, int &x) {
    for (int i = 0; i < n; i++) {
        int l = -1, r = -1;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#') {
                l = j;
                break;
            }
        }
        for (int j = m-1; j >= 0; j--) {
            if (v[i][j] == '#') {
                r = j;
                break;
            }
        }
        if (l == -1) continue;
        for (int j = l; j <= r; j++) {
            if (v[i][j] == '.') {
                return false;
            }
        }
        x++;
    }
    return true;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }    
    int r = 0, c = 0;
    if (!row(n, m, v, r)) {
        cout << -1 << endl;
        return;
    }
    vector<vector<char>> v_t(m, vector<char> (n));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         v_t[n - i - 1][m - j - 1] = v[i][j];
    //     }
    // }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            v_t[i][j] = v[n - j - 1][m - i - 1]; 
        }
    }
    if (!row(m, n, v_t, c)) {
        cout << -1 << endl;
        return;
    }
    // cout << r << " " << c << endl;
    r = n - r, c = m - c;
    if ((r == 0 && c > 0) || (r > 0 && c == 0)) {
        cout << -1 << endl;
        return;
    }
    // dfs
    int cc = 0;
    vector<vector<int>> vis(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#' && vis[i][j] == 0) {
                dfs(i, j, n, m, v, vis);
                cc++;
            }
        }
    }
    cout << cc << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
