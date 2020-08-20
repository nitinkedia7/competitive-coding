#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    int l = 0, r = 0, count = 0;
    vector<int> v(3);
    int ans = INT_MAX;
    while (r < n) {
        // expand
        if (r < l) r = l;
        while (r < n && count < 3) {
            v[s[r] - '1']++;
            if (v[s[r] - '1'] == 1) {
                count++;
            }
            r++;
        }
        bool good = (count == 3);
        // shrink
        while (l <= r && count == 3) {
            v[s[l] - '1']--;
            if (v[s[l] - '1'] == 0) {
                count--;
            }
            l++;
        }
        if (good) {
            ans = min(ans, r - l + 1);
        }
    }    
    if (ans == INT_MAX) {
        ans = 0;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
