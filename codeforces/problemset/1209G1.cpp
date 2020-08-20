#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    map<int,int> mpr, count;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mpr[v[i]] = i;
        count[v[i]]++;
    }    
    int ans = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        int r = mpr[v[i]];
        int maxc = count[v[i]];
        while (j <= r) {
            r = max(r, mpr[v[j]]);
            maxc = max(maxc, count[v[j]]);
            j++;
        } 
        ans += (j - i - maxc);
        i = j;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
