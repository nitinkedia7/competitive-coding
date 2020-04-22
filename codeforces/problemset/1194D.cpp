#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

void sherlock(int t) {
    int n, k;
    cin >> n >> k;
    if (k % 3 == 0) {
        n = n % (k + 1);
        if (n == k) {
            cout << "Alice" << endl;
        } 
        else if (n % 3 == 0) {
            cout << "Bob" << endl;
        } 
        else {
            cout << "Alice" << endl;
        }
    } 
    else {
        if (n % 3 == 0) {
            cout << "Bob" << endl;
        }
        else {
            cout << "Alice" << endl;
        }
    }
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