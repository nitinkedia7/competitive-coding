#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ld PI = 3.1415926535897932384626433832795;

void sherlock(int t) {
    int n;
    cin >> n;

    ld fi = (PI * (n - 1)) / n;
    fi /= 2;
    ld a = sqrt(2) * sin(fi);
    cout << a << endl;

    ld theta = (PI * (n-2)) / n;
    theta /= 2;
    ld k = PI / n;
    k /= 2;
    // cout << theta << " " << k << endl;
    ld b = sin(theta) / sin(k);
    b /= sqrt(2);
    cout << b << endl;

    cout.precision(10);
    cout << fixed << a + b << endl << endl;;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
