#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return;
    }
    if (n % 2 == 0) {
        int d = 23;
        if ((5 * (n / 2)) % 3 == 0) {
            d = 33;
        }
        cout << d;
        for (int i = 0; i < (n/2 - 1); i++) {
            cout << 23;
        }
        cout << endl;
    }
    else {
        int d = 2;
        if ((5 * (n / 2) + 2) % 3 == 0) {
            d = 3;
        }
        cout << d;
        for (int i = 0; i < n/2; i++) {
            cout << 23;
        }
        cout << endl;
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