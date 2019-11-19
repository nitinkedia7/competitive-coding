#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007; 

void sherlock(int t) {
    vector<int> v(9);
    int n = 0;
    int sum = 0;
    vector<int> arr;
    for (int i = 0 ; i < 9; i++) {
        cin >> v[i];
        n += v[i];
        sum += (i + 1) * v[i];
        for (int j = 0; j < v[i]; j++) {
            arr.push_back(i + 1);
        }
    }
    // knapsack index, currentsum, allowedelem
    int h = n / 2;
    int opt[n + 1][sum + 1][h + 1];   
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            for (int k = 0; k <= h; k++) {
                opt[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        opt[i][0][0] = 1;
    }
    for (int k = 1; k <= h; k++) {
        // opt[n][0][k] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= sum; j++) {
                opt[i][j][k] = opt[i+1][j][k];
                if (j >= arr[i]) {
                    opt[i][j][k] |= opt[i+1][j - arr[i]][k-1];
                }
            }
        }
    }
    for (int j = 0; j <= sum; j++) {
        if (opt[0][j][h] == 1) {
            int lhs = j;
            int rhs = sum - j;
            if (lhs > rhs) {
                int temp = lhs;
                lhs =  rhs;
                rhs = temp;
            }
            if ((rhs - lhs) % 11 == 0) {
                cout << "Case #" << t << ": " << "YES" << endl;
                return;
            }
        }
    }
    cout << "Case #" << t << ": " << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        sherlock(t);
    }
}