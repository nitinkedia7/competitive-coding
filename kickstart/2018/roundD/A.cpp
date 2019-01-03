#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    int n, o, x1, x2, a, b, c, m, l;
    long long d;
    cin >> t;
    for (int count = 1; count <= t; count++) {
        cin >> n >> o >> d;
        cin >> x1 >> x2 >> a >> b >> c >> m >> l;

        vector<int> v(n);
        v[0] = x1;
        v[1] = x2;
        a = a%m;
        b = b%m;
        c = c%m;
        for (int i = 2; i < n; i++) {
            long long p = (a*1LL*v[i-1]) % m;
            p += (b*1LL*v[i-2]) % m;
            p = p%m;
            p += c;
            p = p%m;
            v[i] = p;
        }
        for (int i = 0; i < n; i++) v[i] += l;
        // output
        vector<int> odd(n);
        for (int i = 0; i < n; i++) {
            if (v[i] >= 0) odd[i] = v[i]%2;
            else odd[i] = ((-1)*v[i])%2;
        }

        vector<long long> opt(n);
        vector<int> imp(n, 0);
        int prev = -1, nodd = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (v[0] <= d && odd[i] <= o) {
                    opt[0] = v[0];
                    prev++;
                    nodd = odd[i];
                }
                else {
                    opt[0] = 0;
                    imp[0] = 1;
                }
            }
            else {
                if (odd[i] == 0) {
                    if (0 && opt[i-1]+v[i] <= d) {
                        opt[i] = opt[i-1]+v[i];
                    }
                    else {
                        long long sum = opt[i-1] + v[i];
                        while (prev != -1 && prev <= i) {
                            sum -= v[prev];
                            nodd -= odd[prev];
                            if (sum <= d) {
                                // opt[i] = sum;
                                prev++;
                                break;
                            }
                            prev++;
                        }
                        if (sum <= d) opt[i] = sum;
                        else {
                            opt[i] = 0;
                            prev = -1;
                            imp[i] = 1;
                        }
                    }
                }
                else { // odd case
                    if (opt[i-1]+v[i] <= d && nodd+1 <= o) {
                        opt[i] = opt[i-1]+v[i];
                    }
                    else {
                        long long sum = opt[i-1] + v[i];
                        nodd += 1;
                        while (prev <= i && prev != -1) {
                            sum -= v[prev];
                            nodd -= odd[prev];
                            if (sum <= d && nodd <= o) {
                                // opt[i] = sum;
                                prev++;
                                break;
                            }
                            prev++;
                        }
                        if (sum <= d && nodd <= o) opt[i] = sum;
                        else {
                            opt[i] = 0;
                            prev = -1;
                            imp[i] = 1;
                        }
                    }
                }
            }
        }
        long long m = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if (opt[i] >= m && imp[i] == 0) m = opt[i];
        }
        cout << "Case #" << count << ": ";
        if (m != LLONG_MIN) cout << m << endl;
        else cout << "IMPOSSIBLE" << endl;
    }   
}