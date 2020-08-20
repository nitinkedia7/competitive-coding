#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int f(int x, int p, int n, vector<int> &a) {
    // cout << x << endl;
    int j = 0;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        while (j < n && a[j] <= x + i) {
            j++;
        }
        // cout << i << " " << j << endl;
        ans *= max(0, j - i);
        ans %= p;
    }
    return ans;
}

void sherlock(int t) {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    sort(all(a));
    vector<int> ans;
    for (int x = 0; x < a[n-1]; x++) {
        if (f(x, p, n, a) != 0) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
