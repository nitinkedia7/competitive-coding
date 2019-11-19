#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void sherlock(int t) {
    int n, p;
    cin >> n >> p;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    ll sum = 0;
    for (int i = 0; i < p; i++) {
        sum += s[i];
    }
    ll mintr = p * 1LL * s[p-1] - sum;
    for (int i = 1; i < n - p + 1; i++) {
        sum -= s[i-1];
        sum += s[i + p - 1];
        mintr = min(mintr, p * 1LL * s[i + p - 1] - sum);
    }
    cout << "Case #" << t << ": " << mintr << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        sherlock(i);
    }
}