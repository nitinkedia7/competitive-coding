#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int MAXN = 1000;

void sherlock(int t) {
    int n = MAXN, c = MAXN, m = MAXN;
    cout << n << " " << c << " " << m << endl;
    for (int i = 0; i < m; i++) {
        cout << rand() % 10 + 1 << " " << rand() % c + 1 << endl;
    }   
}

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    cout << tt << endl;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
