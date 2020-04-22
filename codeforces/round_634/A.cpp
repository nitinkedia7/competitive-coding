#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    if (n < 2) {
        cout << 0 << endl;
    }
    else if (n % 2 == 0) {
        cout << n / 2 - 1 << endl;
    }
    else {
        cout << n - (n+1) / 2 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}