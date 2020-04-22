#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool cut(vector<vector<char>> &v, int r, int c, int h, int l) {
    vector<int> row(r, 0);
    int cc = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '@') {
                row[i]++;
                cc++;
            }
        }
    }
    if (cc % ((h + 1) * (l+1)) != 0) return false;
    int i = 0, ccs;
    vector<int> ss;
    for (int s = 0; s < h + 1; s++) {
        ccs = cc / (h + 1);
        while (ccs > 0 && i < r) {
            ccs -= row[i];
            ss.push_back(s);
            i++;
        }
        if (ccs != 0) return false;
    }
    for (; i < r; i++) {
        ss.push_back(h);
    }
    assert(ss.size() == r);
    // print(ss);
    // cout << cc / ((h + 1) * (l+1)) << endl;
    // Now try to cut vertically
    vector<vector<int>> w(h+1, vector<int> (c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '@') w[ss[i]][j]++;
        }
    }
    // print2d(w);
    vector<int> v1(h + 1, 0);
    for (int s = 0; s < l+1; s++) { // for each vertical slice
        // each row moves it's j forward
        for (int i = 0; i < h + 1; i++) {
            int ccs = cc / ((h + 1) * (l+1));
            while (ccs > 0 && v1[i] < c) {
                ccs -= w[i][v1[i]];
                v1[i]++;
            }
            if (ccs != 0) return false;
        }    
        // print(v1);
        int J = *max_element(v1.begin(), v1.end());
        for (int i = 0; i < h + 1; i++) {
            int ccs = 0;
            while (v1[i] < J) {
                ccs += w[i][v1[i]];
                v1[i]++;
            }
            if (ccs != 0) return false;
        }
        // print(v1);
        // cout << endl;
    }
    return true;
}

void sherlock(int t) {
    int r, c, h, v;
    cin >> r >> c >> h >> v;
    vector<vector<char>> v1(r, vector<char> (c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v1[i][j];
        }
    }
    bool can_cut = cut(v1, r, c, h, v);
    cout << "Case #" << t << ": ";
    if (can_cut) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}