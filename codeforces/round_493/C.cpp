#include <iostream>
using namespace std;

int main() {
    int n;
    unsigned long long x, y;
    cin >> n >> x >> y;
    char s[n];
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    // string s;
    // cin >> s;
    // cout << s.length() << endl;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i == n-1) {
                a++;
            }
            else if (s[i+1] == '1') {
                a++;
            }
        }
        if (s[i] == '1') {
            if (i == n-1) {
                b++;
            }
            else if (s[i+1] == '0') {
                b++;
            }
        }
    }
    if (a == 0) {
        cout << 0 << endl;
        return 0;
    }
    unsigned long long min = 0, min1 = y;
    if (x > y) {
        min = a * y;
    }
    else {
        min = (a-1)*x;
        min += y;
    }
    if (x > y) {
        min1 += b*y;
    }
    else {
        min1 += (b-1)*x;
        min1 += y;
    }

    if (min < min1) cout << min << endl;
    else cout << min1 << endl;
    return 0;
}
