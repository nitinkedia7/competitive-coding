#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

vector<pair<ll,ll>> v(300);

bool smaller(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.first == 0 && a.second == 1) return true;
    if (a.first == 1 && a.second == 0) return false;
    if (b.first == 0 && b.second == 1) return false;
    if (b.first == 1 && b.second == 0) return true;
    return (a.first * b.second < a.second * b.first);
}

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

pair<pair<ll,ll>, pair<ll,ll>> process(int i, int j) {
    // (a, b) > (c, d)
    ll a = v[i].first, b = v[i].second, c = v[j].first, d = v[j].second;
    ll g, x, y;
    if (a > c) {
        if (b >= d) {
            return {{0, 1}, {1, 0}};
        }
        else {
            g = gcd(d-b, a-c);
            x = (d - b) / g;
            y = (a - c) / g;
            return {{x, y}, {1, 0}};
        }
    }
    else if (a == c) {
        if (b > d) {
            return {{0, 1}, {1, 0}};
        }
        else { // b <= d
            return {{1, 0}, {0, 1}};
        }
    }
    else { // a < c
        if (b > d) {
            g = gcd(b - d, c - a);
            x = (b - d) / g;
            y = (c - a) / g;
            return {{0, 1}, {x, y}};
        }
        else {
            return {{1, 0}, {0, 1}};
        }
    }
}

void limit_denominator(ll p1, ll q1, ll p2, ll q2, ll &p, ll &q) {
    ll x, y;
    if (q1 == 0 || p1 >= q1) {
        ll f = p1 / q1;
        limit_denominator(p1 - f * q1, q1, p2 - f * q2, q2, x, y);
        p = x + f * y;
        q = y;
    }
    else if (q2 == 0 || p2 > q2) {
        p = 1;
        q = 1;
    }
    else {
        limit_denominator(q2, p2, q1, p1, x, y);
        p = y;
        q = x;
    }
    return;
}

void sherlock(int t) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    pair<pair<ll,ll>, pair<ll,ll>> r{{0, 1}, {1, 0}}, rp;
    for (int i = 1; i < n; i++) {
        rp = process(i, i-1);
        // combine
        r.first = smaller(r.first, rp.first) ? rp.first : r.first;
        r.second = smaller(r.second, rp.second) ? r.second : rp.second;
        // cout << rp.first.first << "," << rp.first.second << " " << rp.second.first << "," << rp.second.second << endl; 
    }
    if (smaller(r.first, r.second)) {
        ll a = r.first.first, b = r.first.second, c = r.second.first, d = r.second.second;
        // cout << a << "," << b << "    " << c << "," << d << endl;
        ll x, y;
        limit_denominator(a, b, c, d, x, y);
        cout << "Case #" << t << ": " << x << " " << y << endl;
    }
    else {
        cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
