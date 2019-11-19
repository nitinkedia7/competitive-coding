#include <bits/stdc++.h>
using namespace std;

void dfs_visit(int u, int c, vector<vector<int>> &adj, vector<int> &color, vector<int> &vis, bool &doable) { 
    vis[u] = 1;
    color[u] = c;
    c = !c;
    for (auto v : adj[u]) {
        if (vis[v] == 0) {
            dfs_visit(v, c, adj, color, vis, doable);
        }
        else if (color[v] == color[u]) {
            doable = false;
        }
    }
    vis[u] = 2;
}

void sherlock() {
    int n, l, r, sp;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>l>>r>>sp;
        v[i][0]=l;
        v[i][1]=r;
        v[i][2]=sp;
    }
    vector<vector<int>> graph(n);
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i][2]==v[j][2]){
                if(v[i][0]>v[j][1] || v[i][1]<v[j][0]){
                    continue;
                }
                else{
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
    }
    vector<int> vis(n), color(n);
    bool doable = true;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs_visit(i, 0, graph, color, vis, doable);
        }
    }
    cout << (doable ? "YES" : "NO") << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sherlock();
    }
    return 0;
}