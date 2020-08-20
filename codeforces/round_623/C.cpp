#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> r_b(2 * n + 1);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        r_b[b[i]] = i;
    }    
    vector<int> p(2 * n + 1, 0), a(2 * n);
    for (int i = 0; i < n; i++) {
        if (p[b[i]] == 1) {
            cout << -1 << endl;
            return;
        }
        a[2 * i] = b[i];
        p[b[i]] = 1;
    }
    set<int> z;
    for (int i = 1; i <= 2 * n; i++) {
        if (p[i] == 1) {
            z.insert(r_b[i]);
            continue;
        }
        if (z.size() == 0) {
            cout << -1 << endl;
            return;
        }
        int x = *z.begin();
        z.erase(z.begin());
        a[2 * x + 1] = i;
    }


    for (int i = 0; i < 2 * n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
