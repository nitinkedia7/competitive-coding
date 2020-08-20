#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N_MAX = 1e4;

void sherlock(int t) {
    int n = N_MAX, q = N_MAX;
    cout << n << " " << q << endl;
    for (int i = 0; i < n; i++) {
        cout << rand() % n + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < q; i++) {
        if (i % 2) {
            cout << -1 * (rand() % n + 1) << " ";
        }   
        else {
            cout << rand() % n + 1 << " ";
        }
    }
    cout << endl;
}

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    cout << tt << endl;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
