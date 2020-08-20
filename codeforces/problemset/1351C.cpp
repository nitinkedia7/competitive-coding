#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string s;
    cin >> s;
    int n = s.length();
    set<pair<pair<int,int>, pair<int,int>>> vis;
    int x = 0, y = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int nx = x, ny = y;
        if (s[i] == 'N') nx++;
        else if (s[i] == 'S') nx--;
        else if (s[i] == 'E') ny++;
        else ny--;
        if (vis.find({{x, y}, {nx, ny}}) == vis.end()) {
            vis.insert({{x, y}, {nx, ny}});
            vis.insert({{nx, ny}, {x, y}});
            ans += 5;
        }
        else ans += 1;
        x = nx;
        y = ny;
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
