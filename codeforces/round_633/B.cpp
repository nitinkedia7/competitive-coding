#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l, r;
    if (n % 2 == 0) {
        r = n / 2;
        l = r - 1;
    }
    else {
        l = n / 2;
        r = n / 2;
    }
    cout << v[l] <<  " ";
    if (n % 2 == 0) cout << v[r] << " ";
    while (l >= 0 && r < n) {
        l--;
        r++;
        if (l < 0 || r >= n) break;
        cout << v[l] << " " << v[r]  << " ";
    }  
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}