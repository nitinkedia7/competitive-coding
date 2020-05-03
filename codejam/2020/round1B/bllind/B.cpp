#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll f = 1000000000;
const ll h = 1000000000 / 2;

int query(ll x, ll y) {
    // cerr << x << " " << y << endl;
    cout << x << " " << y << endl;
    string res;
    cin >> res;
    // cerr << res << endl;
    if (res == "MISS") {
        return 0;
    }
    else if (res == "HIT") {
        return 1;
    }
    else if (res == "CENTER") {
        return 2;
    }
    else {
        exit(0);
    }
} 

bool check(ll x, ll y) {
    return x <= f && x >= -1 * f && y <= f && y >= -1 * f; 
} 

void sherlock(int t) {
    vector<pair<ll,ll>> v = {{h, 0}, {-1 * h, 0}, {0, h}, {0, -1 * h}};
    ll x = -1, y = -1;
    for (int i = 0; i < 3; i++) {
        x = v[i].first;
        y = v[i].second;
        int res = query(x, y);
        if (res == 2) return;
        if (res == 1) {
            break;
        }
    }
    if (x == -1 || y == -1) {
        cerr << "ERROR" << endl;
        exit(0);
    }
    ll l = 0, r = f - x;
    while (l <= r) {
        ll mid = (l + r) / 2;
        int res = query(x+mid, y);
        if (res == 2) return;

        if (res == 1) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    ll x1 = x + l - 1;
    l = 0, r = x + f;
    while (l <= r) {
        ll mid = (l + r) / 2;
        // cerr << x-mid << " " << x << " " << mid << " " << l << " " << r << endl;
        int res = query(x-mid, y);
        if (res == 2) return;

        if (res == 1) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    ll x2 = x - l + 1;
    l = 0, r = f - y;
    while (l <= r) {
        ll mid = (l + r) / 2;
        int res = query(x, y+mid);
        if (res == 2) return;

        if (res == 1) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    ll y1 = y + l - 1;
    l = 0, r = y + f;
    while (l <= r) {
        ll mid = (l + r) / 2;
        int res = query(x, y-mid);
        if (res == 2) return;

        if (res == 1) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    ll y2 = y - l + 1;
    // assert(query(x1, y) >= 1);
    // assert(query(x2, y) >= 1);
    // assert(query(x, y1) >= 1);
    // assert(query(x, y2) >= 1);

    // cerr << x1 << " " << x2 << " " << y1 << " " << y2 << " " << endl;

    ll xc = (x1 + x2) / 2, yc = (y1 + y2) / 2;
    query(xc, yc);
    // queue<pair<ll,ll>> q;
    // q.push({xc, yc});
    // set<pair<ll,ll>> vis;
    // vis.insert({xc, yc}); 
    // while (!q.empty()) {
    //     xc = q.front().first;
    //     yc = q.front().second;
    //     q.pop();
    //     int res = query(xc, yc);
    //     if (res == 2) return;
    //     if (check(xc+1, yc) && vis.find({xc + 1, yc}) == vis.end()) {
    //         vis.insert({xc+1, yc});
    //         q.push({xc+1, yc});
    //     }
    //     if (check(xc-1, yc) && vis.find({xc - 1, yc}) == vis.end()) {
    //         vis.insert({xc-1, yc});
    //         q.push({xc-1, yc});
    //     }
    //     if (check(xc, yc+1) && vis.find({xc, yc+1}) == vis.end()) {
    //         vis.insert({xc, yc+1});
    //         q.push({xc, yc+1});
    //     }
    //     if (check(xc, yc-1) && vis.find({xc, yc-1}) == vis.end()) {
    //         vis.insert({xc, yc-1});
    //         q.push({xc, yc-1});
    //     }
    // }
    // cout << "Case #" << t << ": " << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt, a, b;
    cin >> tt >> a >> b;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}