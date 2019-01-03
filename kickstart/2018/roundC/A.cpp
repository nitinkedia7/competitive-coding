#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int n, vector<int> &cycle) {
    stack<int> stack;
    vector<int> color(n+5);
    vector<int> par(n+5);
    for (int i = 1; i <= n; i++) {
        color[i] = 0; // white
        par[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            stack.push(i);
            color[i] = 1;
            while (!stack.empty()) {
                int u = stack.top();
                color[u] = 1; //gray
                for (int j = 0; j < adj[u].size(); j++) {
                    // if (adj[u][j] == u) continue;
                    if (color[adj[u][j]] == 0) {
                        // cout << "discovered " << adj[u][j] << endl;
                        stack.push(adj[u][j]);
                        par[adj[u][j]] = u;
                        color[adj[u][j]] = 1;
                        break;
                    }
                    if (color[adj[u][j]] == 1 && par[u] != adj[u][j]) {
                        // cout << "from " << u << endl;
                        // cout << "back " << adj[u][j] << " " << stack.size() << endl;
                        while (stack.top() != adj[u][j]) {
                            // cout << stack.top() << " ";
                            cycle[stack.top()] = 1;
                            stack.pop();
                        }
                        cycle[stack.top()] = 1;
                        return;
                    }
                    if (j == adj[u].size()-1) {
                        int x = stack.top();
                        stack.pop();
                        color[x] = 2;
                    }
                }
            }
        }
    }
}

void bfs(vector<int> adj[], int n, int u, vector<int> &v) {
    queue<int> q;
    vector<int> color(n+5);
    for (int i = 1; i <= n; i++) color[i] = 0;
    q.push(u);
    color[u] = 1;
    v[u] = 0;
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (int j = 0; j < adj[f].size(); j++) {
            if (color[adj[f][j]] == 0) {
                q.push(adj[f][j]);
                color[adj[f][j]] = 1;
                v[adj[f][j]] = v[f]+1;
            }
        }
    }
}

int main() {
    int t;
    int n, x, y;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        vector<int> adj[n+5];
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        // cout << "input taken" << endl;
        vector<int> cycle(n+5, 0);
        dfs(adj, n, cycle);
        // cout << endl;
        // cout << "dfs done" << endl;
        // for (int i = 1; i <= n; i++) {
        //     if (cycle[i]) cout << i << " ";
        // }
        // cout << endl;
        vector<vector<int> > v(n+1, vector<int> (n+1, -1));
        for (int i = 1; i <= n; i++) {
            if (cycle[i]) {
                bfs(adj, n, i, v[i]);
            }
        }
        cout << "Case #" << c << ":";
        for (int j = 1; j <= n; j++) {
            int m = INT_MAX;
            for (int i = 1; i <= n; i++) {
                if (cycle[i] == 1) {
                    m = min(m, v[i][j]);
                }
            }
            cout << " " << m;
        }
        cout << endl;
    }
}