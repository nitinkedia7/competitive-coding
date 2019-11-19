#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void dfs(int u, int h, vector<vector<int>> &adj, vector<int> &path, vector<int> &foc, vector<int> &nid) {
    path.push_back(h);
    nid.push_back(u);
    if (foc[u] == -1) foc[u] = path.size() - 1;
    for (auto v : adj[u]) {
        dfs(v, h + 1, adj, path, foc, nid);
        path.push_back(h);
        nid.push_back(u);
    }
}

void build(vector<int> &v, int n, vector<int> &path) {
    for (int i = n - 1; i > 0; i--) {
        v[i] = v[2 * i];
        if (path[v[2*i + 1]] < path[v[2 * i]]) {
            v[i] = v[2*i + 1];
        }
    }
}

int query(vector<int> &v, int l, int r, int n, vector<int> &path) {
    assert (l < r);
    int lca = l;
    int l1 = l, r1 = r;
    l += n;
    r += n;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            assert(v[l] >= 0 && v[l] < n);
            if (path[v[l]] < path[lca]) lca = v[l];
            l++;
        }
        if (r & 1) {
            r--;
            assert(v[r] >= 0 && v[r] < n);
            if (path[v[r]] < path[lca]) lca = v[r];
        }
    }
    // cout << l1 << " " << r1 << " " << lca << endl;
    return lca;
}

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n, s, x;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> isChild(n + 1);
    for (int i = 1; i <= n; i++) {
        int s;
        cin >> s;
        while (s--) {
            cin >> x;
            isChild[x] = 1;
            adj[i].push_back(x);
        }
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (isChild[i] == 0) root = i;
    }
    // Euler path
    vector<int> path, foc(n + 1, -1), nid;
    dfs(root, 1, adj, path, foc, nid); // DONE call from root
    // segtree
    // print(path);
    // print(foc);
    n = path.size();
    vector<int> v(2 * n);
    for (int i = 0; i < n; i++) {
        v[n + i] = i;
    }
    build(v, n, path);
    // print(v);
    int q;
    cin >> q;
    cout << "Case " << t <<  ": " << endl;
    while (q--) {
        int y;
        cin >> x >> y;
        int l = min(foc[x], foc[y]);
        int r = max(foc[x], foc[y]) + 1;
        // cout << x << " " << y << " " << l << " " << r << " ";
        cout << nid[query(v, l, r, n, path)] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}