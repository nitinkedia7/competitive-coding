#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int tc) {
    int n, k;
    cin >> n >> k;
    vector<int> both, only_a, only_b;
    int t, a, b;
    for (int i = 0; i < n; i++) {
        cin >> t >> a >> b;
        if (a == 1 && b == 1) both.push_back(t);
        else if (a == 1) only_a.push_back(t);
        else if (b == 1) only_b.push_back(t);
    }       
    int sum_a = both.size() + only_a.size();
    int sum_b = both.size() + only_b.size();
    if (sum_a < k || sum_b < k) {
        cout << -1 << endl;
        return;
    }
    sort(all(both));
    sort(all(only_a));
    sort(all(only_b));
    int x = 0, y = 0;
    ll min_time = 0;
    for (int i = 0; i < k; i++) {
        bool take1 = x < (int) both.size();
        bool take2 = y < (int) only_a.size() && y < (int) only_b.size();
        if (take1 && take2) {
            if (both[x] <= only_a[y] + only_b[y]) {
                min_time += both[x];
                x++;
            }
            else {
                min_time += (only_a[y] + only_b[y]);
                y++;
            }
        } 
        else if (take1) {
            min_time += both[x];
            x++;
        }
        else if (take2) {
            min_time += (only_a[y] + only_b[y]);
            y++;
        }
        else {
            assert(false);
        }
    }
    cout << min_time << endl;   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
