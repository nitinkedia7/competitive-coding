#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

bool is_pow2(ll x) {
    return x && (!(x & (x - 1)));
}

bool is_prime(ll x) {
    ll i = 2;
    while (i * i <= x) {
        if (x % i == 0) return false;
        i++;
    }
    return true;
}

void sherlock(int t) {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "FastestFinger" << endl;
    }    
    else if (n == 2) {
        cout << "Ashishgup" << endl;
    }
    else if (n % 2 == 1) {
        cout << "Ashishgup" << endl;
    } 
    else if (n % 4 == 0) {
        // n = 2^k * (odd_prime)
        if (is_pow2(n)) {
            cout << "FastestFinger" << endl;
        }
        else {
            cout << "Ashishgup" << endl;
        }
    }
    else {
        ll x = n / 2;
        if (is_prime(x)) {
            cout << "FastestFinger" << endl;
        }
        else {
            cout << "Ashishgup" << endl;
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
