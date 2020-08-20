#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int n) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = rand() % (2 * n);
            if (x >= n) {
                cout << x - n + 1 << " ";
            }
            else {
                cout << x - n << " ";
            }
        }
        cout << endl;
    }    
}

int main() {
    srand((unsigned) chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, n;
    cin >> tt >> n;
    cout << tt << endl;
    for (int t = 1; t <= tt; t++) sherlock(n);
    return 0;
}
