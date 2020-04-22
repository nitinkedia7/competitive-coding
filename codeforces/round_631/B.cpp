#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void is_permu(vector<int> &v, vector<int> &ans) {
    int n = v.size(), j = 1;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[v[i]]++;
        if (c[v[i]] == 2) break;
        while (c[j] == 1 && j < n) {
            j++;
        }
        if (i+1 == j-1) ans[i] = 1;
    }
    return;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> ans(n), ansr(n);
    is_permu(v, ans);
    reverse(v.begin(), v.end());
    is_permu(v, ansr);
    // for (int i = 0; i < n; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    
    vector<pair<int,int>> ansf;
    for (int i = 0; i < n-1; i++) {
        if (ans[i] && ansr[n - i - 2]) {
            ansf.push_back({i+1, n-i-1});
        }
    }
    cout << ansf.size() << endl;
    for (auto x : ansf) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}