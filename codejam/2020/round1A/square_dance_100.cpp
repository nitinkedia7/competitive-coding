#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int r, c;
vector<vector<int>> v, n, s, e, w;

void print2d(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void update_east(int i) {
    int ls = 0;
    for (int j = 0; j < c; j++) {
        e[i][j] = ls;
        if (v[i][j] > 0) ls = v[i][j]; 
    }
}

void update_west(int i) {
    int ls = 0;
    for (int j = c-1; j >= 0; j--) {
        w[i][j] = ls;
        if (v[i][j] > 0) ls = v[i][j];
    }
}

void update_north(int j) {
    int ls = 0;
    for (int i = 0; i < r; i++) {
        n[i][j] = ls;
        if (v[i][j] > 0) ls = v[i][j];
    }
}

void update_south(int j) {
    int ls = 0;
    for (int i = r-1; i >= 0; i--) {
        s[i][j] = ls;
        if (v[i][j] > 0) ls = v[i][j];
    }
}

bool win(int i, int j) {
    int c = 0, x = 0;
    if (n[i][j] > 0) {
        c++;
        x += n[i][j];
    }
    if (s[i][j] > 0) {
        c++;
        x += s[i][j];
    }
    if (e[i][j] > 0) {
        c++;
        x += e[i][j];
    }
    if (w[i][j] > 0) {
        c++;
        x += w[i][j];
    }
    return v[i][j] * c >= x; 
}

void play(vector<int> &rmod, vector<int> &cmod, ll &ans, ll &csum) {
    // print2d(v);
    for (int i = 0; i < r; i++) {
        if (rmod[i]) {
            update_east(i);
            update_west(i);
        }
    }
    for (int j = 0; j < c; j++) {
        if (cmod[j]) {
            update_north(j);
            update_south(j);
        }   
    }
    int x = 0;
    vector<int> nrmod(r, 0), ncmod(c, 0);
    for (int i = 0; i < r; i++) {
        if (!rmod[i]) continue;
        for (int j = 0; j < c; j++) {
            if (v[i][j] != 0 && !win(i, j)) {
                csum -= v[i][j];
                v[i][j] = 0;
                nrmod[i] = 1;
                ncmod[j] = 1;
                x++;
            }
        }
    } 
    for (int j = 0; j < c; j++) {
        if (!cmod[j]) continue;
        for (int i = 0; i < r; i++) {
            if (v[i][j] != 0 && !win(i, j)) {
                csum -= v[i][j];
                v[i][j] = 0;
                nrmod[i] = 1;
                ncmod[j] = 1;
                x++;
            }
        }
    }
    if (x > 0) { // !all_win
        ans += csum;
        play(nrmod, ncmod, ans, csum);
    }
}


void sherlock(int t) {
    cin >> r >> c;
    v.clear();
    n.clear();
    s.clear();
    e.clear();
    w.clear();
    v.resize(r, vector<int> (c));
    n.resize(r, vector<int> (c));
    s.resize(r, vector<int> (c));
    e.resize(r, vector<int> (c));
    w.resize(r, vector<int> (c));
    
    ll ans = 0, csum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
            csum += v[i][j];
        }
    }
    vector<int> rmod(r, 1), cmod(c, 1);
    ans = csum;
    play(rmod, cmod, ans, csum);
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}