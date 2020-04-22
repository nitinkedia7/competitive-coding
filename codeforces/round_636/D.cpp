#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 2; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void incr(int l, int r, int val, vector<int> &p) {
    if (l > r) {
        // cout << "err" << endl;
        return;
    }
    if (l >= p.size()) return;
    p[l] += val;
    if (r + 1 < p.size()) p[r+1] -= val;
} 

void update(int a, int b, int k, vector<int> &p) {
    incr(2, min(a, b), 2, p);
    incr(min(a,b)+1, (a+b-1), 1, p);
    incr(a+b+1, max(a,b)+k, 1, p);
    incr(max(a,b)+k+1, 2 * k, 2, p);  
    // print(p);
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), p(2 * k + 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; 2 * i < n; i++) {
        update(v[i], v[n-i-1], k, p);
    }   
    int m = p[2];
    for (int i = 3; i <= 2 * k; i++) {
        p[i] += p[i-1];
        m = min(m, p[i]);
    }
    // print(p);
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}