#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<ll> m(1000), s(1000), p(1000);

bool possible(ll t, int r, int b, int c) {
    vector<ll> chunks;
    for (int i = 0; i < c; i++) {
        if (t > p[i] && ((t - p[i]) / s[i]) > 0) {
            chunks.push_back(min(m[i], (t - p[i]) / s[i]));
        }
    }
    sort(chunks.begin(), chunks.end(), greater<ll>());
    int i = 0;
    ll ab = 0;
    while (i < chunks.size() && i < r) {
        ab += chunks[i];
        i++;
    } 
    return ab >= b;
}

void sherlock(int t) {
    int r, b, c;
    cin >> r >> b >> c;
    for (int i = 0; i < c; i++) {
        cin >> m[i] >> s[i] >> p[i];
    }

    ll ub = LLONG_MIN, lb = *min_element(p.begin(), p.begin() + c);
    for (int i = 0; i < c; i++) {
        ub = max(ub, p[i] + m[i] * 1LL * s[i]);
    }
    while (lb <= ub) {
        // cout << lb << " " << ub << endl;
        ll mid = (lb + ub) / 2;
        if (!possible(mid, r, b, c)) {
            lb = mid + 1;
        }
        else {
            ub = mid - 1;
        }
    }
    // cout << lb << " " << ub << endl;
    cout << "Case #" << t << ": " << lb << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}