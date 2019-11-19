#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void findPrev(set<pair<int,int>> &s, int &x) {
    set<pair<int,int>>::iterator it, cur;
    it = s.lower_bound({x, x});
    cur = s.end();                
    if (it->first == x) {
        cur = it;
    }
    if (it != s.begin()) {
        it--;
        if (x >= it->first && x <= it->second) {
            cur = it;
        }
    }
    if (cur != s.end()) {
        x = cur->first - 1;
    }
    // Now x is ready to be inserted;
    it = s.lower_bound({x, x});
    int r = cur->second;
    if (it == s.begin()) {
        s.erase(cur);
        s.insert({x, r});
    }
    else {
        it--;
        if (it->second == x - 1) {
            int l = it->first;
            s.erase(it);
            s.erase(cur);
            s.insert({l, r});
        } 
        else {
             s.erase(cur);
            s.insert({x, r});
        }
    }
    return;
}

void findNext(set<pair<int,int>> &s, int &x) {
    set<pair<int,int>>::iterator it, cur;
    it = s.lower_bound({x, x});
    cur = s.end();                
    if (it->first == x) {
        cur = it;
    }
    if (it != s.begin()) {
        it--;
        if (x >= it->first && x <= it->second) {
            cur = it;
        }
    }
    if (cur != s.end()) {
        x = cur->first - 1;
    }
    // Now x is ready to be inserted;
    it = s.lower_bound({x, x});
    int r = cur->second;
    if (it == s.begin()) {
        s.erase(cur);
        s.insert({x, r});
    }
    else {
        it--;
        if (it->second == x - 1) {
            int l = it->first;
            s.erase(it);
            s.erase(cur);
            s.insert({l, r});
        } 
        else {
             s.erase(cur);
            s.insert({x, r});
        }
    }
    return;
}

void sherlock(int t) {
    int n, r, c, sr, sc;
    char dir;
    cin >> n >> r >> c >> sr >> sc;
    vector<set<pair<int,int>>> row(r + 1), col(c + 1);
    row[sr].insert({sc, sc});
    col[sc].insert({sr, sr});
    char dir;
    for (int i = 0; i < n; i++) {
        cin >> dir;
        switch (dir) {
            case 'N':
                // it = col[sc].lower_bound({sr, sr});
                // cur = col[sc].end();                
                // if (it->first == sr) {
                //     cur = it;
                // }
                // if (it != col[sc].begin()) {
                //     it--;
                //     if (sr >= it->first && sr <= it->second) {
                //         cur = it;
                //     }
                // }
                // if (cur != col[sc].end()) {
                //     sr = cur->first - 1;
                // }

            case 'S':
            case 'E':
            case 'W':
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}