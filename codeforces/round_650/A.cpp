#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void sherlock(int t) {
    string b;
    cin >> b;
    int n = b.length();
    string a;
    for (int i = 0; i < n; i += 2) {
        a += b[i];
    }    
    a += b[n-1];
    cout << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
