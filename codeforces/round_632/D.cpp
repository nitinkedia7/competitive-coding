#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> v;
    int it = 0;
    bool changed = true;
    // cout << s << endl;
    while (it <= n && changed) {
        changed = false;
        vector<int> c;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == 'R' && s[i+1] == 'L') {
                c.push_back(i);
                changed = true;
                i++;
            }
        }
        for (int i = 0; i < c.size(); i++) {
            swap(s[c[i]], s[c[i] + 1]);
        }
        if (changed) v.push_back(c);
        c.clear();
        it++;
        // cout << s << endl;
    }
    if (changed) {
        cout << -1 << endl;
        return;
    }
    int kmin = 0, kmax = 0;
    for (int i = 0; i < v.size(); i++) {
        kmin++;
        kmax += v[i].size();
    }
    if (k < kmin || k > kmax) {
        cout << -1 << endl;
        return;
    }
    int i = 0;
    string ans;
    while (k > 0) {
        if (k > (v.size() - i)) {
            ans += "1 " + to_string(v[i][v[i].size() - 1] + 1);
            ans += '\n';
            // cout << 1 << " " << v[i][v[i].size() - 1] + 1 << endl;
            v[i].pop_back();
            if (v[i].size() == 0) i++; 
        }   
        else {
            // cout << v[i].size() << " ";
            ans += to_string(v[i].size()) + " ";
            for (int j = 0; j < v[i].size(); j++) {
                ans += to_string(v[i][j] + 1) + " ";
                // cout << v[i][j] + 1 << " ";
            }
            ans += '\n';
            // cout << endl;
            i++;
        }
        k--;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}