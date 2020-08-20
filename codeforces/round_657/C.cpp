#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, m;
    cin >> n >> m;
    vector<pair<int,int>> cost;
    vector<tuple<ll,char,int>> v;
    ll a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v.push_back({a, 'a', i});
        v.push_back({b, 'b', i});
        cost.push_back({a, b});
    }    
    sort(all(v));
    ll max_ans = 0, cur_ans = 0;
    vector<int> a_seen(m, 0), b_seen(m, 0);
    for (int i = 2 * m - 1; i >= 0; i--) {
        if (n == 0) {
            break;
        }
        char type = get<1> (v[i]);
        int value = get<0> (v[i]), j = get<2> (v[i]);
        if (type == 'b') {
            if (a_seen[j] == 1) {
                cur_ans += n * value;
                break;
            }
            else {
                max_ans = max(max_ans, cur_ans + cost[j].first + (n - 1) * value);
                b_seen[j] = true;
            }
        }
        else { // type A
            if (b_seen[j]) {
                continue;
            }
            else {
                a_seen[j] = true;
                cur_ans += value;
                n--;
            }
        }
    }
    max_ans = max(max_ans, cur_ans);
    cout << max_ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
