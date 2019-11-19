#include <bits/stdc++.h>
using namespace std;

int reqm(int x) {
    assert(x >= 0 && x < 10);
    switch (x) {
        case 0:
            return 6;
        case 1:
            return 2;
        case 2:
            return 5;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 3;
        case 8:
            return 7;
        case 9:
            return 6;
        default:
            return 0;
    }
}

int calc(int x) {
    if (x == 0) return 6;
    int d, ans = 0;
    while (x > 0) {
        d = x % 10;
        x /= 10;
        ans += reqm(d);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    int a, b, sum;
    while (t--) {
        cin >> a >> b;
        sum = a + b;
        cout << calc(sum) << endl;
    }
    return 0;
}