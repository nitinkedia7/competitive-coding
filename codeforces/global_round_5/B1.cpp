#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int r, unordered_map<int,int> &umap, set<int> &f) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge(v, l, m, umap, f);
    merge(v, m+1, r, umap, f);
    int i = l, j = m + 1;
    vector<int> temp;
    int daga = INT_MAX;
    while (i <= m && j <= r) {
        if (umap[v[i]] < umap[v[j]]) {
            temp.push_back(v[i]);
            i++;
        }   
        else { 
            if (daga == INT_MAX) daga = i;
            temp.push_back(v[j]);
            j++;
        }
    }
    while (i <= m) {
        if (daga == INT_MAX) daga = i;
        temp.push_back(v[i]);
        i++;
    }
    while (j <= r) {
        temp.push_back(v[j]);
        j++;
    }
    for (int i1 = daga; i1 <= m; i1++) {
        f.insert(v[i1]);
    }
    for (int i = l; i <= r; i++) {
        v[i] = temp[i-l];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> entry(n), exit(n);
    for (int i = 0; i < n; i++) cin >> entry[i];
    for (int i = 0; i < n; i++) cin >> exit[i];

    unordered_map<int,int> umap;
    for (int i = 0; i < n; i++) {
        umap[entry[i]] = i;
    }
    set<int> f;
    merge(exit, 0, n-1, umap, f);
    // for (auto x : f) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << exit[i] << " ";
    // }
    // cout << endl;
    cout << f.size() << endl;
}