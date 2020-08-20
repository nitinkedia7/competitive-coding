#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;


void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), c(k);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < k; i++) cin >> c[i];
    sort(all(v), greater<int>());
    int off = c[k-1];
    set<pair<int,int>> s;
    vector<vector<int>> adj(n);
    int j = 0;
    int i = 0;
    while (i < n) {
        int minf = off;
        if (!s.empty()) {
            minf = s.begin()->first;
        } 
        int remc = off - minf;
        if (remc > 0) {
            int x = s.begin()->second;
            adj[x].push_back(i);
            s.erase(s.begin());
            s.insert({off - remc + 1, x});
        } 
        else {
            adj[j].push_back(i);
            s.insert({1, j});
            j++;
        }
        if (i+1 < n && v[i+1] < v[i]) {
            off = c[v[i+1] - 1];
        }
        i++;
    }
    cout << j << endl;
    for (int i = 0; i < j; i++) {
        cout << adj[i].size() << " ";
        for (auto x : adj[i]) {
            cout << v[x] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}