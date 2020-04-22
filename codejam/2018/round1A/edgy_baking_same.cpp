#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    double p;
    cin >> n >> p;
    double w, h;
    for (int i = 0; i < n; i++) {
        cin >> w >> h;
    }
    double minr = 4 * min(w + h / 2, h + w / 2);
    double maxr = 2 * (w + h + sqrt(h * h + w * w));

    double maxp = n * 2 * (w + h), canp;
    for (int i = 0; i < n; i++) {
        canp = i * 2 * (w + h);
        int inr = (p - canp) / (n - i);
        if (inr >= minr && inr <= maxr) {
            maxp = max(maxp, p);
        }
        else if (inr > maxr) {
            maxp = max(maxp, canp + maxr * (n - i));
        }
    }
    cout.precision(17);
    cout << "Case #" << t << ": " << fixed <<  maxp << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}