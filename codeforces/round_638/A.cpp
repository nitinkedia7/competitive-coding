#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    ll a = 0, b = 0;
    ll x = 2;
    for (int i = 0; i < n/2-1; i++) {
        a += x;
        x *= 2;
    }  
    for (int i = n/2-1; i < n-1; i++) {
        b += x;
        x *= 2;
    }
    a += x;
    cout << abs(a-b) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
