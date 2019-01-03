#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t, n;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int N = 200001;
        vector<int> cnt(N, 0);
        for (int i = 0; i < n; i++) cnt[v[i]]++;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] >= N) break;
            int a = v[i], b = 0;
            ll prod = 0;
            while (prod < N) {
                cnt[a]--;
                if (b == prod) {
                    if (cnt[b] >= 2) {
                        ans += (cnt[b]*(cnt[b]-1))/2;
                    }
                }
                else {
                    if (cnt[prod] && cnt[b]) {
                        ans += cnt[b]*cnt[prod];
                    }
                }
                cnt[a]++;
                if (b >= N) break;
                prod += a;
                b++;
            }
            cnt[a]--;
        }

        cout << "Case #" << c << ": " << ans;
        cout << endl;
    }
}