#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int tc) {
    int n, c, m;
    cin >> n >> c >> m;
    vector<int> tickets_per_seat(n), tickets_by_customer(c);
    int p, b;
    for (int i = 0; i < m; i++) {
        cin >> p >> b;
        p--;
        b--;
        tickets_per_seat[p]++;
        tickets_by_customer[b]++;
    }
    int k = *max_element(all(tickets_by_customer));
    int prefix_sum = 0;
    for (int i = 0; i < n; i++) {
        prefix_sum += tickets_per_seat[i];
        k = max(k, (prefix_sum + i) / (i + 1));
    }
    int promo = 0;
    for (int i = 0; i < n; i++) {
        if (tickets_per_seat[i] > k) {
            promo += (tickets_per_seat[i] - k);
        }
    }
    cout << "Case #" << tc << ": " << k << " " << promo << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
