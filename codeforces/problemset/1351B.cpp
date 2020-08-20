#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    if (a1 != a2 && b1 != b2) {
        cout << "NO" << endl;
    }
    else if (a1 == a2 && b1 == b2) {
        if (a1 == b1 + b2) {
            cout << "YES" << endl;
        }
        else if (b1 == a1 + a2) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else if (b1 == b2) {
        if (b1 == a1 + a2) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        if (a1 == b1 + b2) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
