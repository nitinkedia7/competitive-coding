#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<ll> &v) {
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void add(int l, int r, int val, vector<ll> &v) {
    if (l > r || l >= v.size()) return;
    v[l] += val;
    if (r + 1 < v.size()) v[r+1] -= val;
    return;
}

void handle(int x, int y, vector<ll> &v) {
    if (x == y) return;
    add(1, x-1, y-x, v);
    add(x, x, y-1, v);
    add(x+1, y-1, y - x - 1, v);
    add(y, y, x, v);
    add(y+1, v.size(), y-x, v);
}   

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    vector<ll> v(n+1, 0);
    for (int i = 0; i < m-1; i++) {
        handle(min(x[i], x[i+1]), max(x[i], x[i+1]), v);
        // print(v);
    }
    for (int i = 2; i <= n; i++) {
        v[i] += v[i-1];
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " "; 
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}