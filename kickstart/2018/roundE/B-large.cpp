#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp(vector<vector<int>> &opt, vector<int> &v0, vector<int> &v1, int i, int k) {
    if (i < 0 && k == 0) return 1;
    if (i < 0 || k < 0) return 0;
    if (opt[i][k] != -1) return opt[i][k];
    int ans = 0;
    ans += dp(opt, v0, v1, i-1, k-v0[i]);
    ans += dp(opt, v0, v1, i-1, k-v1[i]);
    opt[i][k] = ans;
    return opt[i][k];
}

int main() {
    int t, n, m, p;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> m >> p;
        vector<string> pref(n+m);
        for (int i = 0; i < n+m; i++) {
            cin >> pref[i];
        }
        vector<int> v0(p, 0), v1(p, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                if (pref[i][j] == '0') v0[j]++;
                else v1[j]++; 
            }
        } 
        // int mi = 0;
        // for (int i = 0; i < p; i++) {
        //     mi += min(v0[i], v1[i]);
        // }  
        // cout << mi << endl;
        unordered_map<int, int> umap;
        for (int i = n; i < n+m; i++) {
            int cost = 0;
            for (int j = 0; j < p; j++) {
                if (pref[i][j] == '0') cost += v1[j];
                else cost += v0[j];
            }
            umap[cost] -= 1;
        }
        // for (int i = 0; i < n*p+1; i++) cout << i << ", " << umap[i] << "   ";
        // cout << endl;
        vector<vector<int>> opt(p, vector<int> (n*p+1, -1));
        // vector<int> v(p);
        // for (int i = 0; i < p; i++) v[i] = abs(v0[i]-v1[i]);

        for (int i = 0; i < n*p+1; i++) {
            umap[i] += dp(opt, v0, v1, p-1, i);
            if (umap[i] > 0) {
                // for (int i = 0; i < n*p+1; i++) cout << i << ", " << umap[i] << "   ";
                // cout << endl;
                // cout << umap[i] << endl;
                cout << "Case #" << c << ": " << i;
                cout << endl;
                break;
            }
        }
    }
}