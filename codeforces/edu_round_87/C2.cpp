#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = double;
const ll MOD = 1000000007;
const ld PI = 3.141592653589793;
const ld EPS = 0.000000001;
const int MAX_ITER = 200;

ld find_bounding_box(int n, ld a) {
    ld b = (2 * PI) / n;
    ld x_min = 0, x_max = 0, y_min = 0, y_max = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x += cos(a);
        y += sin(a);
        x_max = max(x_max, x);
        x_min = min(x_min, x);
        y_max = max(y_max, y);
        y_min = min(y_min, y);
        a += b;
    }
    return max(y_max - y_min, x_max - x_min);    
}

void sherlock(int t) {
    int n;
    cin >> n;
    n *= 2;
    ld l = 0, r = (2 * PI) / n;
    for (int i = 0; i < MAX_ITER && fabs(l - r) > EPS; i++) {
        ld m1 = (2 * l + r) / 3;
        ld m2 = (l + 2 * r) / 3;
        ld f1 = find_bounding_box(n, m1);
        ld f2 = find_bounding_box(n, m2);
        if (f1 > f2) {
            l = m1;
        }
        else {
            r = m2;
        }
    }
    cout.precision(9);
    cout << fixed << find_bounding_box(n, l) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
