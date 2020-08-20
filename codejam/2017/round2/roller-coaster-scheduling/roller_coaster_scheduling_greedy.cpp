#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const ll MAX_ITER = 2;

bool is_possible(int r, int n, int c, int m, vector<vector<pair<int,int>>> &b) {
    // can r rides satisfy the tickets sold
    vector<int> done_ticket(m, 0);
    vector<int> customer(c);
    iota(all(customer), 0);
    for (int i = 0; i < r; i++) {
        vector<bool> done_customer(c, 0);
        
        for (int j = 0; j < n; j++) {
            int t_id = -1, pos, c_id;
            if (j % 2) random_shuffle(all(customer));
            for (auto k : customer) {
                if (done_customer[k]) continue;
                for (auto &t : b[k]) {
                    if (done_ticket[t.second]) continue;
                    if (t.first < j) continue;
                    if (t_id == -1 || pos > t.first) {
                        t_id = t.second;
                        pos = t.first;
                        c_id = k;
                    }
                    if (t_id != -1 && pos == j) break;
                } 
            }
            if (t_id == -1) break;
            done_ticket[t_id] = 1;
            done_customer[c_id] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        if (!done_ticket[i]) return false;
    }   
    return true;
}

void sherlock(int tc) {
    int n, c, m;
    cin >> n >> c >> m;
    vector<vector<pair<int,int>>> b(c); // list of tickets bought by i'th customer
    vector<vector<int>> v(n, vector<int> (c));
    int p, c_id; // position, customer
    for (int i = 0; i < m; i++) {
        cin >> p >> c_id;
        p--;
        c_id--;
        v[p][c_id]++;
        b[c_id].push_back({p, i});
    }    
    
    // find min rides required
    int l = 1, r = m, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (!is_possible(mid, n, c, m, b)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    int minl = l;
    for (l = max(1, minl-1); l <= minl; l++) {
        if (is_possible(l, n, c, m, b)) {
            minl = l;
            break;
        }
    }
    l = minl;
    
    // int minl = m;
    // for (int i = 0; i < MAX_ITER; i++) {
    //     int l = 1, r = minl, mid;
    //     while (l <= r) {
    //         mid = (l + r) / 2;
    //         if (!is_possible(mid, n, c, m, b)) {
    //             l = mid + 1;
    //         }
    //         else {
    //             r = mid - 1;
    //         }
    //     }
    //     if (l < minl) minl = l;
    // }
    // int l = minl;
    // possible in l rides
    // Now find minimum number of promotions
    int x = 0;
    vector<vector<int>> filled(l, vector<int> (n));
    for (int k = 0; k < c; k++) {
        for (auto &t : b[k]) {
            for (int i = 0; i < l; i++) {
                if (filled[i][t.first] == 0) {
                    filled[i][t.first] = 1;
                    x++;
                    break;
                }
            }
        }
    }
    cout << "Case #" << tc << ": " << l << " " << m - x << endl;
}

int main() {
    srand(time(0));
    // srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
