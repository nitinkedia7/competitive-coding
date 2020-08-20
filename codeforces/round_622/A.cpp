#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

vector<vector<int>> v{{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1}};

void sherlock(int t) {
    vector<int> x(3);
    cin >> x[0] >> x[1] >> x[2];
    sort(all(x)); 
    int a = x[0], b = x[1], c = x[2];

    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (a >= v[i][0] && b >= v[i][1] && c >= v[i][2]) {
            ans++;
            a -= v[i][0];
            b -= v[i][1];
            c -= v[i][2];
        }
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
