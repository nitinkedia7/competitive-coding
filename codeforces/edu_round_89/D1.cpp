#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

bool check(int a, int d1, vector<int> &v1, vector<int> &v2) {
    int d2 = a / d1;
    while (gcd(d1, d2) > 1) {
        d2 /= gcd(d1, d2);
    }
    if (d2 > 1) {
        v1.push_back(d1);
        v2.push_back(d2);
        return true;
    }
    return false;
}

void sherlock(int t, vector<int> &v1, vector<int> &v2) {
    int a = 9840769;
    // cin >> a;
    int d1 = 2;
    bool f = false;
    while (d1 * d1 <= a) {
        if (a % d1 == 0) {
            if (check(a, d1, v1, v2)) {
                f = true;
                break;
            }
            if (check(a, a / d1, v1, v2)) {
                f = true;
                break;
            }
        }
        d1++;
    }   
    if (!f) {
        v1.push_back(-1);
        v2.push_back(-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 5 * 1e5;
    // cin >> tt;
    vector<int> v1, v2;
    for (int t = 1; t <= tt; t++) sherlock(t, v1, v2);
    print(v1);
    print(v2);
    return 0;
}
