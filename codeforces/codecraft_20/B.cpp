#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll MOD = 1000000007;


void sherlock(int t) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t1, t2, ans;
    int mink = 1;
    ans = s;
    for (int k = 1; k <= n; k++) {
        t1 = s.substr(k-1, n-k+1);
        t2 = s.substr(0, k-1);
        if ((n-k+1) % 2 == 1) reverse(t2.begin(), t2.end());
        t1 += t2;
        // cout << k << " " << t1 << endl;
        if (t1 < ans) {
            mink = k;
            ans = t1;
        }
    }   
    cout << ans << endl << mink << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}