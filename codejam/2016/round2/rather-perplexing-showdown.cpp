#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N_MAX = 15;

vector<int> pow2(N_MAX, 1);

struct Count {
    int n, r, p, s;
    Count() {}
    Count(int n, int r, int p, int s) : n(n), r(r), p(p), s(s) {}
};

bool get_next_round(Count &cur, Count &next) {
    if (cur.n == 0) return false;
    next.n = cur.n - 1;
    next.p = pow2[cur.n-1] - cur.s;
    next.r = pow2[cur.n-1] - cur.p;
    next.s = pow2[cur.n-1] - cur.r;
    if (next.p < 0 || next.r < 0 || next.s < 0) {
        return false;
    }
    return true;
}

string sort_fixtures(string s) {
    if ((int) s.length() == 1) return s;
    int half_len = (int) s.length() / 2;
    string lhs = sort_fixtures(s.substr(0, half_len));
    string rhs = sort_fixtures(s.substr(half_len, half_len));
    if (lhs > rhs) swap(lhs, rhs);
    return lhs + rhs;
}

void sherlock(int t) {
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    vector<Count> v(n+1);
    v[n] = *new Count(n, r, p, s);
    for (int i = n-1; i >= 0; i--) {
        bool feasible = get_next_round(v[i+1], v[i]);
        if (!feasible) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            return;
        }
    }
    string lineup, next_lineup;
    if (v[0].p > 0) lineup = 'P';
    if (v[0].r > 0) lineup = 'R';
    if (v[0].s > 0) lineup = 'S';
    for (int i = 1; i <= n; i++) {
        next_lineup.clear();
        for (int j = 0; j < (int) lineup.size(); j++) {
            if (lineup[j] == 'P') {
                next_lineup += "PR";
            }
            else if (lineup[j] == 'R') {
                next_lineup += "RS";
            }
            else if (lineup[j] == 'S') {
                next_lineup += "PS";
            }
            else {
                assert(false);
            }
        }
        lineup.clear();
        lineup = next_lineup;
    }
    cout << "Case #" << t << ": " << sort_fixtures(lineup) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N_MAX; i++) {
        pow2[i] = 2 * pow2[i-1];
    }
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
