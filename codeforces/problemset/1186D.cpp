#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v0(n), v1(n);
    double d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        v0[i] = floor(d);
        v1[i] = ceil(d);
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v0[i];
    }
    for (int i = 0; i < n; i++) {
        if (sum < 0) {
            cout << v1[i] << endl;
            if (v1[i] > v0[i]) sum++;
        }
        else {
            cout << v0[i] << endl;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}