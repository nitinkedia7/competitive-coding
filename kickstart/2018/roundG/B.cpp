#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void print(vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(vector<ll> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
void scan(vector<int> &v, int n) {
    // v is already of size n;
    int x1, x2, a, b, c, m;
    cin >> x1 >> x2 >> a >> b >> c >> m;
    v[0] = x1;
    v[1] = x2;
    ll t1, t2;
    for (int i = 2; i < n; i++) {
        t1 = 1LL * a * v[i-1];
        t1 = t1 % m; 
        t2 = 1LL * b * v[i-2];
        t2 = t2 % m;
        t1 += t2;
        t1 = t1 % m; 
        t1 += c;
        t1 = t1 % m;
        v[i] = t1; 
    }
}

int main() {
    int t;
    int n, q;
    int x1, x2, a, b, c, m;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> n >> q;
        vector<int> x(n);
        scan(x, n);
        vector<int> y(n);
        scan(y, n);
        vector<int> z(q);
        scan(z, q);

        // cout << endl;
        // print(x);
        // print(y);
        // print(z);
        // cout << endl;

        vector<int> l(n), r(n), k(q);
        for (int i = 0; i < n; i++) {
            l[i] = min(x[i], y[i]) + 1;
            r[i] = max(x[i], y[i]) + 1;
            r[i]++;
        }
        for (int i = 0; i < q; i++) {
            k[i] = z[i] + 1;
        }
        set <int> s;
        for (int i = 0; i < n; i++) {
            s.insert(l[i]);
            s.insert(r[i]);
        }
        vector<int> pos;
        set <int> :: iterator itr; 
        for (itr = s.begin(); itr != s.end(); ++itr) {
            pos.push_back(*itr);
        }
        int p = pos.size();
        vector<int> m(p+1, 0);
        for (int i = 0; i < n; i++) {
            m[lower_bound(pos.begin(), pos.end(), l[i]) - pos.begin()]++;
            m[lower_bound(pos.begin(), pos.end(), r[i]) - pos.begin()]--;
        }
        for (int i = 0; i < p-1; i++) {
            m[i+1] = m[i+1] + m[i];
        }
        // print(pos);
        // print(m);
        // return 0;
        vector<ll> sf(p, 0);
        sf[p-1] = m[p-1];
        for (int i = p-1; i > 0; i--) {
            sf[i-1] = sf[i] + m[i-1] * 1LL * (pos[i]-pos[i-1]); 
        }
        // print(l);
        // print(r);
        // print(k);
        // print(pos);
        // print(m);
        // print1(sf);
        // return 0;

        ll ans = 0;
        for (int i = 0; i < q; i++) {
            if (k[i] <= sf[0]) {
                int x1 = upper_bound(sf.begin(), sf.end(), k[i], greater<long long>()) - sf.begin();
                if (sf[x1] == k[i]) {
                    ans += (1LL * pos[x1] * (i+1));
                }
                else {
                    x1--;
                    // int x2 = x1;
                    // cout << "x2: " << x2 << endl;
                    // cout << "sf[x2]: " << sf[x2] << endl;
                    // cout << "m[x2]: " << m[x2] << endl;
                    // cout << "pos[x2]: " << pos[x2] << endl;
                    // cout << "k[0]: " << k[0] << endl;

                    long long d = sf[x1] - k[i];
                    d = d / m[x1];
                    ll term = pos[x1] + d;
                    ans += term * (i+1);
                }
            }
        }
        cout << "Case #" << c << ": " << ans;
        cout << endl;
    }
}