#include <bits/stdc++.h>
using namespace std;

void sherlock(int a, int b, int c) {
    bool odd1 = a % 2, odd2 = b % 2, odd3 = c % 2;
    if (odd1 && odd2 && odd3) {
        cout << "YES" << endl;
        return;
    }
    if (odd1 && odd2 && !odd3) {
        cout << "NO" << endl;
        return;
    }
    if (odd1 && !odd2 && odd3) {
        if (b >= 2) {
            cout << "YES" << endl;
        }
        else if (a >= 3 && c >= 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return;
    }
    if (odd1 && !odd2 && !odd3) {
        cout << "NO" << endl;
        return;
    }
    if (!odd1 && odd2 && odd3) {
        cout << "NO" << endl;
        return;
    }
    if (!odd1 && odd2 && !odd3) {
        if (a >= 2) {
            cout << "YES" << endl;
        }
        else if (b >= 3 && c >= 2) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return;
    }
    if (!odd1 && !odd2 && odd3) {
        cout << "NO" << endl;
        return;
    }
    if (!odd1 && !odd2 && !odd3) {
        cout << "YES" << endl;
        return;
    }
}

int main() {
    int t;
    cin >> t;
    int a, b, c;
    while (t--) {
        cin >> a >> b >> c;
        sherlock(a, b, c);
    }
}