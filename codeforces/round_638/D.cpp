#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void sherlock(int t) {
    ll n;
    cin >> n;
    vector<int> x;
    ll sum = 1, cur = 1;
    while (sum <= n) {
        x.push_back(cur);
        cur *= 2;
        sum += cur;
    }    
    if (sum - cur < n) {
        x.push_back(n - sum + cur);
    }
    for (int i = x.size()-1; i > 0; i--) {
        if (x[i] < x[i-1]) {
            swap(x[i], x[i-1]);
        }
    }
    // print(x);
    cout << x.size() - 1 << endl;
    for (int i = 1; i < (int) x.size(); i++) {
        cout << x[i] - x[i-1] << " ";
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
