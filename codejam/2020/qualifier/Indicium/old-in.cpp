#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void reset(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            v[i][j] = 0;
        }
    }
    return;
 } 

bool find_path(int n, vector<vector<int>> &adj) {
    // path from n to 2 * n - 1;
    vector<int> color(2 * n + 2, 0);
    vector<int> parent(2 * n + 2, -1);
    queue<int> q;
    q.push(n);
    color[n] = 1;
    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v = 0; v < 2 * n + 2; v++) {
            if (adj[u][v] && color[v] == 0) {
                parent[v] = u;
                color[v] = 1;
                q.push(v);
            }
        }
        color[u] = 2;
    }
    // cout << "queue empty" << endl;
    if (parent[2 * n + 1] == -1) return false;
    int cur = 2 * n + 1, par = parent[2 * n + 1];
    while (par != -1) {
        adj[par][cur] = 0;
        adj[cur][par] = 1;
        cur = par;
        par = parent[cur];
        // cout << 'x';
    }
    return true;
}

bool fill_row(int r, int n, vector<vector<int>> &v, vector<vector<int>> &col) {
    vector<vector<int>> adj(2 * n + 2, vector<int> (2 * n + 2, 0));
    // cols 0 to n-1 in row r
    for (int i = 0; i < n; i++) {
        if (v[r][i] != 0) {
            int x = v[r][i];
            adj[i][n + x] = 1;
            continue;
        }
        for (int x = 1; x <= n; x++) {
            if (col[i][x] == 0) { // x number in column i is unused
                adj[i][n + x] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) adj[n][i] = 1; // from source
    for (int i = n + 1; i <= 2 * n; i++) adj[i][2 * n + 1] = 1; // to sink
    // bipartite matching
    int flow = 0;
    while (find_path(n, adj)) {
        flow++;
    }
    // cout << flow << " " << n << endl;
    // fill r'th row using the match found
    for (int num = 1; num <= n; num++) {
        for (int i = 0; i < n; i++) {
            if (adj[n + num][i] == 1) {
                v[r][i] = num;
                col[i][num] = 1;
                break;
            }
        }
    }
    return flow == n;
}

bool good_diagonal(int n, int a, int b, int c, vector<vector<int>> &v, vector<vector<int>> &col) {
    reset(v);
    reset(col);

    for (int i = 0; i < n; i++) {
        int z;
        if (i == n - 2) z = b;
        else if (i == n - 1) z = c;
        else z = a;
        v[i][i] = z;
        col[i][z] = 1;
    }
    bool done = true;
    for (int i = 0; i < n; i++) {
        done = done && fill_row(i, n, v, col);
        if (!done) break;
    }
    return done;
}

void sherlock(int t) {
    int n, tr;
    cin >> n >> tr;
    if (tr == n + 1 || tr == n * n - 1) {
        cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        return;
    }
    vector<vector<int>> v(n, vector<int> (n));
    vector<vector<int>> col(n, vector<int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i == j && i != k) continue;
                if (i != j && i == k) continue;
                if ((n - 2) * i + j + k == tr) {
                    bool done = good_diagonal(n, i, j, k, v, col);
                    cout << done << endl;
                    // if (!done) continue;
                    cout << "Case #" << t << ": POSSIBLE" << endl;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            cout << v[i][j];
                            if (j < n - 1) cout << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                    // return;
                }
            }
        }
    }
    cout << "Case #" << t << ": ERROR" << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}