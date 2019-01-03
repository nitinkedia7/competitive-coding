#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, r;
    cin >> t;
    for (; t > 0; t--) {
        int c = 0;
        cin >> l >> r;
        for (int i = 1; i < 31; i++) {
            for (int j = 1; j <= i; j++) {
                if (i%j != 0) continue; 
                int pc = 0;
                int base = pow(2, j), mul = 1;
                int s = i/j;
                if ((s-1) % 2 == 0) {
                    // lsb is 1
                    for (int k = 0; k < s; k++) {
                        if (k % 2 == 0) {
                            pc += (base-1)*mul;
                        }
                        mul *= base;
                    }
                }
                else {
                    // lsb is 0
                    for (int k = 0; k < s; k++) {
                        if (k % 2 == 1) {
                            pc += (base-1)*mul;
                        }
                        mul *= base;
                    }
                }
                if (pc >= l && pc <= r) c++;
            }
        }
        cout << c << endl;
    }
}