#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int find(int x, vector<int> &parent) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

bool join(int x, int y, vector<int> &parent, vector<int> &rank) {
    int px = find(x, parent);
    int py = find(y, parent);
    if (px == py) return false;
    parent[px] = parent[py];
    // if (rank[px] > rank[py]) {
    //     parent[py] = px;
    //     rank[px] += rank[py];
    // }
    // else {
    //     parent[px] = py;
    //     rank[py] += rank[px]; 
    // }
    return true;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    ll x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = {x, y};
    }
    // set<tuple<ll,int,int>> ms;
    set<pair<ll,pair<int,int>>> ms;
    ll c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        ms.insert({c, {0, i+1}});
    }
    vector<ll> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ll d = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            d *= (k[i] + k[j]);
            ms.insert({d, {i+1, j+1}});
        }
    }
    vector<int> parent(n+1), rank(n+1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
    ll d;
    int a, b;
    vector<int> ps;
    vector<pair<int,int>> w;
    ll cost = 0;
    int f = n+1;
    while (f > 1 && !ms.empty()) {
        d = ms.begin()->first;
        a = ms.begin()->second.first;
        b = ms.begin()->second.second;
        ms.erase(ms.begin());
        if (join(a, b, parent, rank)) {
            f--;
            cost += d;
            if (a == 0) {
                ps.push_back(b);
            }
            else {
                w.push_back({a, b});
            }
        }
    }
    cout << cost << endl;
    cout << ps.size() << endl;   
    for (int i = 0; i < ps.size(); i++) cout << ps[i] << " ";
    cout << endl;
    cout << w.size() << endl;   
    for (int i = 0; i < w.size(); i++) cout << w[i].first << " " << w[i].second << endl;
    ps.clear();
    w.clear();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}