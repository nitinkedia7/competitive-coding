#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
        cout << x/2 << " " << x/2 << endl;
    }
    else {
        cout << 1 << " " << (x-1) << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}