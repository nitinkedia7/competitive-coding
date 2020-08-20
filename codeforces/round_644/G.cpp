#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
}

void sherlock(int t) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (m % a != 0 || n != (m / a) * b) {
        cout << "NO" << endl;
        return;
    }    
    vector<int> v(m, 0);
    for (int i = 0; i < m; i += (m / a)) {
        v[i] = 1;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        print(v);
        rotate(v.begin(), v.begin() + 1, v.end());
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
