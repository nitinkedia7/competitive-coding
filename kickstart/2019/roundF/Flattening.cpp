#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void calcR(vector<int> &v, vector<int> &R) {
    int n = v.size();
    set<pair<int,int>, greater<pair<int,int>>> count;
    unordered_map<int,int> umap; // A[i] -> count
    for (int i = 0; i < n; i++) {
        count.clear();
        umap.clear();
        for (int j = i; j < n; j++) {
            int pc = umap[v[j]];
            umap[v[j]]++;
            count.erase({pc, v[j]});
            count.insert({pc + 1, v[j]});
            R[i * n + j] = (j - i + 1) - count.begin()->first;
            assert(R[i * n + j] >= 0);
        }
    }
    // print(R);
    // cout << endl;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> R(n * n);
    calcR(v, R);
    vector<vector<int>> opt(n, vector<int> (k + 1));
    for (int i = 0; i < n; i++) {
        opt[i][0] = R[i];
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 1; i < n; i++) {
            int c = INT_MAX;
            for (int l = 0; l < i; l++) {
                c = min(c, opt[l][j-1] + R[(l+1) * n + i]);
            }
            opt[i][j] = c;
        }
    }
    // for (int j = 0; j <= k; j++) {
    //     for (int i = 0; i < n; i++) {
    //         cout << opt[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "Case #" << t << ": " << opt[n - 1][k] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}