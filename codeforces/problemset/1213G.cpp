#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int find(int x, vector<ll> &par) {
    while (x != par[x]) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

ll join(int x, int y, vector<ll> &par, vector<ll> &rank) {
    int px = find(x, par), py = find(y, par);
    ll ans = rank[px] * 1LL * rank[py];
    if (rank[px] > rank[py]) {
        par[py] = px;
        rank[px] += rank[py];
    }
    else {
        par[px] = py;
        rank[py] += rank[px]; 
    }
    return ans;
}

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<tuple<int,int,int>> e(n-1);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        e[i] = {w, u, v};
    }
    sort(all(e));
    vector<pair<int,int>> q(m);
    for (int i = 0; i < m; i++) {
        cin >> w;
        q[i] = {w, i};
    }
    sort(all(q));
    vector<ll> par(n), rank(n);
    iota(all(par), 0);
    fill(all(rank), 1);
    int j = 0;
    ll ans = 0;
    vector<ll> qa(m);
    for (int i = 0; i < m; i++) {
        while (j < n-1 && get<0> (e[j]) <= q[i].first) {
            ans += join(get<1> (e[j]), get<2> (e[j]), par, rank);
            j++;
        }
        qa[q[i].second] = ans;
    }
    for (int i = 0; i < m; i++) {
        cout << qa[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
