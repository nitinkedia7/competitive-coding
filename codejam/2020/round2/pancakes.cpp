#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const ll N_MAX = 1e10;
const ll INF = 1e18 + 5 * 1e17;

ll add(ll x, ll y) {
    return min(INF, x + y);
}

ll mul(ll x, ll y) {
    if (!x) {
        return 0;
    }
    if (INF / x < y) {
        return INF;
    }
    return x * y;
}


ll sum(ll k) {
    return (k * (k+1)) / 2;
}

void watson(int tc, ll left, ll right) {
    // find smallest k such that left - k * (k + 1) / 2 < r
    ll l = 1, r = N_MAX, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        ll sum = (mid * (mid + 1)) / 2;
        if (left - sum >= right) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    ll k = l;
    left -= sum(k-1);
    // cout << k << " " << left << endl;
    l = 1, r = N_MAX;
    while (l <= r) {
        mid = (l + r) / 2;
        ll val = add(mul(k, mid), mul(mid, mid - 1));
        // ll val = k * mid + mid * (mid - 1);
        if (val <= left) {
            l = mid + 1;
        }  
        else {
            r = mid - 1;
        }
    }
    ll pl = l;
    l = 1, r = N_MAX;
    while (l <= r) {
        mid = (l + r) / 2;
        ll val = add(mul(k, mid), mul(mid, mid));
        // ll val = k * mid + mid * mid;
        if (val <= right) {
            l = mid + 1;
        }  
        else {
            r = mid - 1;
        }
    }
    ll pr = l;
    // cout << pl << " " << pr << endl;
    ll minp = min(pl, pr) - 1;
    if (minp > 0) {
        left -= (k * minp + minp * (minp - 1));
        right -= (k * minp + minp * minp);
    }  
    k = k + 2 * (minp - 1) + 2;
    bool b = true;
    while (b) {
        b = false;
        if (left >= right) {
            if (k <= left) {
                left -= k;
                k++;
                b = true;
            }
        }
        else {
            if (k <= right) {
                right -= k;
                k++;
                b = true;
            }
        }
    }
    cout << "Case #" << tc << ": " << k-1 << " " << left << " " << right << endl;
}

void watson2(int tc, ll left, ll right) {
    // find smallest k such that left - k * (k + 1) / 2 < r
    ll l = 1, r = N_MAX, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        ll sum = (mid * (mid + 1)) / 2;
        if (right - sum > left) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    ll k = l;
    right -= sum(k-1);
    l = 1, r = N_MAX;
    while (l <= r) {
        mid = (l + r) / 2;
        ll val = add(mul(k, mid), mul(mid, mid - 1));
        // ll val = k * mid + mid * (mid - 1);
        if (val <= right) {
            l = mid + 1;
        }  
        else {
            r = mid - 1;
        }
    }
    ll pl = l;
    l = 1, r = N_MAX;
    while (l <= r) {
        mid = (l + r) / 2;
        ll val = add(mul(k, mid), mul(mid, mid));
        if (val <= left) {
            l = mid + 1;
        }  
        else {
            r = mid - 1;
        }
    }
    ll pr = l;
    ll minp = min(pl, pr) - 1;
    if (minp >= 0) {
        right -= (k * minp + minp * (minp - 1));
        left -= (k * minp + minp * minp);
    }  
    k = k + 2 * (minp - 1) + 2;
    bool b = true;
    while (b) {
        b = false;
        if (left >= right) {
            if (k <= left) {
                left -= k;
                k++;
                b = true;
            }
        }
        else {
            if (k <= right) {
                right -= k;
                k++;
                b = true;
            }
        }
    }
    cout << "Case #" << tc << ": " << k-1 << " " << left << " " << right << endl;
}

void sherlock(int t) {
    ll l, r;
    cin >> l >> r;
    if (l >= r) {
        watson(t, l, r);
    }
    else {
        watson2(t, l, r);
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
