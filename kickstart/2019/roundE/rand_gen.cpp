#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0)); 
    int r;
    cout << 1 << endl;
    int d = 100000;
    int s = 100000;
    cout << d << " " << s << endl;
    int c, e, a, b;
    for (int i = 0; i < d; i++) {
        c = i % 93 ? rand() % 100 : 0;
        e = i % 53 ? rand() % 100 : 0;
        cout << c << " " << e << endl;
    }
    for (int i = 0; i < d; i++) {
        a = (rand() % 10000) * 10000;
        b = (rand() % 10000) * 10000;
        cout << a << " " << b << endl;
    }
}