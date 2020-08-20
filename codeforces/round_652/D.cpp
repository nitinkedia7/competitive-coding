#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N = 2000001;

vector<ll> head(N), not_head(N);

void sherlock(int t) {
    int n;
    cin >> n;
    cout << (4 * max(head[n], not_head[n])) % MOD << endl;
}

ll get_head(int l) {
    if (l <= 2) return 0;
    return (1 + not_head[l-1] + 2 * not_head[l-2]) % MOD;  
}

ll get_not_head(int l) {
    if (l <= 2) return 0;
    ll x = max(head[l-1], not_head[l-1]) % MOD;
    ll y = (2 * max(head[l-2], not_head[l-2])) % MOD;
    return (x + y) % MOD; 
}

void police() {
    for (int i = 1; i < N; i++) {
        head[i] = get_head(i);
        not_head[i] = get_not_head(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    police();
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
