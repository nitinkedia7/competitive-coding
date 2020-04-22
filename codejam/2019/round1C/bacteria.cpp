#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

bool spread(int i, int j, char type, vector<vector<char>> &v) {
    int r = v.size(), c = v[0].size();
    if (i < 0 || i >= r || j < 0 || j >= c) return true;
    if (v[i][j] == '#') return false; // spread unsuccessful
    if (v[i][j] == 'H' || v[i][j] == 'V') return true;
    if (v[i][j] == '.') {
        v[i][j] = type;
        if (type == 'H') {
            return spread(i, j+1, type, v) && spread(i, j-1, type, v);
        }
        else return spread(i+1, j, type, v) && spread(i-1, j, type, v);
    }
    assert(false);
} 

int play(int turn, int i, int j, char type, vector<vector<char>> v) {
    int r = v.size(), c = v[0].size();
    if (v[i][j] == 'H' || v[i][j] == 'V') return !turn;
    if (spread(i, j, type, v)) {
        // now its opposition's turn
        bool opp_wins = false;
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                opp_wins = opp_wins || (play(!turn, x, y, 'H', v) == !turn);
                opp_wins = opp_wins || (play(!turn, x, y, 'V', v) == !turn);
                if (opp_wins) return !turn;
            }
        }
        return turn; // self win
    }   
    else {
        return !turn; // self lose
    }
}

void sherlock(int t) {
    int r, c;
    cin >> r >> c;
    if (r > 4 || c > 4) exit(0);
    vector<vector<char>> v(r, vector<char> (c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }

    int ans = 0, w;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            w = play(0, i, j, 'H', v);
            if (w == 0) {
                ans++;
                // cout << i << " " << j << " H" << endl;
            }

            w = play(0, i, j, 'V', v);
            if (w == 0) {
                ans++;
                // cout << i << " " << j << " V" << endl;
            }
        }
    }
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