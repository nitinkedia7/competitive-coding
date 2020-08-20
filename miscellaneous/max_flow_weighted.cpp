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