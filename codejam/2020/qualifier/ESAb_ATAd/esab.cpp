#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
int b;

int query(int i) {
    assert(i >= 1 && i <= b);
    cout << i << endl;
    int res;
    cin >> res;
    assert(res == 0 || res == 1);
    return res;
}

int find_op(int x1, int y1, int x2) {
    if (x1 == y1) {
        if (x1 == x2) {
            return 10;
        }
        else {
            return 5;
        }
    }
    else {
        if (x1 == x2) {
            return 12;
        }
        else {
            return 3;
        }
    }
}

void sherlock(int t, int b) {
    vector<int> v(b, -1);
    int np = b / 2;
    int i = 0;
    int si = -1, ci = -1;
    
    // scan first five pairs
    int x, y;
    for (; i < 5; i++) {
        x = query(i + 1);
        y = query(b - i);
        if (x == y) si = i;
        else ci = i;
        v[i] = x;
        v[b - i - 1] = y;
    } 
    int nsx, ncx;
    while (i < np) {
        // query for atmost 2 positions
        if (si != -1) {
            nsx = query(si + 1);
        }
        else {
            query(1);
        }
        if (ci != -1) {
            ncx = query(ci + 1);
        }
        else {
            query(1);
        }
        // determine the prev operation
        if (ci == -1) { // all same
            if (nsx != v[si]) {
                for (int j = 0; j < i; j++) {
                    v[j] = !v[j];
                    v[b - j - 1] = !v[b - j - 1];
                }
            }
        }
        else if (si == -1) { // all comp
            if (ncx != v[ci]) {
                for (int j = 0; j < i; j++) {
                    v[j] = !v[j];
                    v[b - j - 1] = !v[b - j - 1];
                }
            }
        }
        else { // given one same and one comp find the operation happened
            int op = find_op(v[si], v[b-si-1], nsx) & find_op(v[ci], v[b-ci-1], ncx);
            for (int j = 0; j < i; j++) {
                if (op == 1) {
                    v[j] = !v[j];
                    v[b - j - 1] = !v[b - j - 1];
                }
                else if (op == 2) {
                    swap(v[j], v[b - j - 1]);
                }
                else if (op == 4) {
                    swap(v[j], v[b - j - 1]);
                    v[j] = !v[j];
                    v[b - j - 1] = !v[b - j - 1];
                }
                else if (op == 8) {
    
                }
                else {
                    cout << "ERROR";
                    exit(0);
                }
            }
        }

        // now scan for 4 more pairs every iteration
        int it = 0;
        while (i < np && it < 4) {
            x = query(i + 1);
            y = query(b - i);
            if (x == y) si = i;
            else ci = i;
            v[i] = x;
            v[b - i - 1] = y;
            i++;
            it++;
        }
    }
    // cout << "Case #" << t << ": ";
    for (int i = 0; i < b; i++) {
        cout << v[i];
    }
    cout << endl;
    char ans;
    cin >> ans;
    if (ans == 'Y') return;
    else exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt >> b;
    for (int t = 1; t <= tt; t++) sherlock(t, b);
    return 0;
}