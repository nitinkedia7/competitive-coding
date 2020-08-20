#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;

int pow2(ll b) {
    int c = 0;
    while (b % 2 == 0) {
        b /= 2;
        c++;
    }
    return c;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        mp[pow2(b[i])]++;
    }
    int p = 0;
    for (auto &[x, y] : mp) {
        // cout << x << " " << y << endl;
        if (y > mp[p]) {
            p = x;
        }
    }   
    cout << n - mp[p] << endl;
    for (int i = 0; i < n; i++) {
        if (p != pow2(b[i])) {
            cout << b[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}