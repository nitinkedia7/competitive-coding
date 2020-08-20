#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool is_similar(int n, int m, string &s, vector<string> &v) {
    for (int i = 0; i < n; i++) {
        int d = 0;
        for (int j = 0; j < m; j++) {
            if (s[j] != v[i][j]) d++;
            if (d > 1) return false;
        }
    }
    return true;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string s = v[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 26; j++) {
            s[i] = ('a' + j);
            if (is_similar(n, m, s, v)) {
                cout << s << endl;
                return;
            }
        }
        s[i] = v[0][i];
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
