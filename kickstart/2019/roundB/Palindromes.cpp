#include <bits/stdc++.h>
using namespace std;

void sherlock(int t) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> adj(26);
    for (int i = 0; i < n; i++) {
        adj[s[i] - 'A'].push_back(i);
    }    
    // for (int i = 0; i < 3; i++) {
    //     cout << i + 'A' << ": ";
    //     for (auto j : adj[i]) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int yes = 0;
    int l, r;
    vector<int>::iterator ub, lb;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        l--;
        r--;
        // cout << l << "," << r << endl;
        int odd = (r - l + 1) % 2;
        int oddseen = 0;
        for (int j = 0; j < 3; j++) {
            ub = upper_bound(adj[j].begin(), adj[j].end(), r);
            lb = lower_bound(adj[j].begin(), adj[j].end(), l);
            // cout << ub - adj[j].begin() << " ";
            // cout << lb - adj[j].begin() << endl;
            int c = ub - lb;
            // cout << c << " ";
            oddseen += c % 2;
        }
        // cout << endl;
        if (oddseen == odd) {
            // cout << l + 1 << " " << r + 1 << endl;
            yes++;
        }
        // else {
        //     cout << "Rejected " << l + 1 << " " << r + 1 << " " << oddseen << " " << odd << endl;
        // }
    }
    cout << "Case #" << t << ": " << yes << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}