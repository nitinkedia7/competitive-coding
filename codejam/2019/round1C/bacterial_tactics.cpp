#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

map<tuple<int,int,int,int>, int> dp;
vector<vector<char>> v;
vector<vector<int>> rowlaw, collaw;
int ans;

bool is_legal_row(int x, int y, int rid) {
    assert(x <= y);
    if (rowlaw[rid][y] < x + 1) return true;
    return false;
}

bool is_legal_col(int x, int y, int cid) {
    assert(x <= y);
    if (collaw[cid][y] < x + 1) return true;
    return false;
}

int solve(int x, int y, int r, int c) { // state
    if (dp.find({x, y, r, c}) != dp.end()) {
        return dp[{x, y, r, c}];
    }
    set<int> s;
    for (int i = 0; i < r; i++) { // horizontal
        if (!is_legal_row(y, y+c-1, x + i)) continue;
        int lhs = 0, rhs = 0;
        if (i > 0) {
            lhs = solve(x, y, i, c);
        }
        if (i < r-1) {
            rhs = solve(x+i+1, y, r-i-1, c);
        }
        if (x == 0 && y == 0 && r == v.size() && c == v[0].size() && (lhs ^ rhs) == 0) {
            ans += c;
        }
        s.insert(lhs ^ rhs);
    }
    for (int j = 0; j < c; j++) {
        if (!is_legal_col(x, x+r-1, y + j)) continue;
        int lhs = 0, rhs = 0;
        if (j > 0) {
            lhs = solve(x, y, r, j);
        }
        if (j < c-1) {
            rhs = solve(x, y+j+1, r, c-j-1);
        }
        if (x == 0 && y == 0 && r == v.size() && c == v[0].size() && (lhs ^ rhs) == 0) {
            ans += r;
        }
        s.insert(lhs ^ rhs);
    }
    int mex = -1;
    for (int i = 0; i <= s.size(); i++) {
        if (s.find(i) == s.end()) {
            mex = i;
            break;
        }
    }
    assert(mex != -1);
    dp[{x, y, r, c}] = mex;
    return mex;
}

void sherlock(int t) {
    ans = 0;
    dp.clear();
    v.clear();
    rowlaw.clear();
    collaw.clear();
    int r, c;
    cin >> r >> c;
    v.resize(r, vector<char> (c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    rowlaw.resize(r, vector<int> (c));
    for (int i = 0; i < r; i++) {
        int last_seen = 0;
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '#') last_seen = j + 1;
            rowlaw[i][j] = last_seen;
        }
    }
    collaw.resize(c, vector<int> (r));
    for (int j = 0; j < c; j++) {
        int last_seen = 0;
        for (int i = 0; i < r; i++) {
            if (v[i][j] == '#') last_seen = i + 1;
            collaw[j][i] = last_seen;
        }
    }
    solve(0, 0, r, c);
    cout << "Case #" << t << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}