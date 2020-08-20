#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int get_mex(int n, vector<int> &v) { // O(n)
    vector<int> v_r(n + 1);
    for (int i = 0; i < n; i++) {
        v_r[v[i]] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (v_r[i] == 0) return i;
    }
    assert(false);
    // return -1;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> ans;
    while (1) {
        int mex = get_mex(n, v);
        if (mex < n) {
            ans.push_back(mex + 1);
            v[mex] = mex;
        }
        else {
            assert(mex == n);
            bool f = false;
            for (int i = 0; i < n; i++) {
                if (v[i] != i) {
                    ans.push_back(i + 1);
                    v[i] = mex;
                    f = true;
                    break;
                }
            }
            if (!f) break;
        }
        // print(v);
    }
    cout << ans.size() << endl;
    print(ans);
    // print(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
