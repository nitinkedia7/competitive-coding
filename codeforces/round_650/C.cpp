#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int get_free(int d, int k) {
    int x = 0;
    int md = 2 + 2 * k;
    while (d >= md) {
        x++;
        md += k + 1;
    }
    return x;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    int N = n + 2 * k + 2;
    vector<char> v(N, '0');
    v[0] = '1';
    v[N - 1] = '1';
    for (int i = 0; i < n; i++) {
        cin >> v[i + k + 1];
    }
    int j = 0, ans = 0;
    for (int i = 1; i < N; i++) {
        if (v[i] == '0') continue;
        ans += get_free(i - j, k);
        j = i;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
