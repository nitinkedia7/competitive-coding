#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;


void sherlock(int t) {
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) s += a[i];
    }
    ll in = min(m - a[0], s);
    cout << a[0] + in << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}