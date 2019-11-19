#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll base = 1019;

ll getKey(vector<int> &v, int mask) {
    ll key = 0;
    for (int i = 0; i < v.size(); i++) {
        if (mask & (1 << i)) {
            key = key * base + v[i];
        }
    }
    return key;
} 

void sherlock(int t) {
    int n, s;
    cin >> n >> s;
    unordered_map<ll, int> umap;
    vector<vector<int>> sset(n);
    int sid;
    ll key;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s; j++) {
            cin >> sid;
            sset[i].push_back(sid);    
        }
        sort(sset[i].begin(), sset[i].end());
        key = getKey(sset[i], (1 << s) - 1);
        // cout << key << endl;
        umap[key]++;
    }
    // mi: number of persons who can train i'th emp
    ll ans = 0, mentor;
    for (int i = 0; i < n; i++) {
        mentor = n;
        s = sset[i].size();
        s = (1 << s) - 1;
        for (int j = 1; j <= s; j++) {
            key = getKey(sset[i], j);
            mentor -= umap[key];
        }
        ans += mentor;
    }
    cout << "Case #" << t << ": " << ans << endl; 
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}