#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    int n, d; 
    vector<int> v;
    for (; t > 0; t--) {
        cin >> n;
        v.clear();
        for (int i = 0; i < n; i++) {
            cin >> d;
            v.push_back(d);
        }
        sort(v.begin(), v.end());
        ll s = 0;
        n = n/2;
        for (int i = 0; i < n; i++) s += v[i];
        s = -1 * s;
        for (int i = n; i < 2*n; i++) s += v[i];
        cout << s << endl;
    }
}