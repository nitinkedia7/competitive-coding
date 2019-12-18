#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, temp;
    cin >> n;
    map<int,int, greater<int>> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp % 2 == 0) m[temp]++;
    }
    int c = 0;
    while (!m.empty()) {
        int x = m.begin()->first;
        int f = m.begin()->second;
        m.erase(m.begin());
        c++;
        x /= 2;
        if (x % 2 != 0) continue;
        if (m.find(x) != m.end()) {
            m[x] += f;
        }
        else m.insert({x, f});
    }
    cout << c << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) sherlock(t);
    return 0;
}