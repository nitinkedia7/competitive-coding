#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cerr << v[i] << " ";
    }
    cerr << endl;
}

int query(vector<int> &li) {
    cout << "? " << li.size() << " ";
    for (auto i : li) {
        cout << i << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void make_li(vector<int> &li, int l, int r) {
    li.clear();
    for (int i = l; i <= r; i++) {
        li.push_back(i);
    }
    // print(li);
    return;
}

void sherlock(int t) {
    vector<int> li;
    int n, k;
    cin >> n >> k;
    vector<set<int>> v(k);
    vector<int> p(n + 1, -1);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            v[i].insert(x);
            p[x] = i;
        } 
    }
    make_li(li, 1, n);
    int g_max = query(li), o_max;
    // cerr << "G_MAX = " << g_max << endl;
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        // cerr << l << " " << r << " " << mid << endl;
        make_li(li, l, mid);
        int y = query(li);
        if (y < g_max) {
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }
    // cerr << "l = " << l << endl;
    // l is the position of g_max
    if (p[l] == -1) {
        cout << "! ";
        for (int i = 0; i < k; i++) {
            cout << g_max << " ";
        }
        cout << endl;
    }
    else {
        int y = p[l];
        li.clear();
        for (int i = 1; i <= n; i++) {
            if (v[y].find(i) == v[y].end()) {
                li.push_back(i);
            }
        }
        o_max = query(li);
        cout << "! ";
        for (int i = 0; i < k; i++) {
            if (i == y) {
                cout << o_max << " ";
            }
            else {
                cout << g_max << " ";
            }
        }
        cout << endl;
    }
    string res;
    cin >> res;
    if (res != "Correct") {
        exit(0);
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
