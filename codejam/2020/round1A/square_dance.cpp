#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct Neighbour {
    int n, s, e, w;
};

int r, c;
vector<vector<int>> v;
vector<vector<Neighbour>> nv;

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool win(int i, int j) {
    int c = 0, x = 0;
    int n = nv[i][j].n, s = nv[i][j].s, e = nv[i][j].e, w = nv[i][j].w;
    if (n != -1 && v[n][j] > 0) {
        c++;
        x += v[n][j];
    }
    if (s != -1 && v[s][j] > 0) {
        c++;
        x += v[s][j];
    }
    if (e != -1 && v[i][e] > 0) {
        c++;
        x += v[i][e];
    }
    if (w != -1 && v[i][w] > 0) {
        c++;
        x += v[i][w];
    }
    return c * v[i][j] >= x;
}

void play(set<pair<int,int>> &wl, ll &ic, ll &il) {
    // cout << ic << endl;
    // print2d(v);
    
    // assuming neighbours are updated
    vector<pair<int,int>> el;
    for (auto z : wl) {
        int x = z.first, y = z.second;
        if (v[x][y] > 0 && !win(x, y)) {
            el.push_back(z);
            il -= v[x][y];
        }
    }
    for (int i = 0; i < el.size(); i++) {
        v[el[i].first][el[i].second] = 0;
    }
    wl.clear();
    // update neighbours of eliminated players
    for (int i = 0; i < el.size(); i++) {
        int x = el[i].first, y = el[i].second;
        int n = nv[x][y].n, s = nv[x][y].s, e = nv[x][y].e, w = nv[x][y].w;
        if (n != -1) {
            nv[n][y].s = s;
        }
        if (s != -1) {
            nv[s][y].n = n; 
        }
        if (e != -1) {
            nv[x][e].w = w;
        }
        if (w != -1) {
            nv[x][w].e = e;
        }
    }

    // prepare new watchlist
    for (int i = 0; i < el.size(); i++) {
        int x = el[i].first, y = el[i].second;
        int n = nv[x][y].n, s = nv[x][y].s, e = nv[x][y].e, w = nv[x][y].w;
        if (n != -1) {
            wl.insert({n, y});
        }
        if (s != -1) {
            wl.insert({s, y});
        }
        if (e != -1) {
            wl.insert({x, e});
        }
        if (w != -1) {
            wl.insert({x, w});
        }
    }

    if (el.size() > 0) {
        el.clear();
        ic += il;
        play(wl, ic, il);
    }
}

void sherlock(int t) {
    cin >> r >> c;
    v.resize(r, vector<int> (c));
    nv.resize(r, vector<Neighbour> (c));
    ll il = 0;
    set<pair<int,int>> wl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            nv[i][j] = *(new Neighbour());
            nv[i][j].n = i > 0 ? i-1 : -1;
            nv[i][j].s = i < r-1 ? i+1 : -1;
            nv[i][j].w = j > 0 ? j-1 : -1;
            nv[i][j].e = j < c-1 ? j+1 : -1;
            il += v[i][j];
            wl.insert({i, j});
        }
    }
    ll ic = il;
    play(wl, ic, il);
    cout << "Case #" << t << ": " << ic << endl;
    v.clear();
    nv.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}