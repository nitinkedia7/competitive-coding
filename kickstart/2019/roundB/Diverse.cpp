#include <bits/stdc++.h>
using namespace std;

void build(vector<pair<int,int>> &v, int n) {
    int l, r;
    for (int i = n - 1; i > 0; i--) {
        l = 2 * i;
        r = 2 * i + 1;
        v[i].first = v[l].first + v[r].first;
        v[i].second = max(v[l].second, v[l].first + v[r].second);
    }
}

void update(vector<pair<int,int>> &v, int n, int p, int x) {
    p += n;
    v[p] = {x, x};
    p /= 2;
    int l, r;
    while (p > 0) {
        l = 2 * p;
        r = 2 * p + 1;
        v[p].first = v[l].first + v[r].first;
        v[p].second = max({v[l].second, v[l].first + v[r].second, v[p].first});
        p /= 2;
    }
}

void print(vector<pair<int,int>> &v, int n) {
    for (int i = 1; i < 2 * n; i++) {
        cout << v[i].first << "," << v[i].second << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int T = 100000;
    int n, s;
    cin >> n >> s;
    vector<int> type(n);
    vector<vector<int>> adj(T + 1);
    for (int i = 0; i < n; i++) {
        cin >> type[i];
        adj[type[i]].push_back(i);
    }
    int N = 1;
    while (N < n) {
        N += N;
    }
    vector<pair<int,int>> v(2 * N, {0, 0});
    vector<int> end(T + 1, n);
    for (int t = 1; t <= T; t++) {
        for (int j = 0; j < adj[t].size(); j++) {
            int p = adj[t][j];
            if (j < s) v[p + N] = {1, 1};
            else if (j == s) {
                end[t] = j;
                v[p + N] = {-s, -s};
            } 
            else {
                v[p + N] = {0, 0};
            }
        }
    }
    build(v, N);
    int maxpref = 0;
    for (int i = 0; i < n; i++) {
        // contend
        // print(v, N);
        maxpref = max(maxpref, v[1].second);        
        // update
        int t = type[i];
        int j1 = end[t] < adj[t].size() ? adj[t][end[t]] : n;
        int j2 = end[t] + 1 < adj[t].size() ? adj[t][end[t] + 1] : n;
        end[t]++;

        update(v, N, i, 0);
        if (j1 < n) update(v, N, j1, 1);
        if (j2 < n) update(v, N, j2, -s);
    }
    cout << "Case #" << t << ": " << maxpref << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}