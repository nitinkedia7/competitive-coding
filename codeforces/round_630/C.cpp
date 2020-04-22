#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> count(26);
    int ans = 0;
    for (int i = 0; i < k; i++) {
        vector<int> v;
        int j = i;
        while (j < n) {
            v.push_back(j);
            j += k;
        }
        if (k > 1) {
            j = n-1-i;
            while (j >= 0) {
                v.push_back(j);
                j -= k;
            } 
        }
        fill(count.begin(), count.end(), 0);
        for (int i = 0; i < v.size(); i++) {
            count[s[v[i]]-'a']++;
        }
        int ma = max_element(count.begin(), count.end()) - count.begin();
        char x = ma + 'a';
        for (int i = 0; i < v.size(); i++) {
            if (s[v[i]] != x) ans++;
            s[v[i]] = x;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}