#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t, d;
    cin >> t;
    for (; t > 0; t--) {
        cin >> d;
        d = d%9;
        cout << d+1 << endl;
    }
}