#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(c) c.begin(),c.end()
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> l(n);
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++) {
        umap[v[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        l[i] = umap[v[i]];
        // cout << l[i] << ", ";
    }
    // cout << endl;
    ll ans = 1;
    int i = 0, c = n;
    while (i < n) {
        assert(i < n);
        // cout << i << endl;
        if (i != 0) {
            ans = ans * 2;
            ans = ans % mod;
        }
        int r = l[i], m = l[i];
        while (true) {
            m = r;
            for (int j = i; j <= r; j++) {
                m = max(m, l[j]);
            }
            // cout << "m " << m << endl;
            // cout << "r " << r << endl;
            if (m == r) {
                i = r+1;
                break;
            }
            else {
                i = r;
                r = m;
            }
        }
    }
    cout << ans << endl;
    return 0;

}