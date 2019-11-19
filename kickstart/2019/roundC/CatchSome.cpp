#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// #define C 1001

void sherlock(int t) {
    int C = 1001;
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> dogs(n); // pos, color
    for (int i = 0; i < n; i++) {
        cin >> dogs[i].first;
    }    
    for (int i = 0; i < n; i++) {
        cin >> dogs[i].second;
    }
    sort(dogs.begin(), dogs.end());
    vector<vector<int>> adj(C);
    for (int i = 0; i < n; i++) {
        int c = dogs[i].second;
        adj[c].push_back(dogs[i].first);
    }

    dogs.clear();    
    int opt[C][k + 1][2];

    opt[0][0][0] = 0;
    opt[0][0][1] = INT_MAX;
    for (int i = 1; i <= k; i++) {
        opt[0][i][0] = INT_MAX;
        opt[0][i][1] = INT_MAX;
    }

    for (int i = 1; i < C; i++) {
        for (int j = 0; j <= k; j++) {
            int ans = INT_MAX;
            for (int l = 0; l <= (int) adj[i].size() && j - l >= 0; l++) {
                if (opt[i-1][j - l][0] != INT_MAX) {
                    ans = min(ans, opt[i-1][j - l][0] + (l == 0 ? 0 : 2 * adj[i][l-1]));
                }
            }
            opt[i][j][0] = ans;
            ans = INT_MAX;
            for (int l = 0; l <= (int) adj[i].size() && j - l >= 0; l++) {
                if (opt[i-1][j - l][1] != INT_MAX) {
                    ans = min(ans, opt[i-1][j - l][1] + (l == 0 ? 0 : 2 * adj[i][l-1]));
                }
            }
            int ans2 = INT_MAX;
            for (int l = 1; l <= (int) adj[i].size() && j - l >= 0; l++) {
                if (opt[i-1][j - l][0] != INT_MAX) {
                    ans = min(ans, opt[i-1][j - l][0] + adj[i][l-1]);
                }
            }
            opt[i][j][1] = min(ans, ans2);
        }
    }
    // for (int i = 0; i <= 5; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << opt[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i <= 5; i++) {
    //     for (int j = 0; j <= k; j++) {
    //         cout << opt[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
    adj.clear();
    // memset(opt, 0, C * (k + 1) * 2);
    cout << "Case #" << t << ": " << opt[C-1][k][1] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}