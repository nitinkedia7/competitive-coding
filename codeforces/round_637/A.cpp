#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll minw = (a-b) * n, maxw = (a+b) * n;
    // cout << minw << " " << maxw << endl;
    if (maxw < c-d) {
        cout << "No" << endl;
    } 
    else if (minw > c+d) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    // if (minw >= c-d && minw <= c+d) {
    //     cout << "Yes" << endl;
    // }
    // else if (maxw >= c-d && maxw <= c+d) {
    //     cout << "Yes" << endl;
    // }
    // else cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}