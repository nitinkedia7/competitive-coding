#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> count_col(int n, int k, vector<vector<char>> &v) {
    vector<vector<int>> prefix(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'B')
                prefix[i][j] = 1;
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            prefix[i][j] += prefix[i-1][j];
        }
    }
    // can query count in O(1)
    vector<vector<int>> ans(n-k+1, vector<int> (n-k+1, 0));
    for (int i = 0; i < n-k+1; i++) {
        vector<int> row(n, 0);
        for (int j = 0; j < n; j++) {
            int b1 = prefix[i+k-1][j] - (i > 0 ? prefix[i-1][j] : 0);
            int b2 = prefix[n-1][j];
            if (b1 == b2 && b2 > 0) {
                row[j] = 1;
            } 
        }
        for (int j = 1; j < n; j++) {
            row[j] += row[j-1];
        }
        for (int j = 0; j < n - k + 1; j++) {
            ans[i][j] = row[j+k-1] - (j > 0 ? row[j-1] : 0);
        }
        row.clear();
    }
    prefix.clear();
    return ans;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<vector<char>> v(n, vector<char> (n)), vt(n, vector<char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vt[i][j] = v[j][i];
        }
    }
    // print2d(v);
    // cout << endl;
    // print2d(vt);
    int x = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (v[i][j] == 'B') break;
        }
        if (j == n) x++;
    }
    // cout << x << endl;
     for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (vt[i][j] == 'B') break;
        }
        if (j == n) x++;
    }
    // cout << x << endl;
    
    vector<vector<int>> ans = count_col(n, k, v);
    // print2d(ans);
    vector<vector<int>> anst = count_col(n, k, vt);
    
    int z = 0;
    for (int i = 0; i < n-k+1; i++) {
        for (int j = 0; j < n-k+1; j++) {
            z = max(z, x + ans[i][j] + anst[j][i]);
        }
    }
    cout << z << endl;
    v.clear();
    vt.clear();
    ans.clear();
    anst.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}