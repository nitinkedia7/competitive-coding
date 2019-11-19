#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    cout << 1 << endl;
    int n;
    cin >> n;
    int s = rand() % n + 1;
    s /= 10;
    cout << n << " " <<  s << endl;
    int t;
    cin >> t;
    for (int i = 0; i < n; i++) {
        cout << rand() % t + 1 << " ";
    }
    cout << endl;
}