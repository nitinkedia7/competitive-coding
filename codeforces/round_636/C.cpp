#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int sign(int x) {
    return x > 0;
}

void sherlock(int t) {
    int n;
    cin >> n;
    vector<int> v;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x != 0) v.push_back(x);
    }
    n = v.size();
    int i = 0;
    ll sum = 0;
    while (i < n) {
        int j = i;
        int x = v[i];
        while (j < n && sign(v[j]) == sign(v[i])) {
            x = max(x, v[j]);
            j++;
        }
        sum += x;
        i = j;
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}