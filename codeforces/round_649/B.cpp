#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }    
    vector<int> ans;
    ans.push_back(v[0]);
    bool prev_trend = (v[1] > v[0] ? true : false);
    for (int i = 1; i < n; i++) {
        bool cur_trend = (v[i] > v[i-1] ? true : false);
        if (cur_trend != prev_trend) {
            ans.push_back(v[i-1]);
        }
        prev_trend = cur_trend;
    }
    ans.push_back(v[n-1]);        
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
