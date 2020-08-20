#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int WEIGHT_MAX = INT_MAX / 2;

bool find_path(int source, int sink, vector<set<int>> &adj, map<pair<int,int>,int> &weight) {
    vector<int> parent(adj.size(), -1), vis(adj.size(), 0);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
                parent[v] = u;
            }
        }
    }
    if (parent[sink] == -1) return false;
    int cur = sink, par = parent[cur];
    int bottleneck = INT_MAX;
    while (par != -1) {
        bottleneck = min(bottleneck, weight[{par, cur}]);
        cur = par;
        par = parent[cur];
    }
    cur = sink, par = parent[cur];
    while (par != -1) {
        weight[{par, cur}] -= bottleneck;
        if (weight[{par, cur}] == 0) {
            adj[par].erase(cur);
        } 
        weight[{cur, par}] += bottleneck;
        adj[cur].insert(par);
        cur = par;
        par = parent[cur];
    }

    return true;
}

vector<pair<int,int>> get_neighbours(int x, int y, char target1, char target2, vector<vector<char>> &v) {
    vector<pair<int,int>> ans;
    int r = v.size(), c = v[0].size();
    // ROW
    for (int j = y+1; j < c; j++) {
        if (v[x][j] == target1 || v[x][j] == target2) {
            ans.push_back({x, j});
        }
        else if (v[x][j] == '#') break;
    }
    for (int j = y-1; j >= 0; j--) {
        if (v[x][j] == target1 || v[x][j] == target2) {
            ans.push_back({x, j});
        }
        else if (v[x][j] == '#') break;
    }
    // COLUMN
    for (int i = x+1; i < r; i++) {
        if (v[i][y] == target1 || v[i][y] == target2) {
            ans.push_back({i, y});
        }
        else if (v[i][y] == '#') break;
    }
    for (int i = x-1; i >= 0; i--) {
        if (v[i][y] == target1 || v[i][y] == target2) {
            ans.push_back({i, y});
        }
        else if (v[i][y] == '#') break;
    }
    return ans;
}

int protect(int x, int y, vector<vector<char>> &v, vector<set<int>> &adj, map<pair<int,int>,int> &weight) {
    int r = v.size(), c = v[0].size();
    vector<pair<int,int>> neighbours = get_neighbours(x, y, '-', '|', v);    
    int in_row = 0, in_col = 0;
    for (int i = 0; i < (int) neighbours.size(); i++) {
        if (neighbours[i].first == x) in_row++;
        if (neighbours[i].second == y) in_col++; 
    }
    if (in_row == 0) {
        adj[x * c + y].insert(r * c + x * c + y);
        weight[{x * c + y, r * c + x * c + y}] = 1;
    }
    if (in_col == 0) {
        adj[x * c + y].insert(2 * r * c + x * c + y);
        weight[{x * c + y, 2 * r * c + x * c + y}] = 1;
    }
    if (in_row == 0 && in_col == 0) return 3;
    else if (in_row == 0) return 1;
    else if (in_col == 0) return 2;
    return 0;
}

void light(int x, int y, vector<vector<char>> &v, vector<set<int>> &adj, map<pair<int,int>,int> &weight) {
    int r = v.size(), c = v[0].size();
    vector<pair<int,int>> neighbours = get_neighbours(x, y, '-', '|', v);
    for (auto &p : neighbours) {
        if (p.first == x) { // same row
            adj[r * c + p.first * c + p.second].insert(x * c + y);
            weight[{r * c + p.first * c + p.second, x * c + y}] = WEIGHT_MAX;
        }
        if (p.second == y) {
            adj[2 * r * c + p.first * c + p.second].insert(x * c + y);
            weight[{2 * r * c + p.first * c + p.second, x * c + y}] = WEIGHT_MAX;
        }
    }   
    return;
}

void sherlock(int t) {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> v(r, vector<char> (c));
    int mirror = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            if (v[i][j] == '/' || v[i][j] == '\\') {
                mirror++;
            }
        }
    }
    if (mirror) {
        exit(0);
    }
    vector<set<int>> adj(3 * r * c + 2);
    map<pair<int,int>,int> weight;
    // No beam  shooter destroyed
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {    
            if (v[i][j] == '-' || v[i][j] == '|') {
                int x = protect(i, j, v, adj, weight);
                if (x == 0) {
                    cout << "Case #" << t << ": IMPOSSIBLE" << endl;
                    return;
                }
            }
        }
    }
    // Every empty cell is lighted
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {    
            if (v[i][j] == '.') {
                light(i, j, v, adj, weight);
            }
        }
    }
    int e = 0;
    int source = 3 * r * c, sink = 3 * r * c + 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '.') {
                adj[i * c + j].insert(sink);
                weight[{i * c + j, sink}] = 1; 
                e++;
            }
            if (v[i][j] == '-' || v[i][j] == '|') {
                adj[source].insert(i * c + j);
                weight[{source, i * c + j}] = WEIGHT_MAX;
            }
        }
    }
    // MAX FLOW
    int flow = 0;
    while (find_path(source, sink, adj, weight)) {
        flow++;
    }
    // cout << flow << endl;
    if (flow < e) {
        cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        return;
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '-' || v[i][j] == '|') {
                int z = i * c + j;
                if (adj[r * c + z].count(z)) {
                    v[i][j] = '-';
                }
                else if (adj[2 * r * c + z].count(z)) {
                    v[i][j] = '|';
                }
                else if (adj[z].count(r * c + z)) {
                    v[i][j] = '-';
                }
                else {
                    v[i][j] = '|';
                }
            }
        }
    }
    cout << "Case #" << t << ": POSSIBLE" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
