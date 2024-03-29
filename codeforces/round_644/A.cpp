#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int a, b;
    cin >> a >> b;
    int a1 = max(2 * a, b);
    int a2 = max(a, 2 * b);
    int a3 = max(a + b, max(a, b));
    cout << min({a1 * a1, a2 * a2, a3 * a3}) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
