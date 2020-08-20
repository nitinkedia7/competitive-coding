#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

// bool digit(int l, int r, vector<int> &v) {
//     int x = *min_element(v.begin() + l, v.begin() + r + 1);
//     stack<int> sl, sr;
//     for (int i = r; i >= l; i--) sr.push(v[i]);
//     while (1) {
//         if (sr.size() == 1) return true;
//         int c = 0;
//         while (!sr.empty()) {
//             int y = sr.top();
//             sr.pop();
//             if (y != x) sl.push(y);
//             else {
//                 int nx = x;
//                 c++;
//                 if (!sl.empty() && sl.top() == x) {
//                     sl.pop();
//                     nx++;
//                     c -= 2;
//                 }
//                 sl.push(nx);
//             } 
//         }
//         // cout << x << " " << c << endl;
//         if (c != 0) return false;
//         while (!sl.empty()) {
//             sr.push(sl.top());
//             sl.pop();
//         }
//         x++;   
//     }
// } 

bool digit(int l, int r, vector<int> &v) {
    stack<int> s;
    for (int i = l; i <= r; i++) {
        int e = v[i];
        while (!s.empty() && s.top() == e) {
            s.pop();
            e++;
        } 
        s.push(e);
    }
    // cout << s.size() << endl;
    return s.size() == 1;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // digit(0, 3, v);
    // return;
    vector<vector<bool>> d(n, vector<bool> (n, false));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            d[i][j] = digit(i, j, v);
            // cout << d[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;
    vector<int> dp(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
        int ans = INT_MAX;
        for (int j = i+1; j <= n; j++) {
            if (d[i][j-1]) {
                ans = min(ans, 1 + dp[j]);
            }
        }
        dp[i] = ans;
    }
    cout << dp[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}