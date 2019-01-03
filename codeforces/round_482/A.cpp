#include <iostream>
using namespace std;

int main() {
    unsigned long long int n;
    cin >> n;
    n += 1;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    unsigned long long int p = 1;
    if (n % 2 != 0) cout << n << endl;
    else {
        while (n % 2 != 0) {
            n = n/2;
            p = p*2;
        }
        cout << (p*(n))/2 << endl;
    }
    return 0;
}