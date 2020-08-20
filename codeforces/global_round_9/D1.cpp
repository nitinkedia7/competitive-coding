#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int,int>> v_s(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v_s[i] = {v[i], i};
    }
    sort(all(v_s));
    int j = 0;
    for (int x = 0; x < n; x++) {
        if (x == v_s[j].first) {
            j++;
            continue;
        }
        int i = v_s[j].second;
        v[i] = x;
        v_s[j].first = x;
        j++;
        cout << i << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
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
