#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }   
    ll ans = 0;
    vector<int> vm(n);
    for (int i = 0; i < 25; i++) {
        int x = (1 << i);
        int x2 = 2 * x;
        int x4 = 4 * x;
        for (int j = 0; j < n; j++) {
            vm[j] = v[j] & (x2 - 1);
        }
        sort(all(vm));
        // print(vm);
        int l = n-1, r = n-1; // (l, r]
        ll b = 0;
        for (int j = 0; j < n; j++) {
            // if (l <= j) l = j;
            // if (r <= j) r = j;
            while (l >= 0 && vm[j] + vm[l] >= x) {
                l--;
            }
            while (r >= 0 && vm[j] + vm[r] >= x2) {
                r--;
            }
            if (l < r) {
                b += (r - l);
                if (j > l && j <= r) b--;
            }
            // cout << j << " " << l << "," << r << endl;
        }

        l = n-1, r = n-1; // [l, r]
        for (int j = 0; j < n; j++) {
            // if (l <= j) l = j;
            // if (r <= j) r = j;
            while (l >= 0 && vm[j] + vm[l] >= x + x2) {
                l--;
            }
            while (r >= 0 && vm[j] + vm[r] >= x4 - 1) {
                r--;
            }
            if (l < r) {
                b += (r - l);
                if (j > l && j <= r) b--;
            }
            // cout << j << " " << l << "," << r << endl;
        }
        b >>= 1;
        // cout << b << endl;
        if (b & 1) {
            ans |= x;
        }
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
