#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

vector<char> v{'.', '#', '-', '|'};
void sherlock(int r, int c) {
    cout << r << " " << c << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << v[rand() % (int) v.size()];
        }
        cout << endl;
    }    
}

int main() {
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt, r, c;
    cin >> tt >> r >> c;
    cout << tt << endl;
    for (int t = 1; t <= tt; t++) sherlock(r, c);
    return 0;
}
