#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int n) {
    cout << n << endl;
    int x = rand() % (int) (pow(2, n * n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (x & (1 << (i * n + j))) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    } 
}

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, n;
    cin >> tt >> n;
    cout << tt << endl;
    for (int t = 1; t <= tt; t++) sherlock(n);
    return 0;
}
