#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int u, int n, vector<vector<int>> &same, vector<vector<int>> &diff, vector<int> &color, int &rhs, int &lhs, int f) {
    color[u] = 1;
    if (f == 0) lhs += 1;
    else rhs += 1;
    for (auto v : diff[u]) {
        if (color[v] == 0) {
            dfs(v, n, same, diff, color, rhs, lhs, !f);
        }
    }
    for (auto v : same[u]) {
        if (color[v] == 0) {
            dfs(v, n, same, diff, color, rhs, lhs, f);
        }
    }
    color[u] = 2;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    vector<vector<int>> f(n, vector<int> (n));
    vector<vector<int>> s(n, vector<int> (n));
    char x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            v[i][j] = x == '.' ? 0 : 1;
            f[i][j] = i + 1 + j - 1;
            s[i][j] = 3 * n - i + j - 1 - 1;
        }
    }
    int m = 4 * n - 2;
    vector<vector<int>> same(m);
    vector<vector<int>> diff(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = f[i][j], y = s[i][j];
            if (v[i][j] == 0) { // white
                diff[x].push_back(y);
                diff[y].push_back(x);
            }
            else {
                same[x].push_back(y);
                same[y].push_back(x);
            }
        }
    }
    vector<int> color(m);
    int lhs, rhs, ans = 0;
    for (int i = 0 ; i < m; i++) {
        if (color[i] == 0) {
            lhs = 0;
            rhs = 0;
            dfs(i, m, same, diff, color, lhs, rhs, 0);
            ans += min(lhs, rhs);
        }
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}