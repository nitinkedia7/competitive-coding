#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void good(int n, int h, vector<int> &v1) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m = 1 << n;
    ll x;
    for (int s = 0; s < m; s++) {
        x = 0;
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                x += v[i];
            }
        }
        if (x >= h) v1[s] = 1;
    }
    return;
}

int unset(int x, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if ((x & (1 << i)) == 0) c++;
    }
    return c;
}

void print(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    // cout << endl;
}

void print1(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n, h;
    cin >> n >> h;
    int m = (1 << n) - 1;
    vector<int> v1(m + 1), v2(m + 1);
    good(n, h, v1);
    good(n, h, v2);
    // print1(v1);
    // print1(v2);
    vector<ll> supermasks(m + 1);
    supermasks[m] = v1[m];
    vector<vector<int>> opt(m + 1, vector<int> (n + 1));
    for (int i = m - 1; i >= 0; i--) {
        int k = unset(i, n);
        int c = 0, j1;        
        for (int j = n - 1; j >= 0; j--) {
            if ((i & (1 << j))) continue;
            if (c == 0) {
                opt[i][k] = v1[i];
            }
            else {
                opt[i][k-c] = opt[i][k - c + 1];
                opt[i][k-c] += opt[i | (1 << j1)][k - c];
            }
            c++;
            j1 = j;
        }
        supermasks[i] = v1[i];
        for (int j = 1, p = 0; j <= m; j <<= 1) {
            if (i & j) continue;
            if (p == 0) {
                supermasks[i] += supermasks[i | j];
            }
            else {
                supermasks[i] += opt[i | j][p];
            }
            p++;
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     cout << supermasks[i] << " ";   
    // }
    // cout << endl;
    // print(opt);
    ll ans = 0;
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] == 0) continue;
        int x = m - i;
        ans += supermasks[x]; 
    }
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}