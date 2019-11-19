#include <bits/stdc++.h>
using namespace std;

struct Node {
    // int i;
    int color;
    int beauty;
    long long b;
    long long p;
    long long d;
};

long long select(Node *v, bool &bright) {
    long long s = max(0LL, max(v->p, v->d));
    if (v->b >= s) {
        bright = true;
        return v->b;
    }
    else return s;
}

long long select1(Node *v) {
    long long s = max(v->b - v->beauty, v->p - v->beauty);
    return max(0LL, max(s, v->d));
}

void dfs(int u, int p, vector<Node *> &tree, vector<vector<int>> &adj) {
    // cout << u << " ";
    if (u == 50000) cout << "hi" << endl;
    tree[u]->color = 1;
    if (adj[u].size() == 1 && adj[u][0] == p) { // leaf
        tree[u]->color = 2;
        tree[u]->d = 0;
        tree[u]->p = INT_MIN + 300000;
        tree[u]->b = tree[u]->beauty;
        return;
    }
    for (auto v : adj[u]) {
        if (tree[v]->color == 0) {
            dfs(v, u, tree, adj);
        }
    }
    // Dark
    long long d = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        d += max(0LL, max(tree[v]->d, tree[v]->p));
    }
    tree[u]->d = d;
    // Partial
    bool done = false;
    long long p1 = tree[u]->beauty;
    for (auto v : adj[u]) {
        if (v == p) continue;
        p1 += select(tree[v], done);
    }
    if (done) {
        tree[u]->p = p1;
    }
    else {
        long long diff = INT_MIN;
        for (auto v : adj[u]) {
            if (v == p) continue;
            int s = select(tree[v], done);
            if ((tree[v]->b - s) > diff) {
                diff = tree[v]->b - s;
            }
        }
        tree[u]->p = p1 + diff;
    }
    // Bright
    long long b = tree[u]->beauty;
    for (auto v : adj[u]) {
        if (v == p) continue;
        b += select1(tree[v]) + tree[v]->beauty;
        // if (u == 3) {
        //     cout << b << "wqdwc" << endl;
        // } 
    }
    tree[u]->b = b;
    tree[u]->color = 2;
    return;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<Node *> tree(n);
    int b;
    for (int i = 0; i < n; i++) {
        tree[i] = new Node(); 
        cin >> b;
        // tree[i]->i = i;
        tree[i]->beauty = b;
        tree[i]->color = 0;
    }
    vector<vector<int>> adj(n);
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // dfs
    dfs(0, -1, tree, adj);
    cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << tree[i]->i << "   ";
    //     cout << tree[i]->beauty << " ";
    //     cout << tree[i]->b << " ";
    //     cout << tree[i]->p << " ";
    //     cout << tree[i]->d << endl;
    // }
    long long ans = 0;
    ans = max(ans, tree[0]->b);
    ans = max(ans, tree[0]->p);
    ans = max(ans, tree[0]->d);
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}