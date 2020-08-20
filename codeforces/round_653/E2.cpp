#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int tc) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> both, only_a, only_b, v;
    int t, a, b;
    for (int i = 0; i < n; i++) {
        cin >> t >> a >> b;
        if (a == 1 && b == 1) both.push_back({t, i+1});
        else if (a == 1) only_a.push_back({t, i+1});
        else if (b == 1) only_b.push_back({t, i+1});
        else v.push_back({t, i+1});
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
    set<int> ans;   
    for (int i = 0; i < k; i++) {
        bool take1 = x < (int) both.size();
        bool take2 = y < (int) only_a.size() && y < (int) only_b.size();
        if (take1 && take2) {
            if (both[x].first <= only_a[y].first + only_b[y].first) {
                ans.insert(both[x].second);
                min_time += both[x].first;
                x++;
            }
            else {
                ans.insert(only_a[y].second);
                ans.insert(only_b[y].second);
                min_time += (only_a[y].first + only_b[y].first);
                y++;
            }
        } 
        else if (take1) {
            ans.insert(both[x].second);
            min_time += both[x].first;
            x++;
        }
        else if (take2) {
            ans.insert(only_a[y].second);
            ans.insert(only_b[y].second);
            min_time += (only_a[y].first + only_b[y].first);
            y++;
        }
        else {
            assert(false);
        }
    }
    int min_size = ans.size();
    // cout << min_size << endl;
    if (min_size > m) {
        int extra = min((int) both.size() - x, y);
        if (min_size - extra > m) {
            cout << -1 << endl;
            return;
        } 
        while (min_size > m) {
            y--;
            ans.erase(only_a[y].second);
            ans.erase(only_b[y].second);
            min_time -= (only_a[y].first + only_b[y].first);
            ans.insert(both[x].second);
            min_time += both[x].first;
            x++;
            min_size--;
        }
    }
    for (int i = x; i < (int) both.size(); i++) {
        v.push_back(both[i]);
    }
    for (int i = y; i < (int) only_a.size(); i++) {
        v.push_back(only_a[i]);
    }
    for (int i = y; i < (int) only_b.size(); i++) {
        v.push_back(only_b[i]);
    }
    sort(all(v));
    for (int i = 0; i < (m - min_size); i++) {
        min_time += v[i].first;
        ans.insert(v[i].second);
    }
    cout << min_time << endl;   
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
