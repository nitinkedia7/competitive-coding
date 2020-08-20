#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, x;
    cin >> n >> x;
    vector<int> deg(n, 0);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;
        deg[u]++;
        deg[v]++;
    }        
    x--;
    if (deg[x] <= 1) {
        cout << "Ayush" << endl;
        return;
    }
    if (n % 2) {
        cout << "Ashish" << endl;
    } 
    else {
        cout << "Ayush" << endl;
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
