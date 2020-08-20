#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(int x, int y) {
    cout << x << " " << y << endl;
}

void sherlock(int t) {
    int n;
    cin >> n;
    int x = 0, y = 0;
    cout << 3 * n + 4 << endl;
    for (int i = 0; i < n; i++) {
        print(x, y);
        print(x + 1, y);
        print(x, y + 1);
        x++;
        y++;
    }    
    print(x, y);
    print(x + 1, y);
    print(x, y + 1);
    print(x + 1, y + 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
