#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int win1(char a, char b) {
    if (b == 'R' && a == 'P') return 2;
    if (b == 'P' && a == 'S') return 2;
    if (b == 'S' && a == 'R') return 2;
    if (a == b) return 1;
    return 0;
}

int opposition(int i, vector<string> &v, vector<int> &result) {
    int a = v.size(), op = 0;
    for (int j = 0; j < a; j++) {
        if (result[j] == 2) continue; // already defeated
        switch (v[j][i % v[j].length()]) {
            case 'R':
                op = op | 1;
                break;
            case 'P':
                op = op | 2;
                break;
            case 'S':
                op = op | 4;
                break;
            default:
                break;
        }
    }
    return op;
}

void sherlock(int t) {
    int a;
    cin >> a;
    vector<string> v(a);
    vector<int> result(a, 1); // ongoing battle with everyone else
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    string ans;
    int state = 1, op; // ongoing
    for (int i = 0; i < a; i++) {
        op = opposition(i, v, result);
        switch (op) {
            case 0:
                state = 2;
                break;
            case 1: // R only
                ans.push_back('P');
                state = 2;
                break;
            case 2: // P only
                ans.push_back('S');
                state = 2;
                break;
            case 3: // RP
                ans.push_back('P');
                state = 1;
                break;
            case 4: // S only
                ans.push_back('R');
                state = 2;
                break;
            case 5: // SR
                ans.push_back('R');
                state = 1;
                break;
            case 6: // PS
                ans.push_back('S'); 
                state = 1;
                break;
            case 7: // RPS
                state = 0;
                cout << "Case #" << t << ": IMPOSSIBLE" << endl;
                return;
            default:
                break;
        }
        
        for (int j = 0; j < a; j++) {
            if (win1(ans[ans.size() - 1], v[j][i % v[j].length()]) == 2) result[j] = 2; // defeated
        }

        if (state == 2) {
            cout << "Case #" << t << ": " << ans << endl;
            return;
        }
    }
    cout << "Case #" << t << ": IMPOSSIBLE" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}