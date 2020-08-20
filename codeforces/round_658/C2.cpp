#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

char oppo(char x) {
    return (x == '0' ? '1' : '0');
}

char get(char x, int f) {
    f %= 2;
    if (f == 0) return x;
    return (x == '0' ? '1' : '0');
}

void sherlock(int t) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    // direction 0 : ->, 1 : <-
    vector<int> op;
    int left = 0, dir = 0;
    int flip = 0;
    for (int i = 0; i < n; i++) {
        int x = left;
        if (dir == 0) x += (n - i - 1);
        if (get(a[x], flip) == get(b[n - i - 1], 0)) {
            if (dir == 1) left++;
            continue;
        }
        int z = left;
        if (dir != 0) z += (n - i - 1);
        if (get(a[z], flip) == get(b[n - i - 1], 0)) {
            op.push_back(1);
            // a[z] = oppo(a[z]);
        }
        op.push_back(n - i);
        if (dir == 0) left++;
        dir = !dir;
        flip++;
    }
    cout << op.size() << " ";
    for (int i = 0; i < (int) op.size(); i++) {
        cout << op[i] << " ";
    } 
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
