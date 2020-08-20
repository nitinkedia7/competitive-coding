#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> even, odd;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0) even.push_back(i+1);
        else odd.push_back(i+1);
    }    
    if (even.size() > 0) {
        cout << 1 << endl << even[0] << endl;
    }
    else if (odd.size() > 1) {
        cout << 2 << endl << odd[0] << " " << odd[1] << endl;
    }
    else {
        cout << -1 << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}