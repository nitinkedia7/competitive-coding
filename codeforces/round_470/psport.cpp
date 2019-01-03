#include <iostream>
#include <cmath>
using namespace std;

int max_prime(int x) {
    int mp = 2;
    while (x%2 == 0) {
        x = x/2;
    }
    for (int i = 3; i <= sqrt(x); i += 2) {
        while (x % i == 0) {
            mp = i;
            x = x/i;
        }
    }
    if (x > 2) mp = x;
    return mp;
}

int main() {
    int x2;
    cin >> x2;
    int p = max_prime(x2);
    // cout << p << endl;
    int  min = x2, new_min, q;
    for (int i = x2-p+1; i <= x2; i++) {
        q = max_prime(i);
        new_min = i-q+1;
        if (new_min < min && new_min >= 3) min = new_min;
    }
    cout << min << endl;
}
