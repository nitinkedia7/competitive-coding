#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    int d, f;
    vector<int> req(n), sold(n);
    for (int i = 0; i < n; i++) {
        cin >> d;
        if (d == -1) exit(0);
        vector<int> likes(n);
        for (int j = 0; j < d; j++) {
            cin >> f;
            if (f == -1) exit(0);
            req[f]++;
            likes[f]++;
        }
        // find min
        f = -1;
        for (int j = 0; j < n; j++) {
            if (sold[j]) continue;
            if (!likes[j]) continue;
            if (f == -1 || (req[j] <= req[f])) {
                f = j;
            }
        }
        if (f != -1) sold[f] = 1;
        cout << f << endl;
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