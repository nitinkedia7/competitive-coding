#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    set<int> s;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.insert(x);
    } 
    int found = -1;   
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (s.find(x) != s.end()) {
            found = x;
        }
    }
    if (found == -1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl << 1 << " " << found << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
