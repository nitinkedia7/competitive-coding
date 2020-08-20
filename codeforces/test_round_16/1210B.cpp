#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int MAXN = 7001;
const int MAXS = 60;

int n;
int a[MAXN][MAXS], b[MAXN];

bool is_subset(int x, int y) {
    for (int i = 0; i < MAXS; i++) {
        if (a[x][i] == 1 && a[y][i] == 0) return false;
    }
    return true;
}

void sherlock(int t) {
    cin >> n;
    vector<pair<ll,int>> v(n); 
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i] = {x, i};
        for (int j = 0; j < MAXS; j++) {
            a[i][j] = x % 2;
            x /= 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(all(v));
    vector<int> done(n, 0);
    for (int i = 1; i < n; i++) {
        if (v[i].first == v[i-1].first) {
            done[v[i].second] = 1;
            done[v[i-1].second] = 1;        
        }
    }
    for (int i = 0; i < n; i++) {
        if (done[i]) continue;
        for (int j = 0; j < n; j++) {
            if (done[j] && is_subset(i, j)) {
                done[i] = 1;
                break;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (done[i]) {
            // cout << i << " ";
            ans += b[i];
        }
    }
    // cout << endl;
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
