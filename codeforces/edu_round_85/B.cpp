#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, x;
    cin >> n >> x;
    vector<int> p;
    long long s = 0, w;
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        cin >> w;
        if (w < x) p.push_back(w);
        else {
            s += w;
            ans++;
        }
    }
    sort(p.begin(), p.end(), greater<int>());
    for (int i = 0; i < p.size(); i++) {
        if (s + p[i] >= (ans + 1) * 1LL * x) {
            s += p[i];
            ans++;
        }
        else break;
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