#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

bool nondecr(vector<int> &v) {
    bool nd = true;
    for (int i = 0; i < v.size()-1; i++) {
        nd = nd && v[i] <= v[i+1];
    }
    return nd;
} 

void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void all_nonneg(vector<int> &v) {
    int n = v.size();
    int x = 0;
    while (!nondecr(v)) {
        for (int i = 1; i < n-1; i++) {
            if ((v[i] & (1 << x)) == 0) {
                v[i] += (1 << x);
            }
        }
        v[n-1] += (1 << x);
        x++;
    }
    cout << x << endl;
}

void all_neg(vector<int> &v) {
    int n = v.size();
    int x = 0;
    while (!nondecr(v)) {
        for (int i = 1; i < n-1; i++) {
            if ((abs(v[i]) & (1 << x)) == (1 << x)) {
                v[i] += (1 << x);
            }
        }
        v[n-1] += (1 << x);
        x++;
        // print(v);
    }
    cout << x << endl;
}

void mix(vector<int> &v) {
    int n = v.size();
    int x = 0;
    while (!nondecr(v)) {
        int i;
        for (i = 0; i < n; i++) {
            if (v[i] >= 0 && (v[i] & (1 << x)) == (1 << x)) break;
        }
        // has power if i < n
        for (int j = 1; j < n - 1; j++) {
            if (j > i) {
                if (v[j] < 0 || (v[j] & (1 << x)) == 0) {
                    v[j] += (int) (1 << x);
                }
            }
            else if (v[j] < 0) {
                v[j] += (int) (1 << x);
            }
        }
        v[n-1] += (1 << x);
        x++;
    }
    cout << x << endl;
} 

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mi = *min_element(v.begin(), v.end());
    int ma = *max_element(v.begin(), v.end());
    if (mi >= 0) all_nonneg(v);
    else if ((ma < 0)) all_neg(v);
    else mix(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}