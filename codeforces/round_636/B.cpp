#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    int k = n / 2;
    if (k % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= k; i++) {
        cout << 2 * i << " ";
    }
    for (int i = 0; i < k-1; i++) {
        cout << 2*i+1 << " ";
    }
    cout << 2*k - 1 + k << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}