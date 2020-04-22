#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<pair<int,int>> edges;
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        edges.insert({u, v});
        edges.insert({v, u});
    }
    vector<int> mem(n, -1);
    u = 0;
    for (int i = 0; i < n; i++) {
        if (edges.find({i, u}) == edges.end() && edges.find({u, i}) == edges.end()) {
            mem[i] = 1;
        }
    }    

    for (int i = 0; i < n; i++) {
        if (mem[i] == -1) {
            u = i;
            break;
        }
        if (i == n - 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (edges.find({i, u}) == edges.end() && edges.find({u, i}) == edges.end()) {
            if (mem[i] != -1) {
                cout << -1 << endl;
                return 0;
            }
            mem[i] = 2;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mem[i] == -1) {
            u = i;
            break;
        }
        if (i == n - 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (edges.find({i, u}) == edges.end() && edges.find({u, i}) == edges.end()) {
            if (mem[i] != -1) {
                cout << -1 << endl;
                return 0;
            }
            mem[i] = 3;
        }
    }
    ll c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
        if (mem[i] == -1) {
            cout << -1 << endl;
            return 0;
        }
        else if (mem[i] == 1) {
            c1++;
        }
        else if (mem[i] == 2) {
            c2++;
        }
        else {
            c3++;
        }
    }
    ll m1 = c1 * c2 + c2 * c3 + c3 * c1;
    if (m1 != m) {
        cout << -1 << endl;
        return 0;
    }
    for (auto p : edges) {
        u = p.first;
        v = p.second;
        if (mem[u] == mem[v]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mem[i] << " ";
    }
    cout << endl;
    return 0;
}