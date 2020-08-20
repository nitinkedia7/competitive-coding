#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<string> enc = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void can_convert(string &s, vector<int> &v) {
    assert(v.size() == 10);
    for (int i = 0; i < 10; i++) {
        int k = 0;
        for (int j = 0; j < 7; j++) {
            if (s[j] == '1' && enc[i][j] == '0') {
                k = -1;
                break;
            }
            if (s[j] == '0' && enc[i][j] == '1') {
                k++;
            }
        }
        v[i] = k;
    }
    return;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int> (10, -1));
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        can_convert(s, v[i]);
    }
    vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
    vector<vector<int>> par(n+1, vector<int> (k+1, -1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        // repairing (n-i)th digit
        int x = n-i;
        for (int j = 0; j <= k; j++) {
            int b = 0;
            for (int d = 9; d >= 0; d--) {
                if (v[x][d] == -1) continue;
                if (j - v[x][d] >= 0) {
                    b = b || dp[i-1][j-v[x][d]];
                    if (dp[i-1][j-v[x][d]] == 1) {
                        par[i][j] = d;
                        break;
                    }
                }
            }
            dp[i][j] = b;
        }
    }
    // print2d(dp);
    // cout << endl;
    // print2d(par);
    if (dp[n][k] == 0) {
        cout << -1 << endl;
        return;
    }
    int j = k;
    for (int i = n; i > 0; i--) {
        int x = n-i;
        cout << par[i][j];
        j = j - v[x][par[i][j]]; 
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}