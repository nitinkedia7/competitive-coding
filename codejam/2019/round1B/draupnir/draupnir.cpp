#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

vector<ll> pow2;

ll query(int i) {
    cout << i << endl;
    ll res;
    cin >> res;
    if (res == -1) exit(0);
    return res;
}

void sherlock(int t, int w) {
    ll x56 = query(56);
    vector<ll> r(7);
    r[1] = x56 / pow2[56];
    x56 %= pow2[56];
    r[2] = x56 / pow2[28];
    x56 %= pow2[28];
    // r[3] is now polluted

    ll x210 = query(210);
    r[4] = x210 / pow2[52];
    x210 %= pow2[52];
    r[5] = x210 / pow2[42];
    x210 %= pow2[42];
    r[6] = x210 / pow2[35];
    
    ll y56 = 0;
    y56 += r[4] * pow2[14];
    y56 += r[5] * pow2[11];
    y56 += r[6] * pow2[9];

    for (int i = 0; i < 101; i++) {
        if (y56 + pow2[18] * i == x56) {
            r[3] = i;
            break;
        }
    }
    for (int i = 1; i < 7; i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return;
}

void populate() {
    ll x = 1;
    int i = 0;
    while (i < 64) {
        pow2.push_back(x);
        x *= 2;
        i++;
    }
    return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    populate();
    int tt, w;
    cin >> tt >> w;
    for (int t = 1; t <= tt; t++) sherlock(t, w);
    return 0;
}