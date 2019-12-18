#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n;
    cin >> n;
    ll q = n / 14;
    ll r = n % 14;
    if (q >= 1 && r >= 1 && r <= 6) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}