#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, al, ar;
    cin >> n >> al >> ar;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = i+1;
    }
    queue<int> ans;
    ll l = 1, nl;
    for (int i = 0; i < n-1; i++) {
        nl = l + 2 * (n - 1 - i);
        if ((al <= l && ar >= l) || (l <= al && al < nl)) {
            vector<int> x;
            for (int j = i+1; j < n; j++) {
                x.push_back(v[i]);
                x.push_back(v[j]);
            }
            for (ll y = l; y < nl; y++) {
                if (y >= al && y <= ar) {
                    ans.push(x[y-l]);
                }
            }
            x.clear();
        }
        l = nl;
    }
    if (ar == n * (n-1) + 1) {
        ans.push(v[0]);
    }    
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}