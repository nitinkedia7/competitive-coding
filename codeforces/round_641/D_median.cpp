#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
const int N = 100000;

vector<int> v(N);

void print(vector<int> &v) {
    for (int i = 0; i < (int) v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

ll larger(int n, int k) {
    vector<int> x(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (v[i] < k) x[i+1] = -1;
        else x[i+1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        x[i] += x[i-1];
    }
    // print(x);
    vector<int> freq(2 * n + 1);
    freq[0 + n] = 1;
    ll ans = 0, prev = 0, cur;
    for (int i = 1; i <= n; i++) {
        if (x[i] > x[i-1]) {
            // x[i] = 1 + x[i-1];
            cur = prev + freq[x[i-1] + n];
        }
        else if (x[i] == x[i-1]) {
            cur = prev; 
        }
        else {
            // x[i] == x[i-1] - 1;
            cur = prev - freq[x[i] + n];
        }
        // cout << i << " " << cur << endl;
        freq[x[i] + n]++;
        ans += cur;
        prev = cur;
    } 
    return ans;
}

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    int k_c = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == k) k_c++;
    }
    if (k_c == 0) {
        cout << "no" << endl;
        return;
    }
    if (n == 1) {
        cout << "yes" << endl;
        return;
    }
    ll x = larger(n, k+1);
    ll y = larger(n, k);
    // x <= y
    cout << x << " " << y << endl;
    cout << (y - x - k_c == 0 ? "no" : "yes") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}
