#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
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
    vector<ll> p(n+1);
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i-1] + v[i-1];
    }
    map<ll,int> m;
    int i = 0, j = 1;
    m[p[0]] = 0;
    ll ans = 0;
    while (j <= n) {
        // expansion
        while (j <= n && m.find(p[j]) == m.end()) {
            m[p[j]] = j;
            j++;
        }
        // contraction
        int x = (j == n + 1 ? n + 1 : m[p[j]] + 1);
        while (i < x) {
            ans += (j - i - 1);
            m.erase(p[i]);
            i++;
        }
    }    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}