#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void query(vector<int> &q, int &res) {
    cout << "? ";
    for (int i = 0; i < 100; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
    cin >> res;
}

void sherlock(int t) {
    vector<int> q(100);
    for (int i = 1; i <= 100; i++) {
        q[i-1] = i << 7;
    }
    int lsb;
    query(q, lsb);
    for (int i = 1; i <= 100; i++) {
        q[i-1] = i;
    }
    int msb;
    query(q, msb);
    int x = lsb % 128;
    x = x | ((msb / 128) << 7);
    cout << "! " << x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
