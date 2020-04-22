#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> w(n);
    map<int,int> v;
    int s;
    int u = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v[s]++;
        if (v[s] == 1) u++;  
        w[i] = s;
    }
    
    int x = 0;
    for (int i = 0; i < n; i++) {
        int s = w[i];
        if (v[s] == 0) continue;
        x = max(x, min(u, v[s] - 1));
        x = max(x, min(u - 1, v[s]));
    }
    cout << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}