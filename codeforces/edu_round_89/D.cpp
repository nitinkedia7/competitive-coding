#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N = 10000001;

vector<int> s(N, 1), min_prime(N);

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t, vector<int> &v1, vector<int> &v2) {
    int a;
    cin >> a;
    set<int> pf;
    int x = a;
    while (x > 1) {
        pf.insert(min_prime[x]);
        x /= min_prime[x];
    }
    // for (auto d : pf) {
    //     cout << d << " ";
    // }
    // cout << endl;
    if (pf.size() == 1) {
        v1.push_back(-1);
        v2.push_back(-1);
    }
    else {
        int y = *pf.begin();
        int d1 = 1, d2 = a;
        while (d2 % y == 0) {
            d2 /= y;
            d1 *= y;
        }
        v1.push_back(d1);
        v2.push_back(d2);
    }
    return;
}

void police() {
    s[0] = 0;
    s[1] = 0;
    for (int i = 2; i < N; i++) {
        if (s[i] == 0) continue;
        min_prime[i] = i;
        for (int j = 2 * i; j < N; j += i) {
            s[j] = 0;
            min_prime[j] = i;
        }
    }
    // for (int i = 0; i < 20; i++) {
    //     cout << min_prime[i] << " ";
    // }
    // cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    police();
    int tt;
    cin >> tt;
    vector<int> v1, v2;
    for (int t = 1; t <= tt; t++) sherlock(t, v1, v2);
    print(v1);
    print(v2);
    return 0;
}
