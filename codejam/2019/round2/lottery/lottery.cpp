#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int S = 10, N = 50;

vector<int> v(20);

void query(int v, int p, int &r) {
    int d;
    cin >> d;
    cout << v << " " << p << endl;
    // cerr << d << ": " << v << " " << p << endl;
    if (p == 0) {
        cin >> r;
        for (int i = 0; i < r; i++) {
            cin >> d;
        }
        if (r == -1) exit(0);
    }
}

void sherlock(int t) {
    random_shuffle(all(v));
    int f = rand() % 99 + 1;
    int res; 
    // Sabotage first S vases N times
    for (int i = 0; i < N; i++) {
        query(v[i % S], f, res);
    }
    // Inspect
    set<pair<int,int>> s;
    for (int i = 0; i < 20; i++) {
        query(v[i], 0, res);
        s.insert({res, v[i]});
    }
    // for (auto x : s) {
    //     cerr << x.second << "," << x.first << " ";
    // }
    // cerr << endl;
    // Now sabotage every one except two candidates
    pair<int,int> c1 = *s.begin();
    s.erase(s.begin());
    pair<int,int> c2 = *s.begin();
    s.erase(s.begin());
    for (int i = 0; i < (99 - N - 20 - 5); i++) {
        pair<int,int> c3 = *s.begin();
        s.erase(s.begin());
        query(c3.second, f, res);
        s.insert({c3.first + 1, c3.second});
    }
    query(c1.second, 0, c1.first);
    query(c2.second, 0, c2.first);
    int wv = c1.first < c2.first ? c1.second : c2.second;
    int lv = c1.first < c2.first ? c2.second : c1.second;
    query(lv, f, res);
    query(lv, f, res);
    query(lv, f, res);
    // query(lv, f, res);
    query(wv, 100, res);
    return;
}

int main() {
    srand(time(0));
    iota(all(v), 1);
    // for (int i = 0; i < 20; i++) {
    //     cerr << v[i] << " ";
    // }
    // cerr << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
