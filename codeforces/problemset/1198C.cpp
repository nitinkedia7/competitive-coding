#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, m;
    cin >> n >> m;
    int u, v;
    vector<int> matched(3 * n);
    vector<int> matching, set;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        if (matched[u] == 0 && matched[v] == 0) {
            matched[u] = 1;
            matched[v] = 1;
            matching.push_back(i+1);
        }
    }    
    if ((int) matching.size() >= n) {
        cout << "Matching" << endl;
        for (int i = 0; i < n; i++) {
            cout << matching[i] << " ";
        }
        cout << endl;
        return;
    }
    int s = n;
    cout << "IndSet" << endl;
    for (int i = 0; i < 3 * n; i++) {
        if (matched[i] == 0 && s > 0) {
            s--;
            cout << i + 1 << " ";
        }
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
