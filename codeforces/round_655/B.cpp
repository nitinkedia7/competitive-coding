#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    int max_div = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        max_div = max(max_div, max(i, n / i));
    }    
    cout << max_div << " " << n - max_div << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
