#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll a1, b1, c1;
    ll mind = LLONG_MAX;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            for (int k = -1; k < 2; k++) {
                a1 = a + i;
                b1 = b + j;
                c1 = c + k;
                mind = min(mind, abs(a1-b1) + abs(c1-b1) + abs(c1-a1));
            }
        }
    }
    cout << mind << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock();
    return 0;
}