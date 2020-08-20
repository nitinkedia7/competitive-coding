#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> cost(n, 0);
    for (int i = n-2; i >= 0; i--) {
        if (i == n-2 || s[i] != s[i+1]) {
            if (s[i] == 'A') {
                cost[i] = a + cost[i+1];
            }
            else cost[i] = b + cost[i+1];
        }
        else {
            cost[i] = cost[i+1];
        }
    }    
    for (int i = 0; i < n; i++) {
        if (cost[i] <= p) {
            cout << i+1 << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
