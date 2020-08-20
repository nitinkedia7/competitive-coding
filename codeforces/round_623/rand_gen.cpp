#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    cout << 1 << endl;
    int n;
    cin >> n;
    cout << n << endl;
    vector<int> v(2 * n);
    iota(all(v), 1);
    random_shuffle(all(v));
    for (int i = 0; i < n; i++) {
        cout << min(v[2 * i], v[2 * i + 1]) << " ";
    }    
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << min(v[2 * i], v[2 * i + 1]) << " ";
        cout << max(v[2 * i], v[2 * i + 1]) << " ";
    }
    cout << endl;
}

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
