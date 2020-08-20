#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const int N_MAX = 17;

int n, k;
vector<ld> p(N_MAX);
vector<int> pow2(N_MAX, 1);

ld get_tie_prob(int x) {
    vector<ld> prob;
    for (int i = 0; i < n; i++) {
        if (x & (1 << i)) {
            prob.push_back(p[i]);
        }
    }
    ld tie_prob = 0;
    for (int i = 0; i < pow2[k]; i++) {
        if (__builtin_popcount(i) != k/2) continue;
        int y = i;
        ld z = 1;
        for (int j = 0; j < k; j++) {
            if (y & (1 << j)) {
                z *= prob[j];
            }   
            else {
                z *= (1 - prob[j]);
            }
        }
        tie_prob += z;
    }
    return tie_prob;
}

void sherlock(int t) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    if (n > 16) {
        exit(0);
    }
    ld max_tie_prob = 0;
    for (int i = 0; i < pow2[n]; i++) {
        if (__builtin_popcount(i) != k) continue;
        max_tie_prob = max(max_tie_prob, get_tie_prob(i));
    }
    cout.precision(10);
    cout << "Case #" << t << ": " << fixed << max_tie_prob << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N_MAX; i++) {
        pow2[i] = 2 * pow2[i-1];
    }
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
