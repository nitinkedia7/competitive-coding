#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    ll n, k;
    cin >> n >> k;
    int i = 0;
    while (k > i) {
        k -= i;
        i++;
    }
    vector<char> v(n, 'a');
    v[i] = 'b';
    v[k-1] = 'b';
    for (int i = n-1; i >= 0; i--) {
        cout << v[i];
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