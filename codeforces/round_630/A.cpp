#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

bool can_move(int a, int b, int x1, int x, int x2) {
    if (x1 == x2) {
        return a == 0 && b == 0;
    }
    int p = min(a, b);
    a -= p;
    b -= p;
    if (a > 0) {
        return x - a >= x1;
    }
    if (b > 0) {
        return x + b <= x2; 
    }
    return true;
}

void sherlock(int t) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (can_move(a, b, x1, x, x2) && can_move(c, d, y1, y, y2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
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