#include <bits/stdc++.h>
using namespace std;

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0; 
    }
    return 1;
}

int interest(int l, int r) {
    int count = 0;
    for (int x = l; x <= r; x++) {
        if (x % 16 == 0) {
            continue;
        }
        if (x % 8 == 0) {
            if (x / 8 == 1) {
                // cout << x << endl;
                count++;
            }
            continue;
        }
        if (x % 4 == 0) {
            if (x / 4  == 1 || isPrime(x / 4)) {
                // cout << x << endl;                
                count++;
            }
            continue;
        }
        if (x % 2 == 0) {
            // cout << x << endl;
            count++;
            continue;
        }
        if (x % 2 == 1) {
            if (x == 1 || isPrime(x)) {                
                // cout << x << endl;
                count++;
            }
            continue;
        }
    }    
    return count;
} 

int main() {
    int tt;
    cin >> tt;
    // preprocess sieve
    // vector<int> isPrime(1000001, 1);
    // isPrime[0] = 0;
    // isPrime[1] = 0;
    // int sum, jump;
    // for (int i = 2; i < 1000001; i++) {
    //     if (!isPrime[i]) continue;
    //     sum = 2 * i;
    //     jump = i;
    //     while (sum < 1000001) {
    //         isPrime[sum] = 0;
    //         sum += jump;
    //     }
    // }

    // for (int i = 0; i < 100; i++) {
    //     cout << i << "," << isPrime[i] << " ";
    // }
    // cout << endl;
    
    int l, r;
    for (int t = 1; t <= tt; t++) {
        cin >> l >> r;
        cout << "Case #" << t << ": " << interest(l, r) << endl;
    }
}