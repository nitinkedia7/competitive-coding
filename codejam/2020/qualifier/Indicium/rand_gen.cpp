#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << 100 << endl;
    // for (int i = 2; i < 6; i++) {
    //     for (int j = i; j <= i * i; j++) {
    //         cout << i << " " << j << endl;
    //     } 
    // }
    int n;
    for (int t = 0; t < 100; t++) {
        n = rand() % 50 + 1;
        if (n < 2) n = 2;
        cout << n << " ";
        cout << n + rand() % (n * n - n) << endl;
    }
    return 0;
}