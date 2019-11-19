#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

bool join(vector<int> &parent, vector<int> &rank, int i, int j, int &f) {
    int x = find(parent, i);
    int y = find(parent, j);
    if (x == y) return false;
    if (rank[x] > rank[y]) {
        parent[y] = x;
        rank[x]++;
    }
    else {
        parent[x] = y;
        rank[y]++;
    }
    f--;
    return true;
}

void reset(vector<int> &v, int n, int p) {
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = p == -1 ? i : p;
    }
    return;
} 

int main() {
    int tt;
    cin >> tt;
    int n, m, u, v, f;
    vector<int> parent, rank;
    bool joined;
    int y;
    for (int t = 1; t <= tt; t++) {
        cin >> n >> m;
        reset(parent, n, -1);
        reset(rank, n, 0);
        f = n;
        y = 0;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--;
            v--;
            joined = join(parent, rank, u, v, f);
            if (joined) {
                y += 1;
            }
        }
        
        y += (f-1) * 2;
        cout << "Case #" << t << ": " << y << endl;
    }
}