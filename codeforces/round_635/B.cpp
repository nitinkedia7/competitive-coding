#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int x, n, m;
    cin >> x >> n >> m;
    while (n > 0 && x > 20) {
        x = x/2 + 10;
        n--;
    }
    while (m > 0) {
        x -= 10;
        m--;
    }
    if (x <= 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}