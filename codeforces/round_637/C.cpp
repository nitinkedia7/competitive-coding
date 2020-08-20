#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n+1, -1);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v[x] = i;
    }
    int end = n;
    int i = 1;
    while (i <= n) {
        int f = end - v[i] - 1;
        if (f < 0) {
            cout << "No" << endl;
            return;
        }
        int j = i+1;
        while (f > 0) {
            // v[j] must be in v[i] + (j-i);
            if (v[j] != v[i] + (j-i)) {
                cout << "No" << endl;
                return;
            }
            j++;
            f--;
        }
        end = v[i];
        i = j;
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}