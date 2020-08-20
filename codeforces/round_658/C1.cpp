#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void operate(string &a, int l, vector<int> &op) {
    for (int i = 0; i < l; i++) {
        a[i] = (a[i] == '0' ? '1' : '0');
    }
    reverse(a.begin(), a.begin() + l);
    op.push_back(l);
}

void sherlock(int t) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> op;
    for (int i = n - 1; i >= 0; i--) {
        // making position i same
        if (a[i] == b[i]) {
            continue;
        }
        if (a[0] == b[i]) {
            operate(a, 1, op);
        }
        operate(a, i + 1, op);
    }    
    assert(a == b);
    // cout << a << " " << b << endl;
    cout << op.size() << " ";
    for (int i = 0; i < (int) op.size(); i++) {
        cout << op[i] << " ";
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
