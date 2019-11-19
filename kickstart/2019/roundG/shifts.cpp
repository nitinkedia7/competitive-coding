#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void good(int n, int h, vector<int> &v1) {
    v1.clear();
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m = 1 << n;
    ll x;
    for (int s = 0; s < m; s++) {
        x = 0;
        for (int i = 0; i < n; i++) {
            if (s & (1 << i)) {
                x += v[i];
            }
        }
        if (x >= h) v1.push_back(s);
    }
    return;
}

void sherlock(int t) {
    int n, h;
    cin >> n >> h;
    vector<int> v1, v2;
    good(n, h, v1);
    good(n, h, v2);
    ll c = 0;
    int m = 1 << n;
    m -= 1;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            if ((v1[i] | v2[j]) == m) c++;
        }
    }
    cout << "Case #" << t << ": " << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}