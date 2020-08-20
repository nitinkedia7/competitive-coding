#include "bits/stdc++.h"
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(0));
    cout << 1000 << endl;
    int n;
    for (int i = 0; i < 1000; i++) {
        n = 5;
        cout << n << endl;
        for (int i = 0; i < n; i++) {
            cout << rand() % 100 + 1 << " " << rand() % 100 + 1 << endl;
        }
    }    
    return 0;
}
