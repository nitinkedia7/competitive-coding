#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int k;
    cin >> k;
    int n;
    for (n = 16; n >= 0; n--) {
        if (k & (1 << n)) break;
    }
    // n'th bit 0-indexed is the highest bit in k
    int all1 = (1 << (n+2)) - 1;
    int prefix = 1 << (n+1);
    cout << 3 << " " << 3 << endl;
    cout << all1 << " " << all1 << " " << prefix << endl;
    cout << all1 << " " << k << " " << all1 << endl;
    cout << prefix << " " << all1 << " " << k << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}