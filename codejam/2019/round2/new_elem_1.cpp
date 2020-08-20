#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

struct comp_frac {
    bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b) const {
        return (a.first * b.second < a.second * b.first);
    }
};

vector<pair<ll,ll>> v(300);
unordered_map<pair<ll,ll>, vector<pair<int,int>>, hash_pair> mpg, mpl;
set<pair<ll,ll>, comp_frac> s;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void process(int i, int j, ll a, ll b, ll c, ll d) {
    // (a, b) > (c, d)
    // ll a = v[i].first, b = v[i].second, c = v[j].first, d = v[]
    ll g, x, y;
    if (a > c) {
        if (b >= d) {
            mpg[{0, 1}].push_back({i, j});
            // s.insert({0, 1});
        }
        else {
            g = gcd(d-b, a-c);
            x = (d - b) / g;
            y = (a - c) / g;
            mpg[{x, y}].push_back({i, j}); 
            s.insert({x, y});

        }
    }
    else if (a == c) {
        if (b > d) {
            mpg[{0, 1}].push_back({i, j});
            // s.insert({0, 1});
        }
    }
    else { // a < c
        if (b > d) {
            g = gcd(b - d, c - a);
            x = (b - d) / g;
            y = (c - a) / g;
            mpl[{x,y}].push_back({i, j}); 
            s.insert({x, y});
        }
    }
}

void dfs(int u, vector<unordered_set<int>> &adj, vector<int> &vis, bool &exist) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (vis[v] == 0) {
            dfs(v, adj, vis, exist);
            if (exist == false) return;
        }
        else if (vis[v] == 1) {
            exist = false;
        }
    }
    vis[u] = 2;
}

void print() {
    for (auto x : mpl) {
        cout << x.first.first << "," << x.first.second << ": ";
        for (auto p : x.second) {
            cout << p.first << "," << p.second << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (auto x : mpg) {
        cout << x.first.first << "," << x.first.second << ": ";
        for (auto p : x.second) {
            cout << p.first << "," << p.second << " ";
        }
        cout << endl;
    }
}

void sherlock(int t) {
    int n;
    cin >> n;
    // v.clear();
    // v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    // find conditions
    mpg.clear();
    mpl.clear();
    s.clear();
    s.insert({0, 1});
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            process(i, j, v[i].first, v[i].second, v[j].first, v[j].second);
            process(j, i, v[j].first, v[j].second, v[i].first, v[i].second);
        }
    }
    // print();
    // build graph
    vector<unordered_set<int>> adj(n);
    for (auto x : mpl) {
        for (auto p : x.second) {
            adj[p.first].insert(p.second);
        }
    }
    // iterate every fraction
    // int ans = 0;
    // vector<int> vis(n);
    // for (auto f : s) {
    //     // delete mpl
    //     for (auto p : mpl[f]) {
    //         adj[p.first].erase(p.second);
    //     }
    //     // add mpg
    //     for (auto p : mpg[f]) {
    //         adj[p.first].insert(p.second);
    //     }
    //     // call topological ordering
    //     bool e = true;
    //     fill(all(vis), 0);
    //     dfs(rand() % n, adj, vis, e);
    //     if (e) ans++;
    // } 
    cout << "Case #" << t << ": " << s.size() << endl;
}

int main() {
    srand(time(0));
    // s.insert({1, 2});
    // s.insert({1, 3});
    // s.insert({0, 1});
    // s.insert({0, 1});
    // for (auto x : s) {
    //     cout << x.first << "," << x.second << endl;
    // }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
