#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll diff_sum(ll x, ll y, ll z) {
    return (y - x) * (y - x) + (z - y) * (z - y) + (z - x) * (z - x);
}

ll solve(vector<ll> &A, vector<ll> &B, vector<ll> &C) {
    int i = 0, j = 0, k = 0;
    ll ans = LLONG_MAX;
    while (i < A.size()) {
        while (j < B.size() && B[j] < A[i]) {
            j++;
        } 
        if (j == B.size()) break;
        ll t = A[i] + B[j];
        while (k < C.size() && 2 * C[k] <= t) {
            k++;
        } 
        if (k - 1 >= 0 && C[k-1] >= A[i] && C[k-1] <= B[j]) {
            ans = min(ans, diff_sum(A[i], B[j], C[k-1]));
        }
        if (k < C.size() && C[k] >= A[i] && C[k] <= B[j]) {
            ans = min(ans, diff_sum(A[i], B[j], C[k]));
        }
        i++;
    }
    return ans;
}

void sherlock(int t) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<ll> A(a), B(b), C(c);
    for (int i = 0; i < a; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < c; i++) {
        cin >> C[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    ll ans = LLONG_MAX;
    ans = min(ans, solve(A, B, C));
    // cout << ans << endl;
    ans = min(ans, solve(A, C, B));
    // cout << ans << endl;
    ans = min(ans, solve(B, A, C));
    // cout << ans << endl;
    ans = min(ans, solve(B, C, A));
    // cout << ans << endl;
    ans = min(ans, solve(C, A, B));
    // cout << ans << endl;
    ans = min(ans, solve(C, B, A));
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}