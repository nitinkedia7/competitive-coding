#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1e18 + 1;
const int N = 1e5;

vector<ll> v(N);

ll my_rand() {
    ll a = rand() % MOD;
    ll b = rand() % MOD;
    a *= (RAND_MAX + 1LL);
    a %= MOD;
    return (a + b) % MOD;
}

void police() {
    for (int i = 0; i < N; i++) {
        v[i] = my_rand();
    }
    sort(all(v));
    cout << *max_element(all(v)) << endl;
    return;
}

bool query(int j, ll x, int &c) {
    c++;
    return v[j] >= x;
}

void sherlock(int t) {
    vector<int> ord(N);
    iota(all(ord), 0);
    random_shuffle(all(ord));
    ll max_till_now = 0;
    int c = 0, b = 0;
    for (auto i : ord) {
        if (!query(i, max_till_now + 1, c)) continue;
        b++;
        ll l = max_till_now, r = MOD - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            // if (A[mid] < target)
            if (query(i, mid, c)) {
                l = mid + 1;
            }
            else r = mid - 1;
        }
        max_till_now = l-1;
    }
    cout << max_till_now << endl;
    // assert(max_till_now == *max_element(all(v)));
    cout << c << " " << b << endl;
    // cout << "Case #" << t << ": " << endl;
}

int main() {
    srand(time(NULL));
    // srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 10;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) {
        police();
        sherlock(t);
    }
    return 0;
}
