#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    char x;
    vector<vector<int>> adj(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            adj[i][j] = x - '0';
            if (x == '0' && i != j) adj[i][j] = 1000;
        }
    }
    // APSP
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int c = adj[i][k] + adj[k][j];
                if (adj[i][j] > c) {
                    adj[i][j] = c;
                }
            }
        }
    }
    // print(adj, n);
    int m;
    cin >> m;
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
    }
    int d = 0, u = 0;
    vector<int> ans = {p[0]};
    for (int i = 1; i <= m; i++) {
        d++;
        if (i == m || d > adj[p[u]][p[i]]) {
            ans.push_back(p[i-1]);
            d = 1;
            u = i - 1;
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    } 
    cout << endl;
}   
