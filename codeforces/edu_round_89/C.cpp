#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int x;
    map<int,int> m0, m1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            int d = i + j;
            if (x) {
                m1[d]++;
            }
            else {
                m0[d]++;
            }   
        }
    }        
    int ans = 0;
    for (int d = 0; d < n + m - 1; d++) {
        // cout << m0[d] << " " << m1[d] << endl;
        int rd = n + m - 2 - d;
        if (d < rd) {
            ans += min(m0[d] + m0[rd], m1[d] + m1[rd]);
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
