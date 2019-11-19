#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dist(tuple<int,int,int> &p, tuple<int,int,int> &q) {
    ll x = get<0> (p) - get<0> (q); 
    ll y = get<1> (p) - get<1> (q); 
    ll z = get<2> (p) - get<2> (q); 
    return x * x + y * y + z * z;
}

int main() {
    int n;
    cin >> n;
    vector<tuple<int,int,int>> v(n);
    int x, y, z;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        v[i] = {x, y, z};
    }
    vector<int> gone(n);
    for (int i = 0; i < n; i++) {
        if (gone[i]) continue;
        gone[i] = 1;
        ll md = LLONG_MAX;
        int gf = 0;
        for (int j = 0; j < n; j++) {
            if (gone[j]) continue;
            if (dist(v[i], v[j]) < md) {
                md = dist(v[i], v[j]);
                gf = j;
            }
        }
        gone[gf] = 1;
        cout << i + 1 << " " << gf + 1 << endl;
    }
    return 0;
}