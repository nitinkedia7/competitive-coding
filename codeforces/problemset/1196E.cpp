#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int X = 1e8;

int b, w;
vector<pair<int,int>> off4 = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
set<pair<int,pair<int,int>>, greater<pair<int,pair<int,int>>>> b_club, w_club;
map<pair<int,int>, int> mp;
set<pair<int,int>> cc;

int get_color(int x, int y) {
    return (x + y) % 2;
}

void add(pair<int,int> p) {
    cc.insert(p);
    for (auto off : off4) {
        int x = p.first + off.first;
        int y = p.second + off.second;
        if (cc.find({x, y}) != cc.end()) {
            continue;
        }
        if (mp.find({x, y}) == mp.end()) {
            mp[{x, y}] = 4;
            if (get_color(x, y) == 1) {
                b_club.insert({4, {x, y}});
            }
            else {
                w_club.insert({4, {x, y}});
            }
        }
        int cur = mp[{x, y}];
        if (get_color(x, y) == 0) {
            w_club.erase({cur, {x, y}});
            if (cur > 0) {
                w_club.insert({cur - 1, {x, y}});
                mp[{x, y}] = cur - 1;
            }
        }
        else {
            b_club.erase({cur, {x, y}});
            if (cur > 0) {
                b_club.insert({cur-1, {x, y}});
                mp[{x, y}] = cur - 1;
            }
        }
    }
    if (get_color(p.first, p.second) == 0) {
        w--;
    }
    else {
        b--;
    }
}


void sherlock(int t) {
    b_club.clear();
    w_club.clear();
    cc.clear();
    mp.clear();
    cin >> b >> w;
    add({X, X});
    // cout << b << " " << w << endl;
    while (b + w > 0) {
        if (b > w) {
            if (!b_club.empty()) {
                pair<int,int> p = b_club.begin()->second;
                b_club.erase(b_club.begin());
                add(p);
            }
            else if (w > 0) {
                pair<int,int> p = w_club.begin()->second;
                w_club.erase(w_club.begin());
                add(p);
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            if (!w_club.empty()) {
                pair<int,int> p = w_club.begin()->second;
                w_club.erase(w_club.begin());
                add(p);
            }
            else if (b > 0) {
                pair<int,int> p = b_club.begin()->second;
                b_club.erase(b_club.begin());
                add(p);
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
        // cout << b << " " << w << endl;
    }
    cout << "YES" << endl;
    for (auto p : cc) {
        cout << p.first << " " << p.second << endl;
        // cout << (get_color(p.first, p.second) ? 'B' : 'W') << endl;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
