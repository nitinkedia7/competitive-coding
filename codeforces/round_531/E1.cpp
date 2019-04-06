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
    ll ans = 1;
    vector<int> pl(n, l[0]);
    for (int i = 1; i < n; i++) pl[i] = max(l[i], pl[i-1]);
    for (int i = 0; i < n; i++) {
        if (i == pl[i] && i != n-1) {
            ans = 2 * ans;
            ans = ans % mod;
        } 
    }
    cout << ans << endl;
    return 0;
}